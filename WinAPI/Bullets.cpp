#include "Stdafx.h"
#include "Bullets.h"

HRESULT Bullets::init(int bulletMax, float range)
{
	_range = range;

	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		// ZeroMemory vs memset 
		// ZeroMemory는 0으로 초기화, memset은 0이 아닌 값으로도 초기화가 가능
		ZeroMemory(&bullet, sizeof(tagBullet));

		bullet.img = new GImage;
		bullet.img->init("Resources/Images/ShootingGame/Missile.bmp", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));
		bullet.fire = false;
		bullet.speed = 5.0f;

		_vBullet.push_back(bullet);
	}

	return S_OK;
}

void Bullets::release(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		SAFE_DELETE(_vBulletIter->img);
	}

	_vBullet.clear();
}

void Bullets::update(void)
{
	move();
}

void Bullets::render(void)
{
	draw();
}

void Bullets::fire(float x, float y)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		if (_vBulletIter->fire) continue;

		_vBulletIter->fire = true;
		_vBulletIter->x = _vBulletIter->fireX = x;
		_vBulletIter->y = _vBulletIter->fireY = y;
		_vBulletIter->rc = RectMakeCenter(_vBulletIter->x, _vBulletIter->y,
			_vBulletIter->img->getFrameWidth(), _vBulletIter->img->getFrameHeight());

		break;
	}
}

void Bullets::draw(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		if (!_vBulletIter->fire) continue;

		_vBulletIter->img->frameRender(getMemDC(),
			_vBulletIter->rc.left, _vBulletIter->rc.top,
			_vBulletIter->img->getFrameX(), _vBulletIter->img->getFrameY());


		// 이미지 프레임 변경
		_vBulletIter->count++;

		if (_vBulletIter->count % 5 == 0)
		{
			_vBulletIter->img->setFrameX(_vBulletIter->img->getFrameX() + 1);

			if (_vBulletIter->img->getFrameX() >= _vBulletIter->img->getMaxFrameX())
			{
				_vBulletIter->img->setFrameX(0);
			}

			_vBulletIter->count = 0;
		}
	}
}

void Bullets::move(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		if (!_vBulletIter->fire) continue;

		// 불릿 좌표 변경
		_vBulletIter->y -= _vBulletIter->speed;
		_vBulletIter->rc = RectMakeCenter(_vBulletIter->x, _vBulletIter->y, _vBulletIter->img->getFrameWidth(), _vBulletIter->img->getFrameHeight());

		// 불릿 삭제 조건
		if (_range <= getDistance(_vBulletIter->fireX, _vBulletIter->fireY, _vBulletIter->x, _vBulletIter->y))
		{
			_vBulletIter->fire = false;
		}
	}
}

// ======================================================================================================

HRESULT Missile::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;

	return S_OK;
}

void Missile::release(void)
{
	// 1. 정석 (C++ 표본에서 얘기하는 문법)
	//for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	//{
	//	SAFE_DELETE(_vBulletIter->img);
	//}

	// 2. 줄이고 싶다. (변수에 의해서 길어지는 가독성 파괴)
	//_vBulletIter = _vBullet.begin();
	//for (; _vBulletIter != _vBullet.end(); ++_vBulletIter)
	//{
	//	SAFE_DELETE(_vBulletIter->img);
	//}

	// 3. 협업 시 효율적인건 뭐가 있을까?
	//iterBullet iterBullet = _vBullet.begin();

	//// 협업 X
	//auto iterBullet = _vBullet.begin();
	//for (; iterBullet != _vBullet.end(); iterBullet++)
	//{
	//	SAFE_DELETE(iterBullet->img);
	//}

	// 4. range based (Low 언어)
	//for (auto iter : _vBullet)
	//{
	//	SAFE_DELETE(iter.img);
	//}

	// 5. for each (High 언어)
	// 별도의 연산로직이 없을때는 사용 가능
	//for each (auto iter in _vBullet)
	//{
	//	SAFE_DELETE(iter.img);
	//}

	// 6. for_each
	// ㄴ 반복자의 시작과 끝, 그리고 함수를 파라미터로 받는다.
	// ㄴ 마지막 부분이 파라미터이기 때문에 람다식으로 표현이 가능
	//for_each(_vBullet.begin(), _vBullet.end(), update);

	//int Value = 0;
	//for_each(_vBullet.begin(), _vBullet.end(), [&Value](auto& number))
	//{
	//	Value += number;
	//});

	/*
	람다식
	- [] ( ) { } ( )
	ㄴ [캡처] (매개 변수) {(반환)함수 동작} (호출 인자(생략 가능))
	[] (int numA, int numB) { cout << numA + numB << endl; } (10, 20);
	[] (int numA, int numB) { return numA + numB; } (10, 20);

	==================================

	[] : 같은 영역에 있는 모든 변수에 접근 X
	[&] : 같은 영역에 있는 모든 변수를 참조 O
	[=] : 같은 영역에 있는 모든 변수를 값 O
	[&, 변수A] : 같은 영역에 있는 모든 변수를 참조로 캡처. 단, 변수A만 값으로 캡처
	[=, 변수A] : 같은 영역에 있는 모든 변수를 값으로 캡처. 단, 변수A만 참조로 캡처
	[&변수A] :

	*/

	//int numberA = 10;
	//int numberB = 20;

	//auto resultA = [](int NumA, NumB) {return NumA + NumB; } (10, 10);
	//auto resultB = [&]()->int {return numberA + numberB; } ();
	//auto resultC = [=, &numberA]()->int {return numberA + numberB; }();


	// 7. transform
	// ㄴ 반복자를 이용한 반복문이라고 할 수 있다. (결과를 다른 컨테이너에 저장)
	// ㄴ 원본 컨테이너도 가능 + 람다

	//vector<int> _vBulletReload;
	//transform(_vBullet.begin(), _vBullet.end(), _vBulletReload.begin(), update);

	//transform(_vBullet.begin(), _vBullet.end(), _vBulletReload.begin(),
	//	[](__int64 numA)-> auto { return numA; });


	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		SAFE_DELETE(_vBulletIter->img);
	}

	_vBullet.clear();
}

void Missile::update(void)
{
	move();
}

void Missile::render(void)
{
	draw();
}

void Missile::fire(float x, float y)
{
}

void Missile::draw(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		_vBulletIter->img->frameRender(getMemDC(),
			_vBulletIter->rc.left, _vBulletIter->rc.top,
			_vBulletIter->img->getFrameX(), _vBulletIter->img->getFrameY());

		// 이미지 프레임 변경
		_vBulletIter->count++;

		if (_vBulletIter->count % 5 == 0)
		{
			_vBulletIter->img->setFrameX(_vBulletIter->img->getFrameX() + 1);

			if (_vBulletIter->img->getFrameX() >= _vBulletIter->img->getMaxFrameX())
			{
				_vBulletIter = _vBullet.erase(_vBulletIter);
			}

			_vBulletIter->count = 0;
		}
	}
}

void Missile::move(void)
{
}
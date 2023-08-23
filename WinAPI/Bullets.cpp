#include "Stdafx.h"
#include "Bullets.h"

HRESULT Bullet::init(const char* imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void Bullet::release(void)
{
	_vBullet.clear();
}

void Bullet::update(void)
{
	move();
}

void Bullet::render(void)
{
	draw();
}

void Bullet::fire(float x, float y, float angle, float speed)
{
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getWidth(), bullet.img->getHeight());

	_vBullet.push_back(bullet);
}

void Bullet::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		// 불릿 좌표 변경
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y -= sinf(_viBullet->angle) * _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getWidth(), _viBullet->img->getHeight());

		// 불릿 삭제 조건
		if (_range <= MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void Bullet::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void Bullet::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
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
	//for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	//{
	//	SAFE_DELETE(_viBullet->img);
	//}

	// 2. 줄이고 싶다. (변수에 의해서 길어지는 가독성 파괴)
	//_viBullet = _vBullet.begin();
	//for (; _viBullet != _vBullet.end(); ++_viBullet)
	//{
	//	SAFE_DELETE(_viBullet->img);
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


	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
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
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new GImage;
	bullet.img->init("Resources/Images/ShootingGame/Missile.bmp", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void Missile::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		// 불릿 좌표 변경
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		// 불릿 삭제 조건
		if (_range <= MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y))
		{
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void Missile::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->img->getFrameX(), _viBullet->img->getFrameY());

		// 이미지 프레임 변경
		_viBullet->count++;

		if (_viBullet->count % 5 == 0)
		{
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}

			_viBullet->count = 0;
		}
	}
}

void Missile::removeBullet(int arrNum)
{
	SAFE_DELETE(_vBullet[arrNum].img);
	_vBullet.erase(_vBullet.begin() + arrNum);
}

// Beam =================================================================

HRESULT Beam::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;

	return S_OK;
}

void Beam::release(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		SAFE_DELETE(_viBullet->img);
	}

	_vBullet.clear();
}

void Beam::update(void)
{
	move();
}

void Beam::render(void)
{
	draw();
}

void Beam::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new GImage;
	bullet.img->init("Resources/Images/ShootingGame/Beam.bmp", 0.0f, 0.0f, 426, 801, 4, 1, true, RGB(255, 0, 255));
	bullet.speed = 0.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y - bullet.img->getFrameHeight() / 2, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void Beam::draw(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->img->frameRender(getMemDC(),
			_viBullet->rc.left, _viBullet->rc.top,
			_viBullet->img->getFrameX(), _viBullet->img->getFrameY());

		// 이미지 프레임 변경
		_viBullet->count++;

		if (_viBullet->count % 5 == 0)
		{
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);

			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX())
			{
				_viBullet->img->setFrameX(0);
			}

			_viBullet->count = 0;
		}
	}
}

void Beam::move(void)
{
	//for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	//{
	//	// 불릿 좌표 변경
	//	_viBullet->y -= _viBullet->speed;
	//	_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

	//	// 불릿 삭제 조건
	//	if (_range <= MY_UTIL::getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y))
	//	{
	//		SAFE_DELETE(_viBullet->img);
	//		_viBullet = _vBullet.erase(_viBullet);
	//	}
	//	else ++_viBullet;
	//}
}

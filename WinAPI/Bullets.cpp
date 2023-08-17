#include "Stdafx.h"
#include "Bullets.h"

HRESULT Bullets::init(int bulletMax, float range)
{
	_range = range;

	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		// ZeroMemory vs memset 
		// ZeroMemory�� 0���� �ʱ�ȭ, memset�� 0�� �ƴ� �����ε� �ʱ�ȭ�� ����
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


		// �̹��� ������ ����
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

		// �Ҹ� ��ǥ ����
		_vBulletIter->y -= _vBulletIter->speed;
		_vBulletIter->rc = RectMakeCenter(_vBulletIter->x, _vBulletIter->y, _vBulletIter->img->getFrameWidth(), _vBulletIter->img->getFrameHeight());

		// �Ҹ� ���� ����
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
	// 1. ���� (C++ ǥ������ ����ϴ� ����)
	//for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	//{
	//	SAFE_DELETE(_vBulletIter->img);
	//}

	// 2. ���̰� �ʹ�. (������ ���ؼ� ������� ������ �ı�)
	//_vBulletIter = _vBullet.begin();
	//for (; _vBulletIter != _vBullet.end(); ++_vBulletIter)
	//{
	//	SAFE_DELETE(_vBulletIter->img);
	//}

	// 3. ���� �� ȿ�����ΰ� ���� ������?
	//iterBullet iterBullet = _vBullet.begin();

	//// ���� X
	//auto iterBullet = _vBullet.begin();
	//for (; iterBullet != _vBullet.end(); iterBullet++)
	//{
	//	SAFE_DELETE(iterBullet->img);
	//}

	// 4. range based (Low ���)
	//for (auto iter : _vBullet)
	//{
	//	SAFE_DELETE(iter.img);
	//}

	// 5. for each (High ���)
	// ������ ��������� �������� ��� ����
	//for each (auto iter in _vBullet)
	//{
	//	SAFE_DELETE(iter.img);
	//}

	// 6. for_each
	// �� �ݺ����� ���۰� ��, �׸��� �Լ��� �Ķ���ͷ� �޴´�.
	// �� ������ �κ��� �Ķ�����̱� ������ ���ٽ����� ǥ���� ����
	//for_each(_vBullet.begin(), _vBullet.end(), update);

	//int Value = 0;
	//for_each(_vBullet.begin(), _vBullet.end(), [&Value](auto& number))
	//{
	//	Value += number;
	//});

	/*
	���ٽ�
	- [] ( ) { } ( )
	�� [ĸó] (�Ű� ����) {(��ȯ)�Լ� ����} (ȣ�� ����(���� ����))
	[] (int numA, int numB) { cout << numA + numB << endl; } (10, 20);
	[] (int numA, int numB) { return numA + numB; } (10, 20);

	==================================

	[] : ���� ������ �ִ� ��� ������ ���� X
	[&] : ���� ������ �ִ� ��� ������ ���� O
	[=] : ���� ������ �ִ� ��� ������ �� O
	[&, ����A] : ���� ������ �ִ� ��� ������ ������ ĸó. ��, ����A�� ������ ĸó
	[=, ����A] : ���� ������ �ִ� ��� ������ ������ ĸó. ��, ����A�� ������ ĸó
	[&����A] :

	*/

	//int numberA = 10;
	//int numberB = 20;

	//auto resultA = [](int NumA, NumB) {return NumA + NumB; } (10, 10);
	//auto resultB = [&]()->int {return numberA + numberB; } ();
	//auto resultC = [=, &numberA]()->int {return numberA + numberB; }();


	// 7. transform
	// �� �ݺ��ڸ� �̿��� �ݺ����̶�� �� �� �ִ�. (����� �ٸ� �����̳ʿ� ����)
	// �� ���� �����̳ʵ� ���� + ����

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

		// �̹��� ������ ����
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
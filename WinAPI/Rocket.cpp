#include "Stdafx.h"
#include "Rocket.h"
#include "NormalMissile.h"
#include "ShotMissile.h"
#include "MiniRocket.h"

// 설계와의 싸움
HRESULT Rocket::init()
{
	// 객체의 의한 매니저할당
	_image = IMAGEMANAGER->addImage("로켓", "Resources/Images/ShootingGame/Rocket.bmp", 52, 64, true, RGB(255, 0, 255));

	_x = WINSIZE_X_HALF;
	_y = WINSIZE_Y_HALF;

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

	_flame = new Flame;
	_flame->init("Flame.bmp", & _x, &_y);

	// 미사일 셋팅
	setBullet();
	_curBulletType = NORMAL_BULLET;

	//std::shared_ptr<Rocket> PlayerA = std::make_shared<Rocket>();
	//std::shared_ptr<Rocket> PlayerB = PlayerA->get_shared_ptr();

	//PlayerA.use_count();

	// 좀 더 효율적인 방법
	//spRocket.push_back(std::shared_ptr<Rocket>(new Rocket));

	return S_OK;
}

void Rocket::release(void)
{
	_flame->release();
	SAFE_DELETE(_flame);

	for (int i = 0; i < BULLET_END; i++)
	{
		_bullets[i]->release();
		SAFE_DELETE(_bullets[i]);
	}
}

void Rocket::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left > 0)
	{
		_x -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X)
	{
		_x += ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top > 0)
	{
		_y -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom < WINSIZE_Y)
	{
		_y += ROCKET_SPEED;
	}

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_curBulletType--;

		if (_curBulletType < 0)
		{
			_curBulletType = BULLET_END - 1;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		_curBulletType++;

		if (_curBulletType == BULLET_END)
		{
			_curBulletType = 0;
		}
	}

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		// fire
		_bullets[_curBulletType]->fire(_x, _y - 60);
	}

	_flame->update();

	for (int i = 0; i < BULLET_END; i++)
	{
		_bullets[i]->update();
	}
}

void Rocket::render(void)
{
	_image->render(getMemDC(), _rc.left, _rc.top);
	_flame->render();

	for (int i = 0; i < BULLET_END; i++)
	{
		_bullets[i]->render();
	}

	string strBulletType = "무기 타입 : " + _bullets[_curBulletType]->getName();
	TextOut(getMemDC(), WINSIZE_X - 200, WINSIZE_Y - 50, strBulletType.c_str(), strBulletType.length());
}

void Rocket::setBullet(void)
{
	Missile* normalBullet = new NormalMissile;
	normalBullet->init(30, 500);
	_bullets[NORMAL_BULLET] = normalBullet;

	Missile* shotBullet = new ShotMissile;
	shotBullet->init(100, WINSIZE_Y);
	_bullets[SHOT] = shotBullet;

	Missile* miniRocket = new MiniRocket;
	miniRocket->init(3, 300);
	_bullets[MINI_ROCKET] = miniRocket;
}

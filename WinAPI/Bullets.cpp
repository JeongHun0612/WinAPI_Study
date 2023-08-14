#include "Stdafx.h"
#include "Bullets.h"

HRESULT Missile::init(int bulletMax, float range)
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

void Missile::release(void)
{
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

void Missile::draw(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		if (!_vBulletIter->fire) continue;

		_vBulletIter->img->frameRender(getMemDC(),
			_vBulletIter->rc.left , _vBulletIter->rc.top,
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

void Missile::move(void)
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

// ===============================================================================

HRESULT MissileM1::init(int bulletMax, float range)
{
	_range = range;
	_bulletMax = bulletMax;

	return S_OK;
}

void MissileM1::release(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		SAFE_DELETE(_vBulletIter->img);
	}

	_vBullet.clear();
}

void MissileM1::update(void)
{
	move();
}

void MissileM1::render(void)
{
	draw();
}

void MissileM1::fire(float x, float y)
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

void MissileM1::draw(void)
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
				_vBulletIter->img->setFrameX(0);
			}

			_vBulletIter->count = 0;
		}
	}
}

void MissileM1::move(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end();)
	{
		// 불릿 좌표 변경
		_vBulletIter->y -= _vBulletIter->speed;
		_vBulletIter->rc = RectMakeCenter(_vBulletIter->x, _vBulletIter->y, _vBulletIter->img->getFrameWidth(), _vBulletIter->img->getFrameHeight());

		// 불릿 삭제 조건
		if (_range <= MY_UTIL::getDistance(_vBulletIter->fireX, _vBulletIter->fireY, _vBulletIter->x, _vBulletIter->y))
		{
			SAFE_DELETE(_vBulletIter->img);
			_vBulletIter = _vBullet.erase(_vBulletIter);
		}
		else ++_vBulletIter;
	}
}

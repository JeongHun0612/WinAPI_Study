#include "Stdafx.h"
#include "MiniRocket.h"

HRESULT MiniRocket::init(int bulletMax, float range)
{
    Missile::init(bulletMax, range);

    _name = "미니 로켓";

    return S_OK;
}

void MiniRocket::release(void)
{
}

void MiniRocket::update(void)
{
	move();
}

void MiniRocket::render(void)
{
	draw();
}

void MiniRocket::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new GImage;
	bullet.img->init("Resources/Images/ShootingGame/Missile.bmp", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));
	bullet.effectImg = new GImage;
	bullet.effectImg->init("Resources/Images/ShootingGame/effect_explosion.bmp", 0.0f, 0.0f, 1152, 144, 8, 1, true, RGB(255, 0, 255));
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void MiniRocket::draw(void)
{
	Missile::draw();
}

void MiniRocket::move(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end();)
	{
		if (!_vBulletIter->explosion)
		{
			// 불릿 좌표 변경
			_vBulletIter->y -= _vBulletIter->speed;

			if (_range <= MY_UTIL::getDistance(_vBulletIter->fireX, _vBulletIter->fireY, _vBulletIter->x, _vBulletIter->y))
			{
				_vBulletIter->explosion = true;
				_vBulletIter->img = _vBulletIter->effectImg;
			}

			_vBulletIter->rc = RectMakeCenter(_vBulletIter->x, _vBulletIter->y, _vBulletIter->img->getFrameWidth(), _vBulletIter->img->getFrameHeight());
			++_vBulletIter;
		}
		else
		{
			if (_vBulletIter->img->getFrameX() == _vBulletIter->img->getMaxFrameX() - 1)
			{
				SAFE_DELETE(_vBulletIter->img);
				_vBulletIter = _vBullet.erase(_vBulletIter);
			}
			else ++_vBulletIter;
		}
	}
}

#include "Stdafx.h"
#include "ShotMissile.h"

HRESULT ShotMissile::init(int bulletMax, float range)
{
	Missile::init(bulletMax, range);

	_name = "ªÍ≈∫";

	return S_OK;
}

void ShotMissile::release(void)
{
}

void ShotMissile::update(void)
{
	move();
}

void ShotMissile::render(void)
{
	draw();
}

void ShotMissile::fire(float x, float y)
{
	if (_bulletMax <= _vBullet.size()) return;

	for (int i = 0; i < 3; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));

		bullet.img = new GImage;
		bullet.img->init("Resources/Images/ShootingGame/Missile.bmp", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));
		bullet.speed = 5.0f;
		bullet.angle = 225 + (i * 45);
		bullet.x = bullet.fireX = x;
		bullet.y = bullet.fireY = y;
		bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

		_vBullet.push_back(bullet);
	}
}

void ShotMissile::draw(void)
{
	Missile::draw();
}

void ShotMissile::move(void)
{
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end();)
	{
		// ∫“∏¥ ¡¬«• ∫Ø∞Ê
		_vBulletIter->x += cosf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->speed;
		_vBulletIter->y += sinf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->speed;

		_vBulletIter->rc = RectMakeCenter(_vBulletIter->x, _vBulletIter->y, _vBulletIter->img->getFrameWidth(), _vBulletIter->img->getFrameHeight());

		// ∫“∏¥ ªË¡¶ ¡∂∞«
		if (_range <= MY_UTIL::getDistance(_vBulletIter->fireX, _vBulletIter->fireY, _vBulletIter->x, _vBulletIter->y))
		{
			SAFE_DELETE(_vBulletIter->img);
			_vBulletIter = _vBullet.erase(_vBulletIter);
		}
		else ++_vBulletIter;
	}
}

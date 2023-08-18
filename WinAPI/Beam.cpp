#include "Stdafx.h"
#include "Beam.h"

HRESULT Beam::init(int bulletMax, float range)
{
	Missile::init(bulletMax, range);

	_bulletType = BULLET_TYPE::BEAM;
	_name = "레이저";

	return S_OK;
}

void Beam::release(void)
{
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

void Beam::move(void)
{
	//for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end();)
	//{
	//	// 불릿 좌표 변경
	//	_vBulletIter->y -= _vBulletIter->speed;
	//	_vBulletIter->rc = RectMakeCenter(_vBulletIter->x, _vBulletIter->y, _vBulletIter->img->getFrameWidth(), _vBulletIter->img->getFrameHeight());

	//	// 불릿 삭제 조건
	//	if (_range <= MY_UTIL::getDistance(_vBulletIter->fireX, _vBulletIter->fireY, _vBulletIter->x, _vBulletIter->y))
	//	{
	//		SAFE_DELETE(_vBulletIter->img);
	//		_vBulletIter = _vBullet.erase(_vBulletIter);
	//	}
	//	else ++_vBulletIter;
	//}
}

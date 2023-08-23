#include "Stdafx.h"
#include "Enemy.h"

Enemy::Enemy(void) : _rc(RectMake(0, 0, 0, 0)),
_currentFrameX(0),
_currentFrameY(0),
_x(0.0f),
_y(0.0f),
_speed(0.0f),
_angle(0.0f),
_worldTimeCount(0.0f),
_rndTimeCount(0.0f),
_rndFirecount(0.0f),
_bulletFireCount(0.0f)
{}

HRESULT Enemy::init(void)
{
	// ! Do Nothing;

	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position, float speed, float angle)
{
	_missile = new Missile;
	_missile->init(30, 600);

	_worldTimeCount = GetTickCount();
	_rndTimeCount = RND->getFromFloatTo(50, 150);

	_bulletFireCount = TIMEMANAGER->getWorldTime();
	_rndFirecount = RND->getFromFloatTo(0.5f, 4.5f);

	_image = IMAGEMANAGER->findImage(imageName);

	_maxHP = 3;
	_curHP = _maxHP;

	_x = position.x;
	_y = position.y;

	_speed = speed;
	_angle = angle;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

void Enemy::release(void)
{
	// ! Do Nothing;
}

void Enemy::update(void)
{
	move();

	_missile->update();
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
}

void Enemy::render(void)
{
	draw();
	animation();

	_missile->render();
}

// X : 적마다 움직임이 다르다. -> 상속을 전제한 클래스이기 때문에 -> 자식 구현
void Enemy::move(void)
{
}

void Enemy::draw(void)
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);

	switch (_curHP)
	{
	case 1:
		_hBrush = CreateSolidBrush(RGB(255, 0, 0));
		break;
	case 2:
		_hBrush = CreateSolidBrush(RGB(255, 255, 0));
		break;
	case 3:
		_hBrush = CreateSolidBrush(RGB(0, 255, 0));
		break;
	}

	_hOldBrush = (HBRUSH)SelectObject(getMemDC(), _hBrush);

	RectangleMake(getMemDC(),
		_rc.left, _rc.top - 10,
		(_image->getFrameWidth() / _maxHP) * _curHP, 10);

	SelectObject(getMemDC(), _hOldBrush);
	DeleteObject(_hBrush);
}

void Enemy::animation(void)
{
	if (_rndTimeCount + _worldTimeCount <= GetTickCount())
	{
		_worldTimeCount = GetTickCount();
		_currentFrameX++;

		if (_currentFrameX == _image->getMaxFrameX())
		{
			_currentFrameX = 0;
		}
	}
}

bool Enemy::bulletCountFire(void)
{
	if (_rndFirecount + _bulletFireCount <= TIMEMANAGER->getWorldTime())
	{
		_bulletFireCount = TIMEMANAGER->getWorldTime();
		_rndFirecount = RND->getFromFloatTo(2.0f, 6.0f);

		return true;
	}

	return false;
}

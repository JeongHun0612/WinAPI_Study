#include "Stdafx.h"
#include "Report_15_3_MainGame.h"

/*
과제 3. 발사된 총알끼리 충돌 (역삼각 함수)

- 핵심 요소는 총알끼리 충돌이 되면 자연스럽게 팅겨 나가야 한다.
*/

HRESULT Report_15_3_MainGame::init(void)
{
	GameNode::init();

	_radius = 50;
	_currentAngle = -90;
	_move = 1;
	_bIsAuto = true;

	return S_OK;
}

void Report_15_3_MainGame::release(void)
{
	GameNode::release();
}

void Report_15_3_MainGame::update(void)
{
	GameNode::update();

	// 포신 이동
	if (!_bIsAuto)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _currentAngle > -170)
		{
			_currentAngle -= 1;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _currentAngle < -10)
		{
			_currentAngle += 1;
		}
	}
	else
	{
		if (_currentAngle < -170 || _currentAngle > -10)
		{
			_move = -_move;
		}

		_currentAngle += _move;
	}

	// 자동 / 수동
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_bIsAuto = !_bIsAuto;
	}


	// 총알 발사
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		tagBullet bullet;

		bullet.rc = RectMakeCenter(
			WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
			WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
			30, 30);
		bullet._angle = _currentAngle;
		bullet._moveX = 1;
		bullet._moveY = 1;
		bullet._speed = 5.0f;

		_vBullet.push_back(bullet);
	}

	// 총알 이동
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		_vBulletIter->rc.left += cosf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_moveX * _vBulletIter->_speed;
		_vBulletIter->rc.right += cosf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_moveX * _vBulletIter->_speed;

		_vBulletIter->rc.top += sinf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_moveY * _vBulletIter->_speed;
		_vBulletIter->rc.bottom += sinf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_moveY * _vBulletIter->_speed;


		if (_vBulletIter->rc.right >= WINSIZE_X || _vBulletIter->rc.left <= 0)
		{
			_vBulletIter->_moveX = -_vBulletIter->_moveX;
		}
		if (_vBulletIter->rc.bottom >= WINSIZE_Y || _vBulletIter->rc.top <= 0)
		{
			_vBulletIter->_moveY = -_vBulletIter->_moveY;
		}
	}
}

void Report_15_3_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==========================================================

	EllipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y, _radius);

	LineMake(
		memDC,
		WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * _radius,
		WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * _radius,
		WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
		WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30)
	);

	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		Ellipse(memDC, _vBulletIter->rc.left, _vBulletIter->rc.top, _vBulletIter->rc.right, _vBulletIter->rc.bottom);
	}

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

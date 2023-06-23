#include "Stdafx.h"
#include "Report_15_2_MainGame.h"

/*
과제 2. 포신 각도에 따른 총알 발사

- 예외 처리 : 포신 앵글을 막아준다. -> 화면 밖으로

- 필수 : 수동 / 자동 버전 -> 총 2가지로
*/

HRESULT Report_15_2_MainGame::init(void)
{
	GameNode::init();

	_radius = 50;
	_currentAngle = -90;

	return S_OK;
}

void Report_15_2_MainGame::release(void)
{
	GameNode::release();
}

void Report_15_2_MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _currentAngle > -170)
	{
		_currentAngle -= 1;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _currentAngle < -10)
	{
		_currentAngle += 1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		tagBullet bullet;

		bullet.rc = RectMakeCenter(
			WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
			WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
			20, 20);
		bullet._angle = _currentAngle;
		bullet._speed = 5.0f;

		_vBullet.push_back(bullet);
	}

	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		_vBulletIter->rc.left += cosf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_speed;
		_vBulletIter->rc.right += cosf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_speed;
		_vBulletIter->rc.top += sinf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_speed;
		_vBulletIter->rc.bottom += sinf(DEGREE_RADIAN(_vBulletIter->_angle)) * _vBulletIter->_speed;

		//if (_vBulletIter->rc.top <= 0)
		//{
		//	_vBulletIter->_angle = -_vBulletIter->_angle;
		//}

		//if (_vBulletIter->rc.top <= 0)
		//{
		//	_vBulletIter->_angle *= -1;
		//}

		//if (_vBulletIter->rc.bottom >= WINSIZE_Y)
		//{
		//	_vBulletIter->_angle *= -1;
		//}

		if (_vBulletIter->rc.right >= WINSIZE_X)
		{
			_vBulletIter->rc.left += cosf(DEGREE_RADIAN(_vBulletIter->_angle - 180)) * _vBulletIter->_speed;
			_vBulletIter->rc.right += cosf(DEGREE_RADIAN(_vBulletIter->_angle - 180)) * _vBulletIter->_speed;
		
		}
	}
}

void Report_15_2_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==========================================================

	ElipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y, _radius);

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

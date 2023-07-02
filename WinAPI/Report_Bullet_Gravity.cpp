#include "Stdafx.h"
#include "Report_Bullet_Gravity.h"

/*
���� 4. �߻��� �Ѿ˿� �߷� ����

- �Ѿ��� �߷��� �޾� ��������. -> ���� ���ϸ�
*/

HRESULT Report_Bullet_Gravity::init(void)
{
	_radius = 50;
	_currentAngle = -90;
	_move = 1;
	_bIsAuto = true;

	return S_OK;
}

void Report_Bullet_Gravity::release(void)
{
}

void Report_Bullet_Gravity::update(void)
{
	// ���� �̵�
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

	// �ڵ� / ����
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_bIsAuto = !_bIsAuto;
	}


	// �Ѿ� �߻�
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		tagBullet bullet;

		bullet.centerX = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30);
		bullet.centerY = WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30);

		bullet.radius = 15;
		bullet.angle = _currentAngle;
		bullet.moveX = 1;
		bullet.moveY = 1;
		bullet.speed = 10.0f;

		bullet.rc = RectMakeCenter(bullet.centerX, bullet.centerY, bullet.radius * 2, bullet.radius * 2);

		_vBullet.push_back(bullet);
	}

	// �Ѿ� �̵�
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		_vBulletIter->centerX += cosf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveX * 10.0f;
		_vBulletIter->centerY += sinf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveY * _vBulletIter->speed;

		_vBulletIter->speed -= 0.15f;
	}

	// ������ �Ѿ� ����
	for (int i = 0; i < _vBullet.size(); i++)
	{
		if (_vBullet[i].centerY >= WINSIZE_Y + 100)
		{
			_vBullet.erase(_vBullet.begin() + i);
		}
	}
}

void Report_Bullet_Gravity::render(void)
{
	EllipseMakeCenter(getMemDC(), WINSIZE_X / 2, WINSIZE_Y, _radius);

	LineMake(
		getMemDC(),
		WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * _radius,
		WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * _radius,
		WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
		WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30)
	);

	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		EllipseMakeCenter(getMemDC(), _vBulletIter->centerX, _vBulletIter->centerY, _vBulletIter->radius);
	}
}
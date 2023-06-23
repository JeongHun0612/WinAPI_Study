#include "Stdafx.h"
#include "Report_15_2_MainGame.h"

/*
���� 2. ���� ������ ���� �Ѿ� �߻�

- ���� ó�� : ���� �ޱ��� �����ش�. -> ȭ�� ������

- �ʼ� : ���� / �ڵ� ���� -> �� 2������

���� 3. �߻�� �Ѿ˳��� �浹 (���ﰢ �Լ�)

- �ٽ� ��Ҵ� �Ѿ˳��� �浹�� �Ǹ� �ڿ������� �ð� ������ �Ѵ�.
*/

HRESULT Report_15_2_MainGame::init(void)
{
	GameNode::init();

	_radius = 50;
	_currentAngle = -90;
	_move = 1;
	_bIsAuto = true;

	return S_OK;
}

void Report_15_2_MainGame::release(void)
{
	GameNode::release();
}

void Report_15_2_MainGame::update(void)
{
	GameNode::update();

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
		bullet.speed = 5.0f;

		bullet.rc = RectMakeCenter(bullet.centerX, bullet.centerY, 30, 30);

		_vBullet.push_back(bullet);
	}

	// �Ѿ� �̵�
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		_vBulletIter->centerX += cosf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveX * _vBulletIter->speed;
		_vBulletIter->centerY += sinf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveY * _vBulletIter->speed;

		_vBulletIter->rc = RectMakeCenter(_vBulletIter->centerX, _vBulletIter->centerY, 30, 30);

		if (_vBulletIter->rc.left <= 0 || _vBulletIter->rc.right >= WINSIZE_X)
		{
			_vBulletIter->moveX = -_vBulletIter->moveX;

		}
		if (_vBulletIter->rc.top <= 0 || _vBulletIter->rc.bottom >= WINSIZE_Y)
		{
			_vBulletIter->moveY = -_vBulletIter->moveY;
		}

		
	}

	// �Ѿ� ���� �浹
	//for (int i = 0; i < _vBullet.size(); i++)
	//{
	//	for (int j = 0; j < _vBullet.size(); j++)
	//	{
	//		if (i == j) continue;

	//		//sqrt((x2 - x1)�� + (y2 - y1)��) - �� �� ������ �Ÿ�
	//		if (sqrt(pow(_vBullet[i].centerX - _vBullet[j].centerX, 2) + pow(_vBullet[i].centerY - _vBullet[j].centerY, 2)) <= 30)
	//		{
	//			_vBullet[i].moveX = -_vBullet[i].moveX;
	//			_vBullet[i].moveY = -_vBullet[i].moveY;
	//		}
	//	}
	//}
}

void Report_15_2_MainGame::render(HDC hdc)
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
		EllipseMakeCenter(memDC, _vBulletIter->centerX, _vBulletIter->centerY, _vBulletIter->radius);
	}

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

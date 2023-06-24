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
		bullet.diameter = bullet.radius * 2;
		bullet.angle = _currentAngle;
		bullet.moveX = 1;
		bullet.moveY = 1;
		bullet.speed = 5.0f;

		bullet.rc = RectMakeCenter(bullet.centerX, bullet.centerY, bullet.radius * 2, bullet.radius * 2);

		_vBullet.push_back(bullet);
	}

	// �Ѿ� �̵�
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		_vBulletIter->centerX += cosf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveX * _vBulletIter->speed;
		_vBulletIter->centerY += sinf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveY * _vBulletIter->speed;

		_vBulletIter->rc = RectMakeCenter(_vBulletIter->centerX, _vBulletIter->centerY, _vBulletIter->radius * 2, _vBulletIter->radius * 2);

		// �� �浹
		if (_vBulletIter->rc.left <= 0)
		{
			_vBulletIter->centerX += -_vBulletIter->rc.left;
			_vBulletIter->rc.left = 0;
			_vBulletIter->moveX = -_vBulletIter->moveX;

		}
		if (_vBulletIter->rc.right >= WINSIZE_X)
		{
			_vBulletIter->centerX -= _vBulletIter->rc.right - WINSIZE_X;
			_vBulletIter->rc.right = WINSIZE_X;
			_vBulletIter->moveX = -_vBulletIter->moveX;
		}
		if (_vBulletIter->rc.top <= 0)
		{
			_vBulletIter->centerY += -_vBulletIter->rc.top;
			_vBulletIter->rc.top = 0;
			_vBulletIter->moveY = -_vBulletIter->moveY;
		}
		if (_vBulletIter->rc.bottom >= WINSIZE_Y)
		{
			_vBulletIter->centerY -= _vBulletIter->rc.bottom - WINSIZE_Y;
			_vBulletIter->rc.bottom = WINSIZE_Y;
			_vBulletIter->moveY = -_vBulletIter->moveY;
		}
	}

	//�Ѿ� ���� �浹
	for (int i = 0; i < _vBullet.size(); i++)
	{
		for (int j = 0; j < _vBullet.size(); j++)
		{
			if (i == j) continue;

			//sqrt((x2 - x1)�� + (y2 - y1)��) - �� �� ������ �Ÿ�
			float distance = sqrt(pow(_vBullet[i].centerX - _vBullet[j].centerX, 2) + pow(_vBullet[i].centerY - _vBullet[j].centerY, 2));

			if (distance <= _vBullet[i].diameter)
			{
				_vBullet[i].moveX = -_vBullet[i].moveX;
				_vBullet[i].moveY = -_vBullet[i].moveY;

				_vBullet[i].centerX += sqrt(pow(_vBullet[i].diameter - distance, 2) / 2.0f) * _vBullet[i].moveX;
				_vBullet[i].centerY += sqrt(pow(_vBullet[i].diameter - distance, 2) / 2.0f) * _vBullet[i].moveY;

				//_vBullet[i].centerX += (_vBullet[i].diameter - distance) * _vBullet[i].moveX;
				//_vBullet[i].centerY += (_vBullet[i].diameter - distance) * _vBullet[i].moveY;

				//_vBullet[j].centerX += (_vBullet[j].diameter - distance) * _vBullet[j].moveX;
				//_vBullet[j].centerY += (_vBullet[j].diameter - distance) * _vBullet[j].moveY;


 				//_vBullet[i].centerX += (450.0f - pow(abs(_vBullet[i].centerX) - abs(_vBullet[j].centerX), 2)) * _vBullet[i].moveX;
				//_vBullet[i].centerY += (450.0f - pow(abs(_vBullet[i].centerY) - abs(_vBullet[j].centerY), 2)) * _vBullet[i].moveY;

				//_vBullet[i].centerX += (_vBullet[i].diameter - abs(_vBullet[i].centerX - _vBullet[j].centerX)) * _vBullet[i].moveX;
				//_vBullet[i].centerY += (_vBullet[i].diameter - abs(_vBullet[i].centerY - _vBullet[j].centerY)) * _vBullet[i].moveY;

				//_vBullet[j].centerX += (_vBullet[i].diameter - abs(_vBullet[i].centerX - _vBullet[j].centerX)) * _vBullet[j].moveX;
				//_vBullet[j].centerY += (_vBullet[i].diameter - abs(_vBullet[i].centerY - _vBullet[j].centerY)) * _vBullet[j].moveY;


				//_vBullet[j].moveX = -_vBullet[j].moveX;
				//_vBullet[j].moveY = -_vBullet[j].moveY;
			}
		}
	}
}

void Report_15_2_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==========================================================

	LineMake(memDC,
		WINSIZE_X / 2,
		WINSIZE_Y,
		WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
		WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30)
	);

	EllipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y, _radius);

	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		EllipseMakeCenter(memDC, _vBulletIter->centerX, _vBulletIter->centerY, _vBulletIter->radius);
	}

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

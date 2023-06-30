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
	_radius = 50;
	_currentAngle = 270;
	_move = 1;
	_bIsAuto = true;

	return S_OK;
}

void Report_15_2_MainGame::release(void)
{
}

void Report_15_2_MainGame::update(void)
{

	// ���� �̵�
	if (!_bIsAuto)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _currentAngle > 190)
		{
			_currentAngle -= 1;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _currentAngle < 350)
		{
			_currentAngle += 1;
		}
	}
	else
	{
		if (_currentAngle == 190 || _currentAngle == 350)
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

		bullet.radius = 30;
		bullet.diameter = bullet.radius * 2;
		bullet.angle = _currentAngle;
		bullet.moveX = 1;
		bullet.moveY = 1;

		bullet.centerX = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30);
		bullet.centerY = WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30);
		bullet.tempX = 0.0f;
		bullet.tempY = WINSIZE_Y - bullet.radius;
		bullet.speed = 5.0f;

		bullet.rc = RectMakeCenter(bullet.centerX, bullet.centerY, bullet.radius * 2, bullet.radius * 2);

		_vBullet.push_back(bullet);
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
 				float ratio = _vBullet[i].diameter / (_vBullet[i].diameter - distance);

				float num1 = ((_vBullet[i].centerX - _vBullet[j].centerX) / ratio) / 2.0f;
				float num2 = ((_vBullet[i].centerY - _vBullet[j].centerY) / ratio) / 2.0f;

				if (_vBullet[i].centerX > _vBullet[j].centerX)
				{
					_vBullet[i].centerX += num1;
					_vBullet[j].centerX -= num2;
				}
				else
				{
					_vBullet[i].centerX -= num1;
					_vBullet[j].centerX += num1;
				}

				if (_vBullet[i].centerY > _vBullet[j].centerY)
				{
					_vBullet[i].centerY += num1;
					_vBullet[j].centerY -= num1;
				}
				else
				{
					_vBullet[i].centerY += num1;
					_vBullet[j].centerY -= num1;
				}

				if (abs(_vBullet[i].centerX - _vBullet[j].centerX) < abs(_vBullet[i].centerY - _vBullet[j].centerY))
				{
					_vBullet[i].moveY = -_vBullet[i].moveY;
				}
				else
				{
					_vBullet[i].moveX = -_vBullet[i].moveX;
				}
			}
		}
	}

	// �Ѿ� �̵�
	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		_vBulletIter->centerX += cosf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveX * _vBulletIter->speed;
		_vBulletIter->centerY += sinf(DEGREE_RADIAN(_vBulletIter->angle)) * _vBulletIter->moveY * _vBulletIter->speed;

		// �� �浹
		if (_vBulletIter->centerX - _vBulletIter->radius < 0)
		{
			_vBulletIter->centerX -= _vBulletIter->centerX - _vBulletIter->radius;

			_vBulletIter->angle = 180 + (360 - _vBulletIter->angle);
			//_vBulletIter->moveX = -_vBulletIter->moveX;
		}

		if (_vBulletIter->centerX + _vBulletIter->radius > WINSIZE_X)
		{
			_vBulletIter->centerX -= (_vBulletIter->centerX + _vBulletIter->radius) - WINSIZE_X;

			_vBulletIter->angle = 180 + (360 - _vBulletIter->angle);
			//_vBulletIter->moveX = -_vBulletIter->moveX;
		}

		if (_vBulletIter->centerY - _vBulletIter->radius < 0)
		{
			_vBulletIter->centerY -= _vBulletIter->centerY - _vBulletIter->radius;

			_vBulletIter->angle = 360 - _vBulletIter->angle;
			//_vBulletIter->moveY = -_vBulletIter->moveY;
		}

		if (_vBulletIter->centerY + _vBulletIter->radius > WINSIZE_Y)
		{
			_vBulletIter->centerY -= (_vBulletIter->centerY + _vBulletIter->radius) - WINSIZE_Y;

			_vBulletIter->angle = 360 - _vBulletIter->angle;
			//_vBulletIter->moveY = -_vBulletIter->moveY;
		}
	}
}

void Report_15_2_MainGame::render(void)
{
	LineMake(getMemDC(),
		WINSIZE_X / 2,
		WINSIZE_Y,
		WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30),
		WINSIZE_Y + sinf(DEGREE_RADIAN(_currentAngle)) * (_radius + 30)
	);

	EllipseMakeCenter(getMemDC(), WINSIZE_X / 2, WINSIZE_Y, _radius);

	for (_vBulletIter = _vBullet.begin(); _vBulletIter != _vBullet.end(); ++_vBulletIter)
	{
		EllipseMakeCenter(getMemDC(), _vBulletIter->centerX, _vBulletIter->centerY, _vBulletIter->radius);
	}
}

#include "Stdafx.h"
#include "Report_Racing_Game.h"

/*
���� 1. ���̽� ����

- �̹��� �ʼ� : ��� + �ڵ��� (�÷��̾� + ��) + �����

- ������� �� �ӷ¿� ���� ��ȯ�� �ؾ� �ϰ� ���� �ӵ��� �ִ� �ӵ��� ����ó�� �Ѵ�.

- �߿��Ѱ� ���ǵ尨

- ���� �ý��� ����

- + ��ų 3�� ����
�� 1. ��ȣ��
�� 2. @
�� 3. ȫ�� ������

�� ���� ����� ���
*/

HRESULT Report_Racing_Game::init()
{
	// ��� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addImage("background", "Resources/Images/RacingGame/background.bmp", 840, WINSIZE_Y + 100);
	// ����� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addImage("meterboard", "Resources/Images/RacingGame/meterboard.bmp", WINSIZE_X - 300.0f, WINSIZE_Y - 300.0f, 300, 300, true, RGB(182, 185, 183));
	// ��ŸƮ ��ȣ �̹��� �ʱ�ȭ
	IMAGEMANAGER->addFrameImage("signalCount", "Resources/Images/RacingGame/signalCount.bmp", 840, 1000, 1, 5, true, RGB(255, 0, 255));

	// �÷��̾� ��ü �ʱ�ȭ
	_player.width = 66;
	_player.height = 65;
	_player.speed = 10.0f;
	_player.currentDist = 0;
	_player.alpha = 255;
	_player.isAccel = false;
	_player.isInvincible = false;
	_player.rc = RectMake(620 - _player.width / 2, WINSIZE_Y - _player.height * 2, _player.width, _player.height);

	// �÷��̾� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addImage("player", "Resources/Images/RacingGame/spongeBob.bmp", _player.rc.left, _player.rc.top, _player.width, _player.height, true, RGB(255, 0, 255));

	// ����ü �ʱ�ȭ
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		_enemy[i].width = 66;
		_enemy[i].height = 65;
		_enemy[i].currentDist = 0;
		_enemy[i].speed = 10.0f;
		_enemy[i].maxSpeed = RND->getFromIntTo(40, 50);
		_enemy[i].rc = RectMake(197 + i * 130, WINSIZE_Y - 130, _enemy[i].width, _enemy[i].height);
	}

	IMAGEMANAGER->addImage("enemy1", "Resources/Images/RacingGame/Darwin.bmp", _enemy[0].rc.left, _enemy[0].rc.top, _enemy[0].width, _enemy[0].height, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("enemy2", "Resources/Images/RacingGame/Patrick.bmp", _enemy[1].rc.left, _enemy[1].rc.top, _enemy[1].width, _enemy[1].height, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("enemy3", "Resources/Images/RacingGame/Stimpy.bmp", _enemy[2].rc.left, _enemy[2].rc.top, _enemy[2].width, _enemy[2].height, true, RGB(255, 0, 255));

	// ��� ���� �ʱ�ȭ
	_count = _index = 0;
	_offsetY = 0;

	_isStart = false;
	_isColliderShow = false;

	return S_OK;
}

void Report_Racing_Game::release(void)
{
	IMAGEMANAGER->deleteImage("background");
	IMAGEMANAGER->deleteImage("signalCount");
	IMAGEMANAGER->deleteImage("meterboard");
	IMAGEMANAGER->deleteImage("player");

	IMAGEMANAGER->deleteImage("enemey1");
	IMAGEMANAGER->deleteImage("enemey2");
	IMAGEMANAGER->deleteImage("enemey3");
}

void Report_Racing_Game::update(void)
{
	// ���� ī��Ʈ
	if (!_isStart)
	{
		_count++;
		if (_count % 50 == 0)
		{
			if (_index > IMAGEMANAGER->findImage("signalCount")->getMaxFrameY())
			{
				_isStart = true;
				_index = 0;
				_count = 0;
			}

			_index++;
			IMAGEMANAGER->findImage("signalCount")->setFrameY(_index);
		}
	}
	else
	{
		// �ݶ��̴� ����
		if (KEYMANAGER->isOnceKeyDown(VK_F1))
		{
			_isColliderShow = !_isColliderShow;
		}

		// Ű �Է�(��, �Ʒ�) = �ӵ�
		if (KEYMANAGER->isStayKeyDown(VK_UP) && _player.speed < MAX_SPEED)
		{
			_player.isAccel = true;
			_player.speed += 0.2f;
		}

		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_player.isAccel = false;
		}

		if (!_player.isAccel && _player.speed > MIN_SPEED)
		{
			_player.speed -= 0.1f;
		}

		if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _player.speed > MIN_SPEED)
		{
			_player.speed -= 0.3f;
		}


		// Ű �Է�(��, ��) = ���� ��ȯ
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_player.rc.left -= 5;
			_player.rc.right -= 5;
		}

		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_player.rc.left += 5;
			_player.rc.right += 5;
		}

		// �ν���
		if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
		{
			_player.speed = 60.0f;
			_player.isAccel = false;
		}


		// �÷��̾� �Ÿ� ����
		_player.currentDist += _player.speed * 0.1f;

		// �� �Ÿ� ����
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			// �ִ� �ӵ����� ����
			if (_enemy[i].speed < _enemy[i].maxSpeed)
			{
				_enemy[i].speed += 0.3f;
			}

			// �� / �÷��̾� �浹 ó��
			RECT rt;
			if (IntersectRect(&rt, &_enemy[i].rc, &_player.rc))
			{
				cout << "�浹 ó��" << endl;
				_player.speed = 15.0f;
				_player.isInvincible = true;
			}

			_enemy[i].currentDist += _enemy[i].speed * 0.1f;
			_enemy[i].rc.top = _player.currentDist - _enemy[i].currentDist + (WINSIZE_Y - 100);
			_enemy[i].rc.bottom = _enemy[i].rc.top + _enemy[i].height;
		}

		// ��������
		if (_player.isInvincible)
		{
			_count++;
			if (_count % 2 == 0)
			{
				_player.alpha = 255;
			}
			else
			{
				_player.alpha = 1;
			}

			if (_count > 100)
			{
				_player.alpha = 255;
				_player.isInvincible = false;
				_count = 0;
			}
		}

		// offsetY ���� ����
		_offsetY -= _player.speed;
	}
}

void Report_Racing_Game::render(void)
{
	// ���
	IMAGEMANAGER->loopRender("background", getMemDC(), &RectMake(0, 0, 840, WINSIZE_Y), 0, _offsetY);

	if (!_isStart)
	{
		// ���� ī��Ʈ
		IMAGEMANAGER->frameRender("signalCount", getMemDC(), 0, 50);
	}

	// �÷��̾�
	IMAGEMANAGER->alphaRender("player", getMemDC(), _player.rc.left, _player.rc.top, _player.alpha);

	// ��
	IMAGEMANAGER->render("enemy1", getMemDC(), _enemy[0].rc.left, _enemy[0].rc.top);
	IMAGEMANAGER->render("enemy2", getMemDC(), _enemy[1].rc.left, _enemy[1].rc.top);
	IMAGEMANAGER->render("enemy3", getMemDC(), _enemy[2].rc.left, _enemy[2].rc.top);

	// ��ü �浹����
	if (_isColliderShow)
	{
		DrawRectMake(getMemDC(), _player.rc);
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			DrawRectMake(getMemDC(), _enemy[i].rc);
		}
	}

	// �����
	IMAGEMANAGER->render("meterboard", getMemDC(), IMAGEMANAGER->findImage("meterboard")->getX(), IMAGEMANAGER->findImage("meterboard")->getY());

	// �ӵ���
	HPEN myPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(getMemDC(), myPen);

	LineMake(getMemDC(),
		IMAGEMANAGER->findImage("meterboard")->getX() + IMAGEMANAGER->findImage("meterboard")->getWidth() / 2,
		IMAGEMANAGER->findImage("meterboard")->getY() + IMAGEMANAGER->findImage("meterboard")->getHeight() / 2,
		IMAGEMANAGER->findImage("meterboard")->getX() + IMAGEMANAGER->findImage("meterboard")->getWidth() / 2 + cosf(DEGREE_RADIAN(_player.speed * 5 + 105)) * 100.0f,
		IMAGEMANAGER->findImage("meterboard")->getY() + IMAGEMANAGER->findImage("meterboard")->getHeight() / 2 + sinf(DEGREE_RADIAN(_player.speed * 5 + 105)) * 100.0f);

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		char distance[128];
		wsprintf(distance, "Enemey%d : %f", i, _enemy[i].currentDist);
		TextOut(getMemDC(), WINSIZE_X - 300, 300 + i * 50, distance, strlen(distance));
	}

	SelectObject(getMemDC(), oldPen);
	DeleteObject(myPen);
}

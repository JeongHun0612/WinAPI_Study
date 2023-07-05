#include "Stdafx.h"
#include "Report_Attack_Defense.h"

/*
���� 1. ĳ���� ���� �� ���

- �ʼ� : �̹��� -> ��� / ü�¹� / �÷��̾� (���, ����, ���), �� (���, ����, �ǰ�)

- �⺻ ������ ��������ó�� �� / ��� ��ġ
�� + ü�¹�

- �÷��̾�� ���� �� �� �� �� �ְ� ���� ���� �� �ǰ� ����� �����Ѵ�.
�� �� : ����ƺ�

- �÷��̾�� ��� ���� < - > ���� ���� on / off ��ɸ� (�̵� X)

- ����, ���, �ǰ� ���� �߻��ϸ� ��Ȳ�� �´� ����� ȭ�鿡 ������ �Ѵ�.
�� ����, ������, ġ��Ÿ ��)

- �������� ǥ���Ѵ�.
�� ������ �� �� ������ �غ���.
*/

HRESULT Report_Attack_Defense::init(void)
{
	// �÷��̾� �̹���
	IMAGEMANAGER->addFrameImage("player_head", "Resources/Images/Player/Head.bmp", 244, 44, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_body", "Resources/Images/Player/Body.bmp", 272, 300, 8, 10, true, RGB(255, 0, 255));

	// Ÿ�� �̹���
	IMAGEMANAGER->addImage("dirt", "Resources/Images/Tile/dirt1.bmp", 192, 128);

	_player.headImg = IMAGEMANAGER->findImage("player_head");
	_player.bodyImg = IMAGEMANAGER->findImage("player_body");

	_player.x = WINSIZE_X / 2;
	_player.y = WINSIZE_Y / 2 - 16;

	_player.rc = RectMake(_player.x, _player.y, 64, 64);
	_player.curDirection = PLAYER_DIRECTION::NONE;

	_player.isMove = false;

	_count = 0;

	return S_OK;
}

void Report_Attack_Defense::release(void)
{
	IMAGEMANAGER->deleteImage("player_head");
	IMAGEMANAGER->deleteImage("player_body");
}

void Report_Attack_Defense::update(void)
{
	_count++;

	if (_count % 8 == 0)
	{
		_player.headImg->setFrameX(_player.headImg->getFrameX() + 1);
		_player.bodyImg->setFrameX(_player.bodyImg->getFrameX() + 1);

		if (_player.headImg->getFrameX() == _player.headImg->getMaxFrameX() / 2)
		{
			_player.bodyImg->setFrameX(0);
			_player.headImg->setFrameX(0);
			_count = 0;
		}
	}

	if (_player.isMove)
	{
		moveAction(_player.curDirection);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::LEFT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::RIGHT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::UP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::DOWN;
	}
}

void Report_Attack_Defense::render(void)
{
	// Ÿ�� �׸���
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (j % 2 == 0)
			{
				IMAGEMANAGER->findImage("dirt")->render(getMemDC(), j * 64, i * 64, 0, 0, 64, 64);
			}
			else
			{
				IMAGEMANAGER->findImage("dirt")->render(getMemDC(), j * 64, i * 64, 64, 0, 64, 64);
			}
		}
	}

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		DrawRectMake(getMemDC(), _player.rc);
	}

	_player.headImg->frameRender(getMemDC(),
		_player.x + _player.headImg->getFrameWidth() / 2,
		_player.y + _player.headImg->getFrameHeight() / 2,
		_player.headImg->getFrameX(), _player.headImg->getFrameY());

	_player.bodyImg->frameRender(getMemDC(),
		_player.x + _player.headImg->getFrameWidth() / 2,
		_player.y + _player.headImg->getFrameHeight() / 2 + 16,
		_player.bodyImg->getFrameX(), _player.bodyImg->getFrameY());
}

void Report_Attack_Defense::moveAction(PLAYER_DIRECTION direction)
{
	static int jumpCount = 0;

	switch (direction)
	{
	case Report_Attack_Defense::PLAYER_DIRECTION::LEFT:
		_player.x -= 8;
		break;
	case Report_Attack_Defense::PLAYER_DIRECTION::RIGHT:
		_player.x += 8;
		break;
	case Report_Attack_Defense::PLAYER_DIRECTION::UP:
		_player.y -= 8;
		break;
	case Report_Attack_Defense::PLAYER_DIRECTION::DOWN:
		_player.y += 8;
		break;
	}

	_player.rc = RectMake(_player.x, _player.y - 8, 64, 64);

	_player.y += (jumpCount < 4) ? -4 : 4;

	jumpCount++;

	if (jumpCount == 8)
	{
		jumpCount = 0;
		_player.isMove = false;
	}
}

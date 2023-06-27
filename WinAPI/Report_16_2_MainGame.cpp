#include "Stdafx.h"
#include "Report_16_2_MainGame.h"

/*
���� 2. �̴ϸ� �����

- 2���� ����

- �÷��̾��� �������� �̴ϸʿ����� Ȯ���� �� �־�� �Ѵ�.
�� 1. ȭ�鿡 ǥ�õǴ� ���� GUI ������ �̴ϸ�
�� 2. ȭ������ �׷����� ��üȭ�� �̴ϸ�
*/

HRESULT Report_16_2_MainGame::init(void)
{
	GameNode::init();

	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/background.bmp", WINSIZE_X, WINSIZE_Y);

	_miniMapImage = new GImage;
	_miniMapImage->init("Resources/Images/BackGround/background.bmp", WINSIZE_X / 5, WINSIZE_Y / 5);

	_miniMap = RectMake((WINSIZE_X - WINSIZE_X / 5) - 20, (WINSIZE_Y - WINSIZE_Y / 5) - 20, WINSIZE_X / 5, WINSIZE_Y / 5);

	_player.rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 50, 50);
	_player.centerPos = { WINSIZE_X / 2 - 128, WINSIZE_Y / 2 - 200 };

	_camera.width = WINSIZE_X / 5;
	_camera.height = WINSIZE_Y / 5;

	_camera.pos = { WINSIZE_X / 2 - _camera.width / 2, WINSIZE_Y / 2 - _camera.height / 2 };
	_camera.rc = RectMake(_player.centerPos.x - 250, _player.centerPos.y - 150, 500, 300);

	return S_OK;
}

void Report_16_2_MainGame::release(void)
{
	GameNode::release();
}

void Report_16_2_MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _player.rc.left > 0)
	{
		if (_camera.pos.x - 5 > 0)
		{
			_camera.pos.x -= 5;
		}
		else
		{
			_player.rc.left -= 5;
			_player.rc.right -= 5;
		}

		//_player.rc.left -= 3;
		//_player.rc.right -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _player.rc.right < WINSIZE_X)
	{
		if (_camera.pos.x + 5 < WINSIZE_X)
		{
			_camera.pos.x += 5;
		}
		else
		{
			_player.rc.left += 5;
			_player.rc.right += 5;
		}
		//_player.rc.left += 3;
		//_player.rc.right += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _player.rc.top > 0)
	{
		//_player.rc.top -= 3;
		//_player.rc.bottom -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _player.rc.bottom < WINSIZE_Y)
	{
		//_player.rc.top += 3;
		//_player.rc.bottom += 3;
	}
}

void Report_16_2_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	//_bgImage->render(memDC, 0, 0);

	// camera Render

	_bgImage->render(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, _camera.pos.x, _camera.pos.y, WINSIZE_X / 5, WINSIZE_Y / 5);

	// player Render
	DrawRectMake(memDC, _player.rc);

	_miniMapImage->render(memDC, (WINSIZE_X - WINSIZE_X / 5) - 20, (WINSIZE_Y - WINSIZE_Y / 5) - 20);
	//DrawRectMake(memDC, _camera.rc);

	this->getDoubleBuffer()->render(hdc, 0, 0);
}

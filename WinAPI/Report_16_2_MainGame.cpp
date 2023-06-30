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
	// ��� �̹��� �ʱ�ȭ
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/background.bmp", WINSIZE_X, WINSIZE_Y);


	// Ÿ�ϸ� �ʱ�ȭ
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			_tileMap[i][j].x = j * 64;
			_tileMap[i][j].y = i * 64;
			_tileMap[i][j].index = (i * MAX_COL) + j;
		}
	}

	// �̴ϸ� �ʱ�ȭ
	_miniMap.width = 400;
	_miniMap.height = 250;

	_miniMap.imgae = new GImage;
	_miniMap.imgae->init("Resources/Images/BackGround/background.bmp", _miniMap.width, _miniMap.height);
	_miniMap.x = WINSIZE_X - (_miniMap.width + 15);
	_miniMap.y = WINSIZE_Y - (_miniMap.height + 15);

	// �÷��̾� �ʱ�ȭ
	_player.pos = { WINSIZE_X / 2, WINSIZE_Y / 2 - 16 };
	_player.mapPos = { _miniMap.x + ((_player.pos.x / 64) * 10), _miniMap.y + (_player.pos.y / 64) * 10 };

	// ī�޶� �ʱ�ȭ
	_camera.pos = { 0, 0 };
	_camera.width = WINSIZE_X / 2;
	_camera.height = WINSIZE_Y / 2;
	_camera.mapPos = { _player.mapPos.x - 100, _player.mapPos.y - 60 };

	isShowTile = false;

	return S_OK;
}

void Report_16_2_MainGame::release(void)
{
}

void Report_16_2_MainGame::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _player.pos.x > 0)
	{
		if (_camera.pos.x != 0 && _player.pos.x == WINSIZE_X / 2)
		{
			_camera.pos.x -= 32;
			_camera.mapPos.x -= 10;
		}
		else
		{
			_player.pos.x -= 64;
		}

		_player.mapPos.x -= 10;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _player.pos.x + 64 < WINSIZE_X)
	{
		if (_camera.pos.x + _camera.width != WINSIZE_X && _player.pos.x == WINSIZE_X / 2)
		{
			_camera.pos.x += 32;
			_camera.mapPos.x += 10;
		}
		else
		{
			_player.pos.x += 64;
		}

		_player.mapPos.x += 10;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _player.pos.y > 0)
	{
		if (_camera.pos.y != 0 && _player.pos.y == WINSIZE_Y / 2 - 16)
		{
			_camera.pos.y -= 32;
			_camera.mapPos.y -= 10;
		}
		else
		{
			_player.pos.y -= 64;
		}

		_player.mapPos.y -= 10;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _player.pos.y + 64 < WINSIZE_Y - 64)
	{
		if (_camera.pos.y + _camera.height != WINSIZE_Y - 16 && _player.pos.y == WINSIZE_Y / 2 - 16)
		{
			_camera.pos.y += 32;
			_camera.mapPos.y += 10;
		}
		else
		{
			_player.pos.y += 64;
		}

		_player.mapPos.y += 10;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		isShowTile = !isShowTile;
	}
}

void Report_16_2_MainGame::render(void)
{
	HBRUSH myBrush;
	HBRUSH oldBrush;

	// ��� �̹��� ����
	_bgImage->render(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, _camera.pos.x, _camera.pos.y, _camera.width, _camera.height);


	// Ÿ�� ����
	if (isShowTile)
	{
		myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		oldBrush = (HBRUSH)SelectObject(getMemDC(), myBrush);

		char tileID[10];
		int startX = _camera.pos.x / 32;
		int startY = _camera.pos.y / 32;

		for (int i = 0; i < WINSIZE_Y / 64; i++)
		{
			for (int j = 0; j < WINSIZE_X / 64; j++)
			{
				RectangleMake(getMemDC(), j * 64, i * 64, 64, 64);
				sprintf_s(tileID, "%d", _tileMap[startY + i][startX + j].index);
				TextOut(getMemDC(), j * 64, i * 64, tileID, strlen(tileID));
			}
		}

		SelectObject(getMemDC(), oldBrush);
		DeleteObject(myBrush);
	}

	// �÷��̾� ����
	myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 255));
	oldBrush = (HBRUSH)SelectObject(getMemDC(), myBrush);

	RectangleMake(getMemDC(), _player.pos.x, _player.pos.y, 64, 64);
	//DrawRectMake(getMemDC(), _player.rc);

	SelectObject(getMemDC(), oldBrush);
	DeleteObject(myBrush);


	// �̴ϸ� �̹��� ����
	_miniMap.imgae->render(getMemDC(), _miniMap.x, _miniMap.y);

	myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	oldBrush = (HBRUSH)SelectObject(getMemDC(), myBrush);
	RectangleMake(getMemDC(), _camera.mapPos.x, _camera.mapPos.y, _miniMap.width / 2, _miniMap.height / 2);
	SelectObject(getMemDC(), oldBrush);
	DeleteObject(myBrush);

	RectangleMake(getMemDC(), _player.mapPos.x, _player.mapPos.y, 10, 10);
}

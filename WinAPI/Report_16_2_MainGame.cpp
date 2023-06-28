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
			_tileMap[i][j].index = 0;
		}
	}

	// ī�޶� �ʱ�ȭ
	_camera.pos = { 0, 0 };
	_camera.width = WINSIZE_X / 2;
	_camera.height = WINSIZE_Y / 2;

	// �÷��̾� �ʱ�ȭ
	_player.pos = { WINSIZE_X / 2 - 32, WINSIZE_Y / 2 + 16 };
	_player.rc = RectMakeCenter(_player.pos.x, _player.pos.y, 64, 64);

	return S_OK;
}

void Report_16_2_MainGame::release(void)
{
	GameNode::release();
}

void Report_16_2_MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _player.rc.left > 0)
	{
		_camera.pos.x -= 64;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _player.rc.right < WINSIZE_X)
	{
		_camera.pos.x += 64;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _player.rc.top > 0)
	{
	
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _player.rc.bottom < WINSIZE_Y)
	{
	
	}
}

void Report_16_2_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

	HBRUSH myBrush;
	HBRUSH oldBrush;

	// ��� �̹��� ����
	_bgImage->render(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, _camera.pos.x, _camera.pos.y, _camera.width, _camera.height);

	// Ÿ�� ����
	myBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
	oldBrush = (HBRUSH)SelectObject(memDC, myBrush);

	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			RectangleMake(memDC, _tileMap[i][j].x, _tileMap[i][j].y, 64, 64);
		}
	}

	SelectObject(memDC, oldBrush);
	DeleteObject(myBrush);


	// �÷��̾� ����
	myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 255));
	oldBrush = (HBRUSH)SelectObject(memDC, myBrush);

	DrawRectMake(memDC, _player.rc);

	SelectObject(memDC, oldBrush);
	DeleteObject(myBrush);


	// �̴ϸ� �̹��� ����
	//_miniMap.imgae->render(memDC, _miniMap.x, _miniMap.y);

	this->getDoubleBuffer()->render(hdc, 0, 0);
}

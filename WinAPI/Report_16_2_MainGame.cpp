#include "Stdafx.h"
#include "Report_16_2_MainGame.h"

/*
과제 2. 미니맵 만들기

- 2가지 버전

- 플레이어의 움직임을 미니맵에서도 확인할 수 있어야 한다.
ㄴ 1. 화면에 표시되는 작은 GUI 형태의 미니맵
ㄴ 2. 화면위에 그려지는 전체화면 미니맵
*/

HRESULT Report_16_2_MainGame::init(void)
{
	GameNode::init();

	// 배경 이미지 초기화
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/background.bmp", WINSIZE_X, WINSIZE_Y);


	// 타일맵 초기화
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			_tileMap[i][j].x = j * 64;
			_tileMap[i][j].y = i * 64;
			_tileMap[i][j].index = 0;
		}
	}

	// 카메라 초기화
	_camera.pos = { 0, 0 };
	_camera.width = WINSIZE_X / 2;
	_camera.height = WINSIZE_Y / 2;

	// 플레이어 초기화
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

	// 배경 이미지 렌더
	_bgImage->render(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, _camera.pos.x, _camera.pos.y, _camera.width, _camera.height);

	// 타일 렌더
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


	// 플레이어 렌더
	myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 255));
	oldBrush = (HBRUSH)SelectObject(memDC, myBrush);

	DrawRectMake(memDC, _player.rc);

	SelectObject(memDC, oldBrush);
	DeleteObject(myBrush);


	// 미니맵 이미지 렌더
	//_miniMap.imgae->render(memDC, _miniMap.x, _miniMap.y);

	this->getDoubleBuffer()->render(hdc, 0, 0);
}

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

	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/background.bmp", 1100, 700);
	_bgRC = RectMake(90, 50, 1100, 700);



	_miniMap.x = (_bgRC.right - _camera.width) - 20;
	_miniMap.y = (BG_SIZE_Y - _camera.height) - 20;
	_miniMap.width = BG_SIZE_X / 5;
	_miniMap.height = BG_SIZE_Y / 5;

	_miniMap.imgae = new GImage;
	_miniMap.imgae->init("Resources/Images/BackGround/background.bmp", _miniMap.width, _miniMap.height);

	_player.x = BG_SIZE_X / 2;
	_player.y = BG_SIZE_Y / 2;
	_player.rc = RectMakeCenter(_player.x, _player.y, 50, 50);

	_camera.width = BG_SIZE_X / 5;
	_camera.height = BG_SIZE_Y / 5;

	_camera.x = (BG_SIZE_X / 2)  - _camera.width / 2;
	_camera.y = (BG_SIZE_Y / 2) - _camera.height / 2;

	_camera.rc = RectMake(_camera.x, _camera.y, _camera.width, _camera.height);

	return S_OK;
}

void Report_16_2_MainGame::release(void)
{
	GameNode::release();
}

void Report_16_2_MainGame::update(void)
{
	GameNode::update();

	//if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _player.rc.left > 0)
	//{
	//	if (_camera.pos.x - 5 > 0 && _player.rc.left == WINSIZE_X / 2)
	//	{
	//		_camera.pos.x -= 5;
	//	}
	//	else
	//	{
	//		_player.rc.left -= 5;
	//		_player.rc.right -= 5;
	//	}
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _player.rc.right < WINSIZE_X)
	//{
	//	if (_camera.pos.x + _camera.width + 5 < WINSIZE_X)
	//	{
	//		_camera.pos.x += 5;
	//	}
	//	else
	//	{
	//		_player.rc.left += 5;
	//		_player.rc.right += 5;
	//	}
	//}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _player.rc.top > 0)
	{
	
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _player.rc.bottom < WINSIZE_Y)
	{
	
	}
}

void Report_16_2_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

	// 배경 이미지 렌더
	_bgImage->render(memDC, _bgRC.left, _bgRC.top, BG_SIZE_X, BG_SIZE_Y, _camera.x, _camera.y, _camera.width, _camera.height);


	// 플레이어 렌더
	DrawRectMake(memDC, _player.rc);

	// 타일



	// 미니맵 이미지 렌더
	_miniMap.imgae->render(memDC, _miniMap.x, _miniMap.y);

	this->getDoubleBuffer()->render(hdc, 0, 0);
}

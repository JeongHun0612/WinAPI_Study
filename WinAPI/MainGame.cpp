#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	_loading = new GImage;
	_loading->init("Resources/Images/Object/zero_loading.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		640 , 240,
		8 , 2,
		true, RGB(255, 0, 255));

	_alphaA = 0;
	_count = _index = 0;

	_isLeft = false;
	_isAlphaIncrease = false;

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_loading);
}

void MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK);
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		_loading->setX(_loading->getX() - 8.0f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		_loading->setX(_loading->getX() + 8.0f);
	}

	if (_isLeft)
	{
		_count++;

		_loading->setFrameY(1);

		if (_count % 3 == 0)
		{
			_index--;

			if (_index < 0)
			{
				_index = 10;
			}

			_loading->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_loading->setFrameY(0);

		if (_count % 2 == 0)
		{
			_index++;

			if (_index > 10)
			{
				_index = 0;
			}

			_loading->setFrameX(_index);
		}
	}
}

void MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();

	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ==========================================================

	_loading->frameRender(memDC, _loading->getX(), _loading->getY());

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

/*
과제 1. 제로 콤보 이미지 완성

- 스페이스 바를 누르면 1타부터 -> 마지막 공격까지 자동으로 재생
ㄴ 무한 반복


과제 2. 프레임 이미지 처리

- 시작 씬 + 게임 씬

- 게임씬에서는 아래의 이미지를 GUI화 시켜서 재생 시킨다. (버튼)
ㄴ 프레임 렌더)

- 필수 이미지
ㄴ 배경, 대기, 이동 (좌 + 우), 찌르기 (좌 + 우), 대각선 찌르기,
	연속 찌르기 (좌 + 우), 원 돌리기, 승리 포즈 (옷 던지기), 스킬 클라이막스 연출, 패배

*/
#include "Stdafx.h"
#include "Example_Loop_Render.h"

HRESULT Example_Loop_Render::init(void)
{
	IMAGEMANAGER->addImage("bg_loop", "Resources/Images/Background/Loop_bg.bmp", 1570, WINSIZE_Y);

	_offsetX = _offsetY = 0;
	_bgSpeed = 0;

	return S_OK;
}

void Example_Loop_Render::release(void)
{
	IMAGEMANAGER->deleteImage("bg_loop");
}

void Example_Loop_Render::update(void)
{
	_bgSpeed += 4;
}

void Example_Loop_Render::render(void)
{
	IMAGEMANAGER->loopRender("bg_loop", getMemDC(),
		&RectMake(0, 0, WINSIZE_X, WINSIZE_Y),
		_bgSpeed, _offsetY);
}

/*
과제 1. 레이싱 게임

- 이미지 필수 : 배경 + 자동차 (플레이어 + 적) + 계기판

- 계기판은 차 속력에 따라 변환을 해야 하고 최저 속도와 최대 속도를 예외처리 한다.

- 중요한건 스피드감

- 점수 시스템 구현

- + 스킬 3개 구현
ㄴ 1. 보호막
ㄴ 2. @
ㄴ 3. 홍해 가르기

※ 전자 계기판 사망
*/

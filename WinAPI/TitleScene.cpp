#include "Stdafx.h"
#include "TitleScene.h"



HRESULT TitleScene::init(void)
{
	// 과제 파일 초기화


	// 수업 파일 초기화
	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		_exampleBtn[i].rc = RectMake(20 + (i % 6) * 200, 50 + (i / 6) * 80, 150, 50);
	}

	wsprintf(_exampleBtn[EXAMPLE_MOLE].name, "두더지 게임");
	wsprintf(_exampleBtn[EXAMPLE_BULLET].name, "총알 발사");
	wsprintf(_exampleBtn[EXAMPLE_MATH].name, "삼각 함수");
	wsprintf(_exampleBtn[EXAMPLE_IMAGE].name, "이미지 출력");
	wsprintf(_exampleBtn[EXAMPLE_CLIPING].name, "클리핑 이미지");
	wsprintf(_exampleBtn[EXAMPLE_FRAME_IMAGE].name, "프레임 이미지");

	return S_OK;
}

void TitleScene::release(void)
{
}

void TitleScene::update(void)
{
}

void TitleScene::render(void)
{
	SetTextAlign(getMemDC(), TA_LEFT);
	TextOut(getMemDC(), 20, 20, "과제 파일", strlen("과제 파일"));

	SetTextAlign(getMemDC(), TA_CENTER);
	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		DrawRectMake(getMemDC(), _exampleBtn[i].rc);
		TextOut(getMemDC(),
			_exampleBtn[i].rc.left + (_exampleBtn[i].rc.right - _exampleBtn[i].rc.left) / 2,
			_exampleBtn[i].rc.top + (_exampleBtn[i].rc.bottom - _exampleBtn[i].rc.top) / 2 - 10,
			_exampleBtn[i].name, strlen(_exampleBtn[i].name));
	}

	LineMake(getMemDC(), 0, WINSIZE_Y / 2, WINSIZE_X, WINSIZE_Y / 2);


	SetTextAlign(getMemDC(), TA_LEFT);
	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 20, "수업 파일", strlen("수업 파일"));
}

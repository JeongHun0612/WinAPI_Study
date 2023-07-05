#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	return E_NOTIMPL;
}

void SecondScene::release(void)
{
}

void SecondScene::update(void)
{
}

void SecondScene::render(void)
{

	// SetBkMode() : 텍스트 배경을 투명하게 해준다.
	SetBkMode(getMemDC(), TRANSPARENT);

	// 기존 텍스트
	char str[128];
	wsprintf(str, "기존");
	TextOut(getMemDC(), 230, 350, str, strlen(str));

	// 새로운 방식
	HFONT font;
	HFONT oldFont;

	/*
	font = CreateFont
	(
		문자크기, 문자폭, 전체 기울기, 문자 방향, 문자 굴기,
		기울기 (T/F), 밑줄 (T/F), 취소선(T/F),
		문자 세팅, 출력 정확도, 클릭 정확도, 출력의 질, 자간, 폰트
	);
	*/

	font = CreateFont
	(
		70, 0, 0, 0, 600,
		0, 0, 1,
		HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("휴면굴림")
	);

	oldFont = (HFONT)SelectObject(getMemDC(), font);

	wsprintf(str, "새로운 폰트");
	TextOut(getMemDC(), 100, 400, str, strlen(str));
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);
}

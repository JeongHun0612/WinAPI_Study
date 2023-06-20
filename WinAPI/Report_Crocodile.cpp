#include "Stdafx.h"
#include "Report_Crocodile.h"

/*
과제 3. 악어이빨 게임

- 악어이빨은 최소 8개 이상

- 악어이빨에 물렸는지 아닌지에 대해서 확인이 가능해야 한다.

- 필수 : 악어이빨이 닫히는 애니메이션 구현
*/

HRESULT Report_Crocodile::init(void)
{
	return S_OK;
}

void Report_Crocodile::release(void)
{
}

void Report_Crocodile::update(void)
{
}

void Report_Crocodile::render(HDC hdc)
{
	TextOut(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, "악어 게임", strlen("악어 게임"));
}

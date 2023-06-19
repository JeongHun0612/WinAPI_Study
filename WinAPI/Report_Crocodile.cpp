#include "Stdafx.h"
#include "Report_Crocodile.h"

HRESULT Report_Crocodile::init(void)
{
	GameNode::init();

	return S_OK;
}

void Report_Crocodile::release(void)
{
	GameNode::release();
}

void Report_Crocodile::update(void)
{
	GameNode::update();
}

void Report_Crocodile::render(HDC hdc)
{
	TextOut(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, "æ«æÓ ∞‘¿”", strlen("æ«æÓ ∞‘¿”"));
}

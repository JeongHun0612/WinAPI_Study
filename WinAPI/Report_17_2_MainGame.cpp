#include "Stdafx.h"
#include "Report_17_2_MainGame.h"

HRESULT Report_17_2_MainGame::init(void)
{
	GameNode::init();

	for (int i = 0; i < 10; i++)
	{
		_MotionBtn[i].idx = i;
		_MotionBtn[i].rc = RectMake(50 + (i / 5) * 980, 50 + (i % 5) * 155, 200, 80);
	}

	return S_OK;
}

void Report_17_2_MainGame::release(void)
{
	GameNode::release();
}

void Report_17_2_MainGame::update(void)
{
	GameNode::update();
}

void Report_17_2_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ==========================================================

	for (int i = 0; i < MAX_MOTION; i++)
	{
		DrawRectMake(memDC, _MotionBtn[i].rc);
	}

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

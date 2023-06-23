#include "Stdafx.h"
#include "Report_15_4_MainGame.h"

HRESULT Report_15_4_MainGame::init(void)
{
	GameNode::init();

	return S_OK;
}

void Report_15_4_MainGame::release(void)
{
	GameNode::release();
}

void Report_15_4_MainGame::update(void)
{
	GameNode::update();
}

void Report_15_4_MainGame::render(HDC hdc)
{

}

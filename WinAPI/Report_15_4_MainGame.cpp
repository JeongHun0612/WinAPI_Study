#include "Stdafx.h"
#include "Report_15_4_MainGame.h"

/*
과제 4. 발사한 총알에 중력 적용

- 총알이 중력을 받아 떨어진다. -> 힘이 다하면

*/

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

#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	_mg->init();

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	_mg->release();
}

void MainGame::update(void)
{
	GameNode::update();

	_mg->update();



	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK);
		{
			PostQuitMessage(0);
		}
	}

}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	_mg->render();

	this->getBackBuffer()->render(getHDC(), 0, 0);
}
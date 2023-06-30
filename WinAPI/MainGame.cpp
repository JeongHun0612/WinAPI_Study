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

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK);
		{
			PostQuitMessage(0);
		}
	}

	_mg->update();
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	_mg->render();

	this->getBackBuffer()->render(getHDC(), 0, 0);
}

/*
과제 1. 캐릭터 벽잡기

- 이미지 필수 : 배경, 벽, 캐릭터 (대기, 이동, 점프, 벽을 잡고 있는 모션)

- 기본적으로 벽을 잡을때는 가장 위쪽 모서리를 잡으며 벽 중간을 잡았을 경우 천천히 지면으로 내려온다.

- 캐릭터가 벽을 잡고 있는 상태에서 위 / 또는 아래 방향키를 누르면 올라가거나 / 내려갈 수 있어야 한다.

- 또한 캐릭터가 벽 위로 올라선 다음 다시 아래로 점프하면 캐릭터는 지면에 착지 할 수 있어야 한다.

- 캐릭터 점프 높이의 지형이 있고 캐릭터는 지형 밑에서 점프로 지형위로 올라 갈 수 있다.

- 캐릭터는 지형에 올라선 상태에서 지면으로 다시 내려올 수 있으면 OK


과제 2. 미니맵 연동

- 플레이어의 움직임을 미니맵에서 그대로 확인해야 한다.
ㄴ 움직임까지 동일하게
*/
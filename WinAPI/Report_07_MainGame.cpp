#include "Stdafx.h"
#include "Report_07_MainGame.h"

/*
과제1. 두더지 게임

- 두더지의 수는 최소 8마리 부터 시작한다.

- 화면에 현재 점수를 표기한다.

- 예외 처리
	ㄴ 두더지를 한번 클릭하면 점수 증가
		ㄴ 이후 두더지가 사라질때까지 재클릭을 해도 점수가 오르면 안된다.
*/

HRESULT Report_07_MainGame::init(void)
{
	GameNode::init();

	_tCreateCycle = clock();
	_nScore = 0;

	for (int i = 0; i < MAX_MOLE; i++)
	{
		_Mole[i] = new Mole(200 + (200 * (i % 3)), 150 + (200 * (i / 3)));
	}

	return S_OK;
}

void Report_07_MainGame::release(void)
{
	GameNode::release();
}

void Report_07_MainGame::update(void)
{
	GameNode::update();

	// 두더지 생성 주기
	if ((clock() - _tCreateCycle) / CLOCKS_PER_SEC > CREATE_CYCLE)
	{
		// 두더지 상태 초기화
		for (int i = 0; i < MAX_MOLE; i++)
		{
			_Mole[i]->setState(false);
		}

		// 두더지 랜덤 등장
		for (int i = 0; i < MAX_MOLE; i++)
		{
			if (RND->getInt(3) == 0)
			{
				_Mole[i]->setState(true);
			}
		}

		_tCreateCycle = clock();
	}

	// 두더지 클릭
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < MAX_MOLE; i++)
		{
			if (_Mole[i]->isPointInRect() && _Mole[i]->getState())
			{
				_Mole[i]->setState(false);
				_nScore++;
			}
		}
	}
}

void Report_07_MainGame::render(HDC hdc)
{
	// Draw Score
	wsprintf(_ScoreStr, "Score : %d", _nScore);
	TextOut(hdc, 10, 10, _ScoreStr, strlen(_ScoreStr));

	// Draw Hole
	for (int i = 0; i < MAX_MOLE; i++)
	{
		EllipseMakeCenter(hdc, 200 + (200 * (i % 3)), 200 + (200 * (i / 3)), 150, 100);
	}

	// Draw Mole
	for (int i = 0; i < MAX_MOLE; i++)
	{
		_Mole[i]->drawMole(hdc);
	}
}

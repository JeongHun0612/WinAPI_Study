#include "Stdafx.h"
#include "Report_ClayShooting.h"

/*
과제2. 클레이 사격

- 좌 / 우에서 무작위로 출현하는 타켓을 마우스로 제거한다.

- 타켓을 제거하면 점수 획득
	ㄴ 제거된 타켓은 그자리에서 바로 떨어진다.

- 등장하는 타켓의 종류는 무작위 도형 처리
	ㄴ 사각형 : 50점	/ 원 : -100점 / 다각형 : 100점

- 게임 시간은 60초로 한정하고 시간이 다 되거나 내 점수가 5천점이 되면 게임 종료
*/

HRESULT Report_ClayShooting::init(void)
{
	_nGameTime = 60;
	_nDeltaTime = 0;

	_nScore = 0;

	// Target init
	for (int i = 0; i < TARGET_MAX; i++)
	{
		_Target[i] = NULL;
	}

	return S_OK;
}

void Report_ClayShooting::release(void)
{
}

void Report_ClayShooting::update(void)
{
	// Create Target
	if (_nDeltaTime % 100 == 0)
	{
		int createCount = RND->getFromIntTo(1, 3);

		for (int i = 0; i < createCount; i++)
		{
			if (_Target[i] != NULL) break;

			int rndPosY = RND->getFromIntTo(300, 400);
			float rndSpeed = RND->getFromIntTo(10, 12);

			_Target[i] = RND->getInt(2) ? new Target(-50, rndPosY, 1, rndSpeed) : new Target(WINSIZE_X + 50, rndPosY, -1, rndSpeed);
		}
	}

	// Target Move
	for (int i = 0; i < TARGET_MAX; i++)
	{
		if (_Target[i] == NULL) break;

		_Target[i]->move();

		// Target Delete
		if (_Target[i]->getPosX() < -50 || _Target[i]->getPosX() > WINSIZE_X + 50 || _Target[i]->getPosY() > WINSIZE_Y + 50)
		{
			delete(_Target[i]);
			_Target[i] = NULL;
		}
	}

	// Target Click
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < TARGET_MAX; i++)
		{
			if (_Target[i] == NULL) break;

			if (_Target[i]->isPointInRect() && !_Target[i]->getClick())
			{
				_Target[i]->setMoveX(0);
				_Target[i]->setSpeed(-1.0f);
				_Target[i]->setClick(true);
				_nScore += 50;
			}
		}
	}

	// GameEnd
	if (getTimeOver() || _nScore >= 5000)
	{
		PostQuitMessage(0);
	}
}

void Report_ClayShooting::render(void)
{
	wsprintf(_cTimer, "Game Time : %2d", _nGameTime);
	TextOut(getMemDC(), 10, 0, _cTimer, strlen(_cTimer));

	wsprintf(_cScore, "Score : %4d", _nScore);
	TextOut(getMemDC(), WINSIZE_X - 100, 0, _cScore, strlen(_cScore));

	for (int i = 0; i < TARGET_MAX; i++)
	{
		if (_Target[i] == NULL) break;

		_Target[i]->drawTarget(getMemDC());
	}
}

bool Report_ClayShooting::getTimeOver()
{
	_nDeltaTime++;

	if (_nDeltaTime % 100 == 0)
	{
		_nGameTime--;
	}

	if (_nGameTime != 0) return false;

	return true;
}


#include "Stdafx.h"
#include "Report_ClayShooting.h"

/*
����2. Ŭ���� ���

- �� / �쿡�� �������� �����ϴ� Ÿ���� ���콺�� �����Ѵ�.

- Ÿ���� �����ϸ� ���� ȹ��
	�� ���ŵ� Ÿ���� ���ڸ����� �ٷ� ��������.

- �����ϴ� Ÿ���� ������ ������ ���� ó��
	�� �簢�� : 50��	/ �� : -100�� / �ٰ��� : 100��

- ���� �ð��� 60�ʷ� �����ϰ� �ð��� �� �ǰų� �� ������ 5õ���� �Ǹ� ���� ����
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


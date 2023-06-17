#include "Stdafx.h"
#include "Report_08_MainGame.h"

/*
����2. Ŭ���� ���

- �� / �쿡�� �������� �����ϴ� Ÿ���� ���콺�� �����Ѵ�.

- Ÿ���� �����ϸ� ���� ȹ��
	�� ���ŵ� Ÿ���� ���ڸ����� �ٷ� ��������.

- �����ϴ� Ÿ���� ������ ������ ���� ó��
	�� �簢�� : 50��	/ �� : -100�� / �ٰ��� : 100��

- ���� �ð��� 60�ʷ� �����ϰ� �ð��� �� �ǰų� �� ������ 5õ���� �Ǹ� ���� ����
*/

HRESULT Report_08_MainGame::init(void)
{
	GameNode::init();

	_nGameTime = 60;
	_nDeltaTime = 0;

	_nScore = 0;

	for (int i = 0; i < TARGET_MAX; i++)
	{
		_Target[i] = NULL;
	}

	return S_OK;
}

void Report_08_MainGame::release(void)
{
	GameNode::release();
}

void Report_08_MainGame::update(void)
{
	GameNode::update();

	// Create Target
	if (_nDeltaTime % 100 == 0)
	{
		for (int i = 0; i < RND->getFromIntTo(1, 3); i++)
		{
			if (_Target[i] != NULL) break;

			if (RND->getInt(2))
			{
				_Target[i] = new Target(-50, RND->getFromIntTo(300, 500), 1, RND->getFromIntTo(8, 10));
			}
			else
			{
				_Target[i] = new Target(850, RND->getFromIntTo(300, 500), -1, RND->getFromIntTo(8, 10));
			}
		}
	}

	// Target Move
	for (int i = 0; i < TARGET_MAX; i++)
	{
		if (_Target[i] == NULL) break;

		_Target[i]->move();

		if (_Target[i]->getPosX() < -50 || _Target[i]->getPosX() > 850 || _Target[i]->getPosY() > 850)
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

void Report_08_MainGame::render(HDC hdc)
{
	wsprintf(_cTimer, "Game Time : %2d", _nGameTime);
	TextOut(hdc, 10, 0, _cTimer, strlen(_cTimer));

	wsprintf(_cScore, "Score : %4d", _nScore);
	TextOut(hdc, 700, 0, _cScore, strlen(_cScore));

	for (int i = 0; i < TARGET_MAX; i++)
	{
		if (_Target[i] == NULL) break;

		_Target[i]->drawTarget(hdc);
	}
}

bool Report_08_MainGame::getTimeOver()
{
	_nDeltaTime++;

	if (_nDeltaTime % 100 == 0)
	{
		_nGameTime--;
	}

	if (_nGameTime != 0) return false;

	return true;
}


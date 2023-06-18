#include "Stdafx.h"
#include "Report_07_MainGame.h"

/*
����1. �δ��� ����

- �δ����� ���� �ּ� 8���� ���� �����Ѵ�.

- ȭ�鿡 ���� ������ ǥ���Ѵ�.

- ���� ó��
	�� �δ����� �ѹ� Ŭ���ϸ� ���� ����
		�� ���� �δ����� ����������� ��Ŭ���� �ص� ������ ������ �ȵȴ�.
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

	// �δ��� ���� �ֱ�
	if ((clock() - _tCreateCycle) / CLOCKS_PER_SEC > CREATE_CYCLE)
	{
		// �δ��� ���� �ʱ�ȭ
		for (int i = 0; i < MAX_MOLE; i++)
		{
			_Mole[i]->setState(false);
		}

		// �δ��� ���� ����
		for (int i = 0; i < MAX_MOLE; i++)
		{
			if (RND->getInt(3) == 0)
			{
				_Mole[i]->setState(true);
			}
		}

		_tCreateCycle = clock();
	}

	// �δ��� Ŭ��
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

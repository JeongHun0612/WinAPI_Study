#include "Stdafx.h"
#include "Report_Mole.h"

/*
����1. �δ��� ����

- �δ����� ���� �ּ� 8���� ���� �����Ѵ�.

- ȭ�鿡 ���� ������ ǥ���Ѵ�.

- ���� ó��
	�� �δ����� �ѹ� Ŭ���ϸ� ���� ����
		�� ���� �δ����� ����������� ��Ŭ���� �ص� ������ ������ �ȵȴ�.
*/

HRESULT Report_Mole::init(void)
{
	_tCreateCycle = clock();
	_nScore = 0;

	for (int i = 0; i < MAX_MOLE; i++)
	{
		_Mole[i] = new Mole(200 + (200 * (i % 3)), 150 + (200 * (i / 3)));
	}

	return S_OK;
}

void Report_Mole::release(void)
{
}

void Report_Mole::update(void)
{
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

void Report_Mole::render(void)
{
	// Draw Score
	wsprintf(_ScoreStr, "Score : %d", _nScore);
	TextOut(getMemDC() , 10, 10, _ScoreStr, strlen(_ScoreStr));

	// Draw Hole
	for (int i = 0; i < MAX_MOLE; i++)
	{
		EllipseMakeCenter(getMemDC(), 200 + (200 * (i % 3)), 200 + (200 * (i / 3)), 150, 100);
	}

	// Draw Mole
	for (int i = 0; i < MAX_MOLE; i++)
	{
		_Mole[i]->drawMole(getMemDC());
	}
}

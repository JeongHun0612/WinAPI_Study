#include "Stdafx.h"
#include "Report_06_MainGame.h"

static int tempID = 0;
static int selectCount = 0;
static bool isAnswer = false;
static int firstCardID = 0;
static int secondCardID = 0;

HRESULT Report_06_MainGame::init(void)
{
	Report_06_GameNode::init();

	int startX = 100;
	int startY = 50;
	int colorCode[3];

	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
		{
			colorCode[0] = RND->getInt(255);
			colorCode[1] = RND->getInt(255);
			colorCode[2] = RND->getInt(255);
		}

		_Card[i] = Card(i, i / 2, colorCode, RectMake(startX + ((i % CARD_ROW) * 120), startY + ((i / CARD_ROW)  * 175), 100, 150));
	}

	return S_OK;
}

void Report_06_MainGame::release(void)
{
	Report_06_GameNode::release();
}

void Report_06_MainGame::update(void)
{
	Report_06_GameNode::update();

	for (int i = 0; i < 20; i++)
	{
		if (_Card[i].isPointInRect())
		{
			selectCount++;
			_Card[i].setSelect(true);

			if (selectCount == 1)
			{
				firstCardID = _Card[i].getCardID();
			}
			else
			{
				secondCardID = _Card[i].getCardID();
			}
		}
	}
}

void Report_06_MainGame::render(HDC hdc)
{
	wsprintf(str, "X : %d   Y : %d", _ptMouse.x, _ptMouse.y);
	TextOut(hdc, 0, 0, str, strlen(str));

	for (int i = 0; i < 20; i++)
	{
		_Card[i].drawCard(hdc);
	}

	if (selectCount == 2)
	{
		if (_Card[firstCardID].getAnswerNum() == _Card[secondCardID].getAnswerNum())
		{
			_Card[firstCardID].setAnswer(true);
			_Card[secondCardID].setAnswer(true);
		}
		else
		{
			_Card[firstCardID].setSelect(false);
			_Card[secondCardID].setSelect(false);
		}

		selectCount = 0;
	}
}

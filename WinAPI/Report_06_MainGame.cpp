#include "Stdafx.h"
#include "Report_06_MainGame.h"

/*
과제 1. 카드 짝 맞추기

- 사이즈 : 5 X 4

- 카드 짝을 맞추면 맞춘 카드는 계속 오픈되야 한다.

- 치트 필수
ㄴ 1. 전부 오픈 후 일정 시간 후 다시 감추기
ㄴ 2. 1쌍을 제외하고 나머지는 전부 오픈되고 1쌍을 맞추면서 종료

※ HBRUSH
*/

HRESULT Report_06_MainGame::init(void)
{
	GameNode::init();

	for (int i = 0; i < CARD_MAX; i++)
	{
		_Card[i] = Card(i, i / 2, 100 + ((i % 5) * 120), 50 + ((i / 5) * 175));
	}

	/*for (int i = 0; i < CARD_MAX; i++)
	{
		if (i % 2 == 0)
		{
			colorCode[0] = RND->getInt(255);
			colorCode[1] = RND->getInt(255);
			colorCode[2] = RND->getInt(255);
		}

		_Card[i] = Card(i, i / 2, colorCode, RectMake(100 + ((i % 5) * 120), 50 + ((i / 5) * 175), 100, 150));
	}*/

	return S_OK;
}

void Report_06_MainGame::release(void)
{
	GameNode::release();
}

void Report_06_MainGame::update(void)
{
	GameNode::update();

	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//}

	//for (int i = 0; i < 20; i++)
	//{
	//	if (_Card[i].isPointInRect())
	//	{
	//		selectCount++;
	//		_Card[i].setSelect(true);

	//		if (selectCount == 1)
	//		{
	//			firstCardID = _Card[i].getCardID();
	//		}
	//		else
	//		{
	//			secondCardID = _Card[i].getCardID();
	//		}
	//	}
	//}
}

void Report_06_MainGame::render(HDC hdc)
{
	wsprintf(str, "X : %d   Y : %d", _ptMouse.x, _ptMouse.y);
	TextOut(hdc, 0, 0, str, strlen(str));

	for (int i = 0; i < CARD_MAX; i++)
	{
		_Card[i].drawCard(hdc);
	}

	//if (selectCount == 2)
	//{
	//	if (_Card[firstCardID].getAnswerNum() == _Card[secondCardID].getAnswerNum())
	//	{
	//		_Card[firstCardID].setAnswer(true);
	//		_Card[secondCardID].setAnswer(true);
	//	}
	//	else
	//	{
	//		_Card[firstCardID].setSelect(false);
	//		_Card[secondCardID].setSelect(false);
	//	}

	//	selectCount = 0;
	//}
}

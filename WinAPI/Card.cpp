#include "Stdafx.h"
#include "Card.h"

Card::Card(int cardID, int answerNum, int* colorCode, RECT rcCard)
{
	_nCardID = cardID;
	_nAnswerNum = answerNum;

	_r = colorCode[0];
	_g = colorCode[1];
	_b = colorCode[2];

	_rcCard = rcCard;
	_isSelect = false;
	_isAnswer = false;
}

Card::~Card()
{

}

void Card::drawCard(HDC hdc)
{
	if (_isSelect || _isAnswer)
	{
		hbr = (HBRUSH)CreateSolidBrush(RGB(_r, _g, _b));
		hbrOld = (HBRUSH)::SelectObject(hdc, hbr);
		DrawRectMake(hdc, _rcCard);

		hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
		DeleteObject(hbr);
	}
	else
	{
		DrawRectMake(hdc, _rcCard);
	}
}

bool Card::isPointInRect()
{
	if ((_ptMouse.x > _rcCard.left && _ptMouse.x < _rcCard.right) || (_ptMouse.x > _rcCard.right && _ptMouse.x < _rcCard.left))
	{
		if ((_ptMouse.y > _rcCard.top && _ptMouse.y < _rcCard.bottom) || (_ptMouse.y < _rcCard.top && _ptMouse.y > _rcCard.bottom))
		{
			return true;
		}
	}

	return false;
}
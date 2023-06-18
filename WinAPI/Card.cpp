#include "Stdafx.h"
#include "Card.h"

Card::Card()
{
}

Card::Card(int cardID, int colorCode, int posX, int posY)
{
	_nCardID = cardID;
	_nColorCode = colorCode;

	_nPosX = posX;
	_nPosY = posY;
	_nWidth = 100;
	_nHeight = 150;

	_isSelect = false;
}

Card::~Card()
{
}

void Card::drawCard(HDC hdc)
{
	RectangleMake(hdc, _nPosX, _nPosY, _nWidth, _nHeight);
	wsprintf(str, "%d", _nColorCode);
	TextOut(hdc, _nPosX + _nWidth / 2, _nPosY + _nHeight / 2, str, strlen(str));

	//if (_isSelect || _isAnswer)
	//{
	//	hbr = (HBRUSH)CreateSolidBrush(RGB(_r, _g, _b));
	//	hbrOld = (HBRUSH)::SelectObject(hdc, hbr);
	//	DrawRectMake(hdc, _rcCard);

	//	hbr = (HBRUSH)::SelectObject(hdc, hbrOld);
	//	DeleteObject(hbr);
	//}
	//else
	//{
	//	DrawRectMake(hdc, _rcCard);
	//}
}

bool Card::isPointInRect()
{
	//if ((_ptMouse.x > _nPosX - _nWidth / 2 && _ptMouse.x < _nPosX + _nWidth / 2) || (_ptMouse.x > _nPosX + _nWidth / 2 && _ptMouse.x < _nPosX - _nWidth / 2))
	//{
	//	if ((_ptMouse.y > _nPosY - _nHeight / 2 && _ptMouse.y < _nPosY + _nHeight) || (_ptMouse.y < _nPosY - _nHeight && _ptMouse.y > _nPosY + _nHeight))
	//	{
	//		return true;
	//	}
	//}

	return false;
}
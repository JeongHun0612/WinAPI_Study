#pragma once

#define CARD_MAX		20

class Card
{
private:
	//HBRUSH hbr;
	//HBRUSH hbrOld;

	int _nCardID;
	int _nColorCode;
	char str[125];

	int _nPosX;
	int _nPosY;
	int _nWidth;
	int _nHeight;

	bool _isSelect;

public:
	Card();
	Card(int cardID, int colorCode, int posX, int posY);
	~Card();

	//RECT getRect() { return _rcCard; }

	int getCardID() { return _nCardID; }

	//void setColor(int r, int g, int b) { hbr = (HBRUSH)CreateSolidBrush(RGB(r, g, b)); }

	void setSelect(bool isSelect) { _isSelect = isSelect; }

	void drawCard(HDC hdc);

	bool isPointInRect();


};


#pragma once
class Card
{
private:
	int _nCardID;
	int _nAnswerNum;
	int _r, _g, _b;
	RECT _rcCard;

	HBRUSH hbr;
	HBRUSH hbrOld;

	bool _isSelect;
	bool _isAnswer;

public:
	Card() {};
	Card(int cardID, int answerNum, int* colorCode, RECT rcCard);
	~Card();


	RECT getRect() { return _rcCard; }

	int getAnswerNum() { return _nAnswerNum; }
	int getCardID() { return _nCardID; }

	void setColor(int r, int g, int b) { hbr = (HBRUSH)CreateSolidBrush(RGB(r, g, b)); }

	void setSelect(bool isSelect) { _isSelect = isSelect; }
	void setAnswer(bool isAnswer) { _isAnswer = isAnswer; }


	void drawCard(HDC hdc);
	bool isPointInRect();


};


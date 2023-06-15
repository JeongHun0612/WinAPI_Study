#pragma once
#include "Report_06_GameNode.h"
#include "Card.h"

#define CARD_COL		4
#define CARD_ROW		5

class Report_06_MainGame : public Report_06_GameNode
{
private:
	Card _Card[20];
	HBRUSH hbr;
	HBRUSH hbrOld;
	char str[125];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_06_MainGame() {}
	~Report_06_MainGame() {}
};


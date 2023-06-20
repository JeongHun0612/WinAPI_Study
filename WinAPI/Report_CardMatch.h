#pragma once
#include "Report_MainGame.h"
#include "Card.h"

class Report_CardMatch : public Report_MainGame
{
private:
	Card _Card[CARD_MAX];
	char str[125];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_CardMatch() {}
	~Report_CardMatch() {}
};

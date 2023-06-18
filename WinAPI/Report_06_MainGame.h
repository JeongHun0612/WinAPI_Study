#pragma once
#include "GameNode.h"
#include "Card.h"

class Report_06_MainGame : public GameNode
{
private:
	Card _Card[CARD_MAX];
	char str[125];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_06_MainGame() {}
	~Report_06_MainGame() {}
};


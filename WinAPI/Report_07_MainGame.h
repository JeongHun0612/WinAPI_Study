#pragma once
#include "GameNode.h"
#include "Mole.h"

#define CREATE_CYCLE		2

class Report_07_MainGame : public GameNode
{
private:
	Mole* _Mole[MAX_MOLE];
	clock_t _tCreateCycle;

	char _ScoreStr[256];
	int _nScore;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_07_MainGame() {}
	~Report_07_MainGame() {}
};


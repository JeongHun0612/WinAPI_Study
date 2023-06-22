#pragma once
#include "Report_MainGame.h"
#include "Mole.h"

#define CREATE_CYCLE		1

class Report_Mole : public Report_MainGame
{
private:
	GImage* _bgImage;

	Mole* _Mole[MAX_MOLE];
	clock_t _tCreateCycle;

	char _ScoreStr[256];
	int _nScore;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_Mole() {}
	~Report_Mole() {}
};


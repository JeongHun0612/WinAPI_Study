#pragma once
#include "Report_MainGame.h"
#include "Target.h"

#define TARGET_MAX		5

class Report_ClayShooting : public Report_MainGame
{
private:
	int _nGameTime;
	int _nDeltaTime;

	int _nScore;
	
	char _cTimer[125];
	char _cScore[125];

	Target* _Target[TARGET_MAX];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	bool getTimeOver();

	Report_ClayShooting() {}
	~Report_ClayShooting() {}
};


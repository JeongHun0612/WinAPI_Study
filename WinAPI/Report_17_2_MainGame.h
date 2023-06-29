#pragma once
#include "GameNode.h"

#define MAX_MOTION		10

struct Button
{
	int idx;
	char name[128];
	RECT rc;
};

class Report_17_2_MainGame : public GameNode
{
private:
	Button _MotionBtn[MAX_MOTION];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_17_2_MainGame() {}
	~Report_17_2_MainGame() {}
};


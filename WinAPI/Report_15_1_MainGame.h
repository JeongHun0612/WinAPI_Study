#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define PI 3.141592653f

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

struct Timer
{
	int x;
	int y;
};

class Report_15_1_MainGame : public GameNode
{
private:
	HPEN _pen;
	HPEN _currentPen;

	Timer _hour;
	Timer _minute;
	Timer _second;

	int _radius;

	SYSTEMTIME _st;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_15_1_MainGame() {}
	~Report_15_1_MainGame() {}
};


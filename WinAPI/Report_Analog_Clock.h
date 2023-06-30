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

class Report_Analog_Clock : public GameNode
{
private:
	HPEN _pen;
	HPEN _currentPen;

	Timer _hour[12];
	Timer _minute[60];
	Timer _second[60];

	int _radius;

	SYSTEMTIME _st;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_Analog_Clock() {}
	~Report_Analog_Clock() {}
};


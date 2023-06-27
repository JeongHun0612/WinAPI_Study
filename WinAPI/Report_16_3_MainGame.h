#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define MAX_WORM		30
#define PI 3.141592653f

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

struct tagWorm
{
	RECT rc;
	POINT centerPos;
	int radius;
	float angle;
	float speed;
};

class Report_16_3_MainGame : public GameNode
{
private:
	tagWorm _worms[MAX_WORM];

	float rotPosX;
	float rotPosY;
	float rotAngle;

public:
	HRESULT init();
	void release(void);
	void update(void);
	void render(HDC hdc);
};


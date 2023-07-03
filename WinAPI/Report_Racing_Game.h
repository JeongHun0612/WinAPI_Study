#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

#define		MAX_SPEED	50
#define		MIN_SPEED	10

class Report_Racing_Game : public GameNode
{
private:
	short _offsetY;
	float _speed;

	bool _isAccel;

public:
	HRESULT init();
	void release(void);
	void update(void);
	void render(void);
};


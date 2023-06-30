#pragma once

#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

// 상수화
#define PI 3.141592653f

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

struct STAR
{
	int x;
	int y;
};

class Example_Math : public GameNode
{
private:
	float _radian;
	float _degree;

	// 시간 관련 구조체
	SYSTEMTIME _st;

	HPEN _currentStarPen;
	STAR _star[5];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Example_Math() {}
	~Example_Math() {}
};


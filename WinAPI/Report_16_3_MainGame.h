#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define MAX_WORM		50

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

class Report_16_3_MainGame : public GameNode
{
public:
	struct tagWorm
	{
		int id;
		float x, y;
		float radius;
		COLORREF color;
	};

	struct tagItem
	{
		RECT rc;
		int x, y;
		int id;
	};

private:
	tagWorm _worms[MAX_WORM];
	tagItem _item;

	float angle;
	float speed;

	int count;

	char strId[10];

public:
	HRESULT init();
	void release(void);
	void update(void);
	void render(void);
};


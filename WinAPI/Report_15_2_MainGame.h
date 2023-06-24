#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define PI 3.141592653f

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

struct tagBullet
{
	float centerX;
	float centerY;

	int angle;
	int radius;
	int diameter;
	int moveX;
	int moveY;
	float speed;

	RECT rc;
};

class Report_15_2_MainGame : public GameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _vBulletIter;

	int _currentAngle;
	int _radius;
	int _move;

	bool _bIsAuto;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_15_2_MainGame() {}
	~Report_15_2_MainGame() {}
};


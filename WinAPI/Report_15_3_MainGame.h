#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define PI 3.141592653f

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)


class Report_15_3_MainGame : public GameNode
{
public:
	struct tagBullet
	{
		RECT rc;
		int _angle;
		int _moveX;
		int _moveY;
		float _speed;
	};

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

	Report_15_3_MainGame() {}
	~Report_15_3_MainGame() {}
};


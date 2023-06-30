#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define PI 3.141592653f

// ���� ǥ�� -> ���� ǥ�� ��ȯ
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

class Report_Bullet_Gravity : public GameNode
{
public:
	struct tagBullet
	{
		float centerX;
		float centerY;

		int angle;
		int radius;
		int moveX;
		int moveY;
		float speed;

		RECT rc;
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
	void render(void);

	Report_Bullet_Gravity() {}
	~Report_Bullet_Gravity() {}
};


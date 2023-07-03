#pragma once
#include "GameNode.h"

#define _USE_MATH_DEFINES
#include <math.h>

// 각도 표기 -> 라디안 표기 변환
#define DEGREE_RADIAN(_deg)			(M_PI * (_deg) / 180.f)

#define		MAX_SPEED	40
#define		MIN_SPEED	10
#define		MAX_ENEMY	3

class Report_Racing_Game : public GameNode
{
public:
	struct Player
	{
		int width;
		int height;
		int alpha;

		float speed;
		float currentDist;

		bool isAccel;
		bool isInvincible;

		RECT rc;
	};

	struct Enemy
	{
		int width;
		int height;
		float speed;
		int maxSpeed;
		float currentDist;

		RECT rc;
	};

private:
	Player _player;
	Enemy _enemy[MAX_ENEMY];

	int _count;
	int _index;
	int _offsetY;

	bool _isStart;
	bool _isColliderShow;


public:
	HRESULT init();
	void release(void);
	void update(void);
	void render(void);

	Report_Racing_Game() {}
	~Report_Racing_Game() {}
};


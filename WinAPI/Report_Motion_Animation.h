#pragma once
#include "GameNode.h"

#define MAX_MOTION		10

enum class EMOTION_TYPE
{
	IDLE,
	MOVE,
	STING,
	DIAGONAL_STING,
	DPUBLE_STING,
	TURN_CIRCLE,
	VICTORY,
	LOSE,
	SKILL
};

struct Button
{
	int idx;
	char name[128];
	RECT rc;
};

struct Motion
{
	int x, y;
	GImage* motion;
};

class Report_Motion_Animation : public GameNode
{
private:
	Button _motionBtn[MAX_MOTION];
	Motion _motionImage[MAX_MOTION];

	GImage* _skillScene;
	int _skillSceneX;
	int _skillSceneY;

	EMOTION_TYPE _motionType;

	int _count, _index;
	int _currentIdx;
	int _alpha;

	bool _isLeft;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_Motion_Animation() {}
	~Report_Motion_Animation() {}
};


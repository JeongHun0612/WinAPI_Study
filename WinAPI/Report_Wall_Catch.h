#pragma once
#include "GameNode.h"

#define		MAX_ANIMATION		3

class Report_Wall_Catch : public GameNode
{
public:
	enum EState : int
	{
		IDLE,
		MOVE,
		JUMP
	};

	struct Animation
	{
		GImage* frameImage;
		int frameChangeCnt;
	};

	struct Player
	{
		Animation anim[MAX_ANIMATION];
		EState state;

		float x, y;
		bool isLeft;
		bool isJump;
		bool isJumpped;
	};

private:
	Player _player;

	int _count;
	int _index;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};


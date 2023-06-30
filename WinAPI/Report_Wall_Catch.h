#pragma once
#include "GameNode.h"

class Report_Wall_Catch : public GameNode
{
public:
	enum class EState : int
	{
		IDLE,
		MOVE,
		JUMP
	};

	struct Animation
	{
		int count;
	};

	struct Player
	{
		GImage* _img;
		EState _state;
		bool _isLeft;
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


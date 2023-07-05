#pragma once
#include "GameNode.h"

class Report_Attack_Defense : public GameNode
{
public:
	enum class PLAYER_DIRECTION
	{
		NONE,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	struct Player
	{
		int x, y;

		RECT rc;
		GImage* headImg;
		GImage* bodyImg;

		PLAYER_DIRECTION curDirection;

		bool isMove;
	};

private:
	Player _player;

	int _count;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void moveAction(PLAYER_DIRECTION direction);

	Report_Attack_Defense() {}
	~Report_Attack_Defense() {}
};


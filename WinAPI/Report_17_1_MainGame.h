#pragma once
#pragma once
#include "GameNode.h"

enum class EPLAYER_STATE
{
	IDLE,
	ATTACK
};

struct Animaion
{
	int maxFrameX;
	int maxFrameY;

	EPLAYER_STATE state;
	GImage* image;

	int count;
	int index;
};

class Report_17_1_MainGame : public GameNode
{
private:
	Animaion _idle;
	Animaion _attack1;

	EPLAYER_STATE _currentState;

	int _count;
	int _index;

	bool _isLeft;
	bool _isAttack;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_17_1_MainGame() {}
	~Report_17_1_MainGame() {}
};


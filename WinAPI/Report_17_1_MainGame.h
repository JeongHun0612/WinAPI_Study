#pragma once
#pragma once
#include "GameNode.h"

struct Animaion
{
	int maxFrameX;
	int maxFrameY;

	GImage* image;

	int count;
	int index;
};

class Report_17_1_MainGame : public GameNode
{
private:
	Animaion _idle;

	Animaion _attack1;
	Animaion _attack2;
	Animaion _attack3;

	int _attackIndex;

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


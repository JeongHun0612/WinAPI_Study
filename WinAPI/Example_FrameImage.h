#pragma once
#include "GameNode.h"

class Example_FrameImage : GameNode
{
private:
	GImage* _loading;

	int _alphaA;
	int _count;
	int _index;

	bool _isLeft;
	bool _isAlphaIncrease;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};


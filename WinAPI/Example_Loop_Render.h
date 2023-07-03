#pragma once
#include "GameNode.h"

class Example_Loop_Render : public GameNode
{
private:
	int _offsetX;
	int _offsetY;

	int _bgSpeed;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};


#pragma once
#include "GameNode.h"

class SecondScene : public GameNode
{
private:


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	SecondScene() {}
	~SecondScene() {}
};


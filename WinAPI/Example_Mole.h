#pragma once
#include "GameNode.h"
class Example_Mole : public GameNode
{
private:
	RECT rc;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Example_Mole() {}
	~Example_Mole() {}
};


#pragma once
#include "GameNode.h"

class Example_INIData : public GameNode
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Example_INIData() {}
	~Example_INIData() {}
};


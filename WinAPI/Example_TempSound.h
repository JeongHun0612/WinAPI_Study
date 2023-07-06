#pragma once
#include "GameNode.h"

class Example_TempSound : public GameNode
{
public:
	HRESULT init(void);
	void update(void);

	Example_TempSound() {}
	~Example_TempSound() {}
};


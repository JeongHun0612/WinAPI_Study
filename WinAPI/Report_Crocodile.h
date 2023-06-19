#pragma once
#include "GameNode.h"

class Report_Crocodile : public GameNode
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_Crocodile() {}
	~Report_Crocodile() {}
};


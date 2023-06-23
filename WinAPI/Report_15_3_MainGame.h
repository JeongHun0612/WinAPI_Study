#pragma once
#include "GameNode.h"

class Report_15_3_MainGame : public GameNode
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_15_3_MainGame() {}
	~Report_15_3_MainGame() {}
};


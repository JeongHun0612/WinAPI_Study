#pragma once
#include "GameNode.h"

class Report_15_4_MainGame : public GameNode
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_15_4_MainGame() {}
	~Report_15_4_MainGame() {}
};


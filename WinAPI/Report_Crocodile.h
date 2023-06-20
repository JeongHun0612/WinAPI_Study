#pragma once
#include "Report_MainGame.h"

class Report_Crocodile : public Report_MainGame
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


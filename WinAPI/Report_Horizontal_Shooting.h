#pragma once
#include "Report_MainGame.h"

class Report_Horizontal_Shooting : public Report_MainGame
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	bool isGameOver(void);

	Report_Horizontal_Shooting() {}
	~Report_Horizontal_Shooting() {}
};


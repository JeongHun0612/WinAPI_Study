#pragma once
#include "Report_MainGame.h"

class Report_Mole_Image : public Report_MainGame
{
private:
	GImage* _holeImage;
	GImage* _moleImage;





public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_Mole_Image() {}
	~Report_Mole_Image() {}
};


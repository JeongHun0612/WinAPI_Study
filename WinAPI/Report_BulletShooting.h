#pragma once
#include "Report_MainGame.h"

class Report_BulletShooting : public Report_MainGame
{
private:
	int _posX;

	vector<RECT> _vBullet;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_BulletShooting() {}
	~Report_BulletShooting() {}
};


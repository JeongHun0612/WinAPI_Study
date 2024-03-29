#pragma once
#include "GameNode.h"

class Report_BulletShooting : public GameNode
{
private:
	int _posX;

	vector<RECT> _vBullet;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_BulletShooting() {}
	~Report_BulletShooting() {}
};


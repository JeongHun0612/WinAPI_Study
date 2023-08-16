#pragma once
#include "Bullets.h"

class ShotMissile : public Missile
{
private:
	bool _isTest;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	ShotMissile() {}
	~ShotMissile() {}
};

#pragma once
#include "Bullets.h"

class NormalMissile : public Missile
{
private:

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	NormalMissile() {}
	~NormalMissile() {}
};

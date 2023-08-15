#pragma once
#include "Bullets.h"

class MiniRocket : public Missile
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

	MiniRocket() {}
	~MiniRocket() {}
};


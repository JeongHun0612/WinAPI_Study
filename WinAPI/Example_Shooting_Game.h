#pragma once
#include "GameNode.h"
#include "Rocket.h"

class Example_Shooting_Game : public GameNode
{
private:
	Rocket* _rocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Example_Shooting_Game() {}
	~Example_Shooting_Game() {}
};


#pragma once
#include "GameNode.h"
#include "Rocket.h"
#include "EnemyManager.h"

class Example_Shooting_Game : public GameNode
{
private:
	Rocket* _rocket;
	EnemyManager* _em;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void collision(void);

	Example_Shooting_Game() {}
	~Example_Shooting_Game() {}
};



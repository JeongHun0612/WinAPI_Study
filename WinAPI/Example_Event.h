#pragma once
#include "GameNode.h"

#include "Player_Event.h"
#include "Boss_Event.h"

class Example_Event : public GameNode
{
private:
	EventPublisher eventManager;

	Player_Event _player;
	Boss_Event _boss;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Example_Event() {}
	~Example_Event() {}
};


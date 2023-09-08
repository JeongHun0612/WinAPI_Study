#pragma once
#include "EventListener.h"
#include "EventPublisher.h"
#include "CustomEvent.h"

class Player_Event : public EventListener
{
private:
	EventPublisher eventPublisher;

public:
	void attackBoss()
	{
		CustomEvent attackEvent(10);
		eventPublisher.notify(attackEvent);
	}

	void handleEvent(const Event& event) override
	{
		cout << "Player Handle Event" << endl;
	}

	void setEventPublisher(EventPublisher& publisher)
	{
		eventPublisher = publisher;
	}


	Player_Event() {}
	~Player_Event() {}
};


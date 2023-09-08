#pragma once
#include "EventListener.h"
#include <deque>

class EventPublisher
{
private:
	vector<EventListener*> listerners;

public:
	void addListener(EventListener* listener)
	{
		listerners.push_back(listener);
	}

	void removeListener(EventListener* listener)
	{

	}

	void notify(const Event& event)
	{
		for (EventListener* listener : listerners)
		{
			listener->handleEvent(event);
		}
	}

	EventPublisher() {}
	~EventPublisher() {}
};


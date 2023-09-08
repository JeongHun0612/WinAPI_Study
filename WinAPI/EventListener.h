#pragma once

class Event;

class EventListener
{
public:
	virtual void handleEvent(const Event& event) = 0;
};


#pragma once
#include "Event.h"

class CustomEvent : public Event
{
public:
	int _data;

	CustomEvent(int data) : _data(data) {}
};


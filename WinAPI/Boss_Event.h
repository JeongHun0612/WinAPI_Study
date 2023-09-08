#pragma once
#include "EventListener.h"
#include "CustomEvent.h"

class Boss_Event : public EventListener
{
private:
	int hp;

public:
	void handleEvent(const Event& event) override
	{
		if (typeid(event) == typeid(CustomEvent))
		{
			const CustomEvent& customEvent = static_cast<const CustomEvent&>(event);
			int damage = customEvent._data;

			cout << "Boss takes : " << damage << endl;
		}
	}

	Boss_Event() {}
	~Boss_Event() {}
};


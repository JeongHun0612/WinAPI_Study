#include "Stdafx.h"
#include "Example_Event.h"

HRESULT Example_Event::init(void)
{
	eventManager.addListener(&_player);
	eventManager.addListener(&_boss);

	return S_OK;
}

void Example_Event::release(void)
{
}

void Example_Event::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_player.attackBoss();
	}
}

void Example_Event::render(void)
{
}

#include "Stdafx.h"
#include "MouseManager.h"

HRESULT MouseManager::init(void)
{
	return S_OK;
}

bool MouseManager::isOnceMouseDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!this->getMouseDown())
		{
			this->setMouseDown(true);
			return true;
		}
	}
	else
	{
		this->setMouseDown(false);
	}

	return false;
}

bool MouseManager::isOnceMouseUp(int key)
{
	return false;
}


bool MouseManager::isStayMouseDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		return true;
	}

	return false;
}
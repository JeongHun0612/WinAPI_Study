#include "Stdafx.h"
#include "EventManager.h"

HRESULT EventManager::init(void)
{
	return S_OK;
}

void EventManager::release(void)
{
}

void EventManager::update(void)
{
	for (_viEventHandler = _vEventHandler.begin(); _viEventHandler != _vEventHandler.end(); ++_viEventHandler)
	{
		
	}
}

void EventManager::render(HDC hdc)
{
	for (_viEventHandlerRender = _vEventHandlerRender.begin(); _viEventHandlerRender != _vEventHandlerRender.end(); ++_viEventHandlerRender)
	{
		(*_viEventHandlerRender)(hdc);
	}
}

void EventManager::addEventHandler(EventHandler handler)
{
	_vEventHandler.push_back(handler);
}

void EventManager::addRenderEventHandler(EventHandlerRender handler)
{
	_vEventHandlerRender.push_back(handler);
}

void EventManager::addEventHandler(const char* eventName, EventHandler handler)
{
	cout << "add EventHandler" << endl;
	eventHandlers[eventName] = handler;
}

void EventManager::removeEventHandler(string keyName)
{
}

void EventManager::removeRenderEventHandler(string keyName)
{
}

void EventManager::excute(const char* eventName)
{
	auto iter = eventHandlers.find(eventName);

	if (iter != eventHandlers.end())
	{
		iter->second;
	}
	else
	{
		cout << "Event not found" << endl;
	}
}
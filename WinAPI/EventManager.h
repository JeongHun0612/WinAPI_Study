#pragma once
#include "SingletonBase.h"

using EventHandler = function<void()>;
using EventHandlerRender = function<void(HDC hdc)>;

class EventManager : public SingletonBase<EventManager>
{
private:
	vector<EventHandler> _vEventHandler;
	vector<EventHandler>::iterator _viEventHandler;

	vector<EventHandlerRender> _vEventHandlerRender;
	vector<EventHandlerRender>::iterator _viEventHandlerRender;

	unordered_map<string, EventHandler> eventHandlers;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	void addEventHandler(EventHandler handler);
	void addRenderEventHandler(EventHandlerRender handler);
	void addEventHandler(const char* eventName, EventHandler handler);

	void removeEventHandler(string keyName);
	void removeRenderEventHandler(string keyName);

	void excute(const char* eventName);
};


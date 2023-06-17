#pragma once
#include "SingletonBase.h"

class MouseManager : public SingletonBase <MouseManager>
{
private:
	bool _mouseUp;
	bool _mouseDown;

public:
	HRESULT init(void);

	bool isOnceMouseDown(int key);
	bool isOnceMouseUp(int key);
	bool isStayMouseDown(int key);

	bool getMouseUp(void) { return _mouseUp; }
	bool getMouseDown(void) { return _mouseDown; }

	void setMouseUp(bool state) { _mouseUp = state; }
	void setMouseDown(bool state) { _mouseDown = state; }

	MouseManager() {}
	~MouseManager() {}
};


#include "Stdafx.h"
#include "Example_Loop_Render.h"

HRESULT Example_Loop_Render::init(void)
{
	IMAGEMANAGER->addImage("bg_loop", "Resources/Images/Background/Loop_bg.bmp", 1570, WINSIZE_Y);

	_offsetX = _offsetY = 0;
	_bgSpeed = 0;

	return S_OK;
}

void Example_Loop_Render::release(void)
{
	IMAGEMANAGER->deleteImage("bg_loop");
}

void Example_Loop_Render::update(void)
{
	_bgSpeed += 4;
}

void Example_Loop_Render::render(void)
{
	IMAGEMANAGER->loopRender("bg_loop", getMemDC(),
		&RectMake(0, 0, WINSIZE_X, WINSIZE_Y),
		_bgSpeed, _offsetY);
}


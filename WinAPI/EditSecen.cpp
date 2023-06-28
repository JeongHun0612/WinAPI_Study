#include "Stdafx.h"
#include "EditSecen.h"

HRESULT EditSecen::init(void)
{
    return E_NOTIMPL;
}

void EditSecen::relase(void)
{
}

void EditSecen::update(void)
{
}

void EditSecen::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);


	this->getDoubleBuffer()->render(hdc, 0, 0);
}

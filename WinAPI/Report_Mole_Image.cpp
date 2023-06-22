#include "Stdafx.h"
#include "Report_Mole_Image.h"

HRESULT Report_Mole_Image::init(void)
{
	_holeImage = new GImage;
	_holeImage->init("Resources/Images/Object/Hole.bmp", 54, 68, true, RGB(255, 0, 255));

	_moleImage = new GImage;
	_moleImage->init("Resources/Images/Object/Mole.bmp", 54, 68, true, RGB(255, 0, 255));


	return S_OK;
}

void Report_Mole_Image::release(void)
{
	SAFE_DELETE(_holeImage);
	SAFE_DELETE(_moleImage);
}

void Report_Mole_Image::update(void)
{
}

void Report_Mole_Image::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ==========================================================

	_holeImage->render(memDC, 54, 68);
	_moleImage->render(memDC, 54, 68);

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

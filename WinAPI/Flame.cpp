#include "Stdafx.h"
#include "Flame.h"

HRESULT Flame::init(RECT* rc)
{
	_image = IMAGEMANAGER->addFrameImage("ÇÃ·¹ÀÓ", "Resources/Images/ShootingGame/Flame.bmp", 468, 128, 9, 1, true, RGB(255, 0, 255));
	_rc = rc;

	_count = 0;
	_index = 0;

	return S_OK;
}

void Flame::release(void)
{
}

void Flame::update(void)
{
	_count++;

	if (_count % 5 == 0)
	{
		_index++;

		if (_image->getFrameX() == _image->getMaxFrameX())
		{
			_index = 0;
			_image->setFrameX(_index);
		}
		else
		{
			_image->setFrameX(_index);
		}
	}
}

void Flame::render(void)
{
	_image->frameRender(getMemDC(), _rc->left, _rc->bottom, _image->getFrameX(), _image->getFrameY());
}

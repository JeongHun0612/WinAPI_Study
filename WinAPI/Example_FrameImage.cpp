#include "Stdafx.h"
#include "Example_FrameImage.h"

HRESULT Example_FrameImage::init(void)
{
	_loading = new GImage;
	_loading->init("Resources/Images/Object/zero_loading.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		640, 240,
		8, 2,
		true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("데스 스페이스", "Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_alphaA = 0;
	_count = _index = 0;

	_isLeft = false;
	_isAlphaIncrease = false;

    return S_OK;
}

void Example_FrameImage::release(void)
{
	SAFE_DELETE(_loading);
}

void Example_FrameImage::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		_loading->setX(_loading->getX() - 8.0f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		_loading->setX(_loading->getX() + 8.0f);
	}

	if (_isLeft)
	{
		_count++;

		_loading->setFrameY(1);

		if (_count % 3 == 0)
		{
			_index--;

			if (_index < 0)
			{
				_index = 10;
			}

			_loading->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_loading->setFrameY(0);

		if (_count % 2 == 0)
		{
			_index++;

			if (_index > 10)
			{
				_index = 0;
			}

			_loading->setFrameX(_index);
		}
	}
}

void Example_FrameImage::render(void)
{
	IMAGEMANAGER->render("데스 스페이스", getMemDC(), 0, 0);

	_loading->frameRender(getMemDC(), _loading->getX(), _loading->getY());
}

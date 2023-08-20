#include "Stdafx.h"
#include "Example_Tengai.h"

HRESULT Example_Tengai::init(void)
{
	_bgImg[0].img = IMAGEMANAGER->addImage("bg_loop1", "Resources/Images/Tengai/background1.bmp", 0.0f, 0.0f, 1902, 400);
	_bgImg[1].img = IMAGEMANAGER->addImage("bg_loop2", "Resources/Images/Tengai/background2.bmp", 0.0f, 400.0f, 1902, 200);
	_bgImg[2].img = IMAGEMANAGER->addImage("bg_loop3", "Resources/Images/Tengai/background3.bmp", 0.0f, 600.0f, 1902, 235, true, RGB(255, 0, 255));

	_bgImg[0].rc = RectMake(0, 0, WINSIZE_X, 400);
	_bgImg[1].rc = RectMake(0, 400, WINSIZE_X, 200);
	_bgImg[2].rc = RectMake(0, 565, WINSIZE_X, 235);


	_testImg = IMAGEMANAGER->addImage("test", "Resources/Images/Tengai/MiniHealerBG.bmp", WINSIZE_X, WINSIZE_Y);


	return S_OK;
}

void Example_Tengai::release(void)
{
	for (int i = 0; i < 3; i++)
	{
		SAFE_DELETE(_bgImg[i].img);
	}
}

void Example_Tengai::update(void)
{
	_bgImg[0].offsetX += 0.2f;
	_bgImg[1].offsetX += 0.5f;
	_bgImg[2].offsetX += 2.0f;

	_frameCnt += TIMEMANAGER->getElapsedTime();

	if (_frameCnt >= 0.3f)
	{
		if (_testImg->getFrameX() == _testImg->getMaxFrameX())
		{
			_testImg->setFrameX(0);
		}
		else
		{
			_testImg->setFrameX(_testImg->getFrameX() + 1);
		}

		_frameCnt = 0.0f;
	}
}

void Example_Tengai::render(void)
{
	_testImg->render(getMemDC());

	//for (int i = 0; i < 3; i++)
	//{
	//	_bgImg[i].img->loopRender(getMemDC(), &_bgImg[i].rc, _bgImg[i].offsetX, _bgImg[i].offsetY);

	//}
}

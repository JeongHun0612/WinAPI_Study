#include "Stdafx.h"
#include "Report_Racing_Game.h"

HRESULT Report_Racing_Game::init()
{
	IMAGEMANAGER->addImage("background", "Resources/Images/RacingGame/background.bmp", 840, WINSIZE_Y + 100);

	IMAGEMANAGER->addImage("meterboard", "Resources/Images/RacingGame/meterboard.bmp",  WINSIZE_X - 300.0f, WINSIZE_Y - 300.0f, 300, 300, true, RGB(182, 185, 183));

	IMAGEMANAGER->addImage("player", "Resources/Images/RacingGame/player.bmp", 84, 98, true, RGB(182, 185, 183));
	IMAGEMANAGER->findImage("player")->setX(IMAGEMANAGER->findImage("background")->getWidth() / 2 + IMAGEMANAGER->findImage("player")->getWidth() / 2 - 15);
	IMAGEMANAGER->findImage("player")->setY(WINSIZE_Y - IMAGEMANAGER->findImage("player")->getHeight() - 50);

	_offsetY = 0;
	_speed = 10.0f;

	_isAccel = false;

	return S_OK;
}

void Report_Racing_Game::release(void)
{
}

void Report_Racing_Game::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _speed < MAX_SPEED)
	{
		_isAccel = true;
		_speed+=0.2f;

		if (_speed > MAX_SPEED)
		{
			_speed = MAX_SPEED;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _speed > MIN_SPEED)
	{
		_speed -= 0.3f;

		if (_speed < MIN_SPEED)
		{
			_speed = MIN_SPEED;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		IMAGEMANAGER->findImage("player")->setX(IMAGEMANAGER->findImage("player")->getX() - 137.0f);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		IMAGEMANAGER->findImage("player")->setX(IMAGEMANAGER->findImage("player")->getX() + 137.0f);
	}

	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isAccel = false;
	}

	if (!_isAccel && _speed > MIN_SPEED)
	{
		_speed -= 0.1f;

		if (_speed < MIN_SPEED)
		{
			_speed = MIN_SPEED;
		}
	}

	_offsetY -= _speed;

	cout << _speed << endl;
}

void Report_Racing_Game::render(void)
{
	// 배경
	IMAGEMANAGER->loopRender("background", getMemDC(), &RectMake(0, 0, 840, WINSIZE_Y), 0, _offsetY);

	// 플레이어
	IMAGEMANAGER->render("player", getMemDC(),
		IMAGEMANAGER->findImage("player")->getX(),
		IMAGEMANAGER->findImage("player")->getY()
	);

	// 계기판
	IMAGEMANAGER->render("meterboard", getMemDC(),
		IMAGEMANAGER->findImage("meterboard")->getX(),
		IMAGEMANAGER->findImage("meterboard")->getY()
	);

	// 속도계
	LineMake(getMemDC(),
		IMAGEMANAGER->findImage("meterboard")->getX() + IMAGEMANAGER->findImage("meterboard")->getWidth() / 2,
		IMAGEMANAGER->findImage("meterboard")->getY() + IMAGEMANAGER->findImage("meterboard")->getHeight() / 2,
		IMAGEMANAGER->findImage("meterboard")->getX() + IMAGEMANAGER->findImage("meterboard")->getWidth() / 2 +  cosf(DEGREE_RADIAN(_speed * 6 + 105)) * 100.0f,
		IMAGEMANAGER->findImage("meterboard")->getY() + IMAGEMANAGER->findImage("meterboard")->getHeight() / 2 +  sinf(DEGREE_RADIAN(_speed * 6 + 105)) * 100.0f);
}

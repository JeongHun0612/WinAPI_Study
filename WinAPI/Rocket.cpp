#include "Stdafx.h"
#include "Rocket.h"

// 설계와의 싸움
HRESULT Rocket::init()
{
	// 객체의 의한 매니저할당
	_image = IMAGEMANAGER->addImage("로켓", "Resources/Images/ShootingGame/Rocket.bmp", 52, 64, true, RGB(255, 0, 255));

	_x = WINSIZE_X_HALF;
	_y = WINSIZE_Y_HALF;

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

	_flame = new Flame;
	_flame->init("Flame.bmp", & _x, &_y);

	_missile.init(5, 300);

	//std::shared_ptr<Rocket> PlayerA = std::make_shared<Rocket>();
	//std::shared_ptr<Rocket> PlayerB = PlayerA->get_shared_ptr();

	//PlayerA.use_count();

	// 좀 더 효율적인 방법
	//spRocket.push_back(std::shared_ptr<Rocket>(new Rocket));

	return S_OK;
}

void Rocket::release(void)
{
	_flame->release();
	SAFE_DELETE(_flame);

	_missile.release();
}

void Rocket::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left > 0)
	{
		_x -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X)
	{
		_x += ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top > 0)
	{
		_y -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom < WINSIZE_Y)
	{
		_y += ROCKET_SPEED;
	}

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		// fire
		_missile.fire(_x, _y);
	}

	_flame->update();

	_missile.update();
}

void Rocket::render(void)
{
	_image->render(getMemDC(), _rc.left, _rc.top);
	_flame->render();

	_missile.render();
}

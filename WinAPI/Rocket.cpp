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
    _flame->init(&_rc);

    return S_OK;
}

void Rocket::release(void)
{
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

    _flame->update();

    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {
        // fire
    }
}

void Rocket::render(void)
{
    _image->render(getMemDC(), _rc.left, _rc.top);
    _flame->render();
}

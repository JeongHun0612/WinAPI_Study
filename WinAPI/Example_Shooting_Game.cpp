#include "Stdafx.h"
#include "Example_Shooting_Game.h"

/*
과제1. 로켓에 Flame 이미지 추가

- Flame 이미지는 프레임으로 렌더를 시킨다.

※ Flame 클래스에는 로켓에 대한 정보가 있으면 안되며 MainGame 또한 Flame에 대한 정보를 알 필요가 없다.

과제 2. 로켓 미사일 발사

- 미완성 함수를 완성하고 로켓이 미사일을 발사한다.

- 당연히 미사일 이미지는 프레임으로 출력
*/

HRESULT Example_Shooting_Game::init(void)
{
	IMAGEMANAGER->addImage("슈팅 맵", "Resources/Images/ShootingGame/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_rocket = new Rocket;

	_rocket->init();

	return S_OK;
}

void Example_Shooting_Game::release(void)
{
	_rocket->release();
}

void Example_Shooting_Game::update(void)
{
	_rocket->update();
}

void Example_Shooting_Game::render(void)
{
	IMAGEMANAGER->findImage("슈팅 맵")->render(getMemDC());

	_rocket->render();
}

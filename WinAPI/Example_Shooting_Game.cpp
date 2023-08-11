#include "Stdafx.h"
#include "Example_Shooting_Game.h"

/*

[08/10]
과제1. 로켓에 Flame 이미지 추가

- Flame 이미지는 프레임으로 렌더를 시킨다.

※ Flame 클래스에는 로켓에 대한 정보가 있으면 안되며 MainGame 또한 Flame에 대한 정보를 알 필요가 없다.

[08/11]
과제 1. 로켓 미사일 발사

- 미완성 함수를 완성하고 로켓이 미사일을 발사한다.

- 당연히 미사일 이미지는 프레임으로 출력

과제 2. 팀 포트폴리오로 만들 게임 선정 임박

- 최종 후보군 3개 (2개)

과제 3. 타일맵 만들기

- 사용자가 입력한 숫자로 타일맵을 그린다. (최대 사이즈 : 100)
ㄴ EX : 20을 입력하면 20 X 20 사이즈의 타일이 화면에 그려진다.

- 타일맵안에는 랜덤한 위치에 이미지 2장이 들어간다.

- 이미지는 매번 타일맵을 새로 그려줄때마다 위치가 바껴야 하고 그려진 이미지는 마우스로 클릭할 수 있으며 위치 또한 변경할 수 있어야 한다.

필수 : STL 벡터
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

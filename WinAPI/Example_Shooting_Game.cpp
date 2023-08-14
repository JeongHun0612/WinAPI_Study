#include "Stdafx.h"
#include "Example_Shooting_Game.h"

/*
[08 / 13]

과제1. 로켓에 Flame 이미지 추가

- Flame 이미지는 프레임으로 렌더를 시킨다.

※ Flame 클래스에는 로켓에 대한 정보가 있으면 안되며 MainGame 또한 Flame에 대한 정보를 알 필요가 없다.

과제 2. 로켓 미사일 발사

- 미완성 함수를 완성하고 로켓이 미사일을 발사한다.

- 당연히 미사일 이미지는 프레임으로 출력


[08 / 14]

과제1. 움직이는 적 패턴 추가

- 움직임을 서로 다르게 해온다.
ㄴ 패턴은 총 3가지를 만들면 OK

과제2. 로켓 무장 변경 추가

- F1 : 일반 미사일

- F2 : 산탄

- F3 : 미니 로켓 생성

- F4 : 쉴드

- F5 : 유도 미사일

- F6 : 레이져

- F7 : 블랙홀
ㄴ 영향을 받는 적과 아닌 적으로 구분
ㄴ 블랙홀의 중점에 가까운 적일수록 스킬이 끝나면 튕겨 나가는 관성이 강해진다.

*/

HRESULT Example_Shooting_Game::init(void)
{
	IMAGEMANAGER->addImage("슈팅 맵", "Resources/Images/ShootingGame/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_rocket = new Rocket;

	_rocket->init();

	_em = new EnemyManager;
	_em->init();

	return S_OK;
}

void Example_Shooting_Game::release(void)
{
	_rocket->release();
	SAFE_DELETE(_rocket);

	_em->release();
	SAFE_DELETE(_em);
}

void Example_Shooting_Game::update(void)
{
	_rocket->update();
	_em->update();
}

void Example_Shooting_Game::render(void)
{
	IMAGEMANAGER->findImage("슈팅 맵")->render(getMemDC());

	_rocket->render();
	_em->render();
}

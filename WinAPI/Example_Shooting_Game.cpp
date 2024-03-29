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

[08 / 17]

과제 1. 미사일 충돌 처리

- 내가 발사한 미사일로 적을 제거한다.
ㄴ 본인이 생각한 가장 효율적인 (객체지향적인) 방법으로

과제 2. 체력 바 구현
- 로켓과 적의 체력바를 구현한다.

ㄴ 1. 체력바를 각각의 객체위에 띄어주는 방법
ㄴ 2. 적 객체 한정으로 체력바를 공유하는 방법

[08 / 18]

과제 1. 적이 죽을 때 이펙트 구현

- 무장마다 다른 이펙트로 구현

- 이펙트는 프레임 렌더 처리


과제 2. 적 미사일 발사

- 적이 미사일을 발사하며 미사일은 로켓의 위치로 쏴야 한다.

- 적이 발사하는 미사일은 발사 주기와 스피드가 모두 달라야 한다.


[08 / 23]

과제 1. 팀 포트폴리오 PPT 발표 준비
ㄴ 발표일 : 내일
ㄴ 발표자 준비

과제 2. 세미 포트폴리오 (장르 : 슈팅 게임)
ㄴ 27일 (일) 까지 -> 월요일 제출
ㄴ 새로운 이미지 필수 (1945, 동방 시리즈, 텐가이)
ㄴ 스타트 씬과 게임 씬 + 플레이어 선택 씬
ㄴ 적을 죽이면 점수 획득
ㄴ 파워에 따라 총알 모양 바꾸기
ㄴ 플레이어 -> 체력 / 라이프
ㄴ 적을 모두 죽이면 보스 출현 (보스 출현에 대해서는 자연스럽게)
ㄴ 적 2 + @ + 중간 보스 
ㄴ 보스를 죽이면 게임 루프를 다시 가능한 구조
*/

HRESULT Example_Shooting_Game::init(void)
{
	IMAGEMANAGER->addImage("슈팅 맵", "Resources/Images/ShootingGame/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_rocket = new Rocket;
	_rocket->init();

	_em = new EnemyManager;
	_em->init();

	_em->setRocketMemoryAddress(_rocket);
	_rocket->setEnemyManagerMemoryAddress(_em);

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

	//collision();
}

void Example_Shooting_Game::render(void)
{
	IMAGEMANAGER->findImage("슈팅 맵")->render(getMemDC());

	_rocket->render();
	_em->render();

	TIMEMANAGER->render(getMemDC());
}
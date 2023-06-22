#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

}

void MainGame::update(void)
{
	GameNode::update();

}

void MainGame::render(HDC hdc)
{
	
}

/*
이미지 추가 과제 1. 두더지 게임

- 상황에 맞는 이미지 필수적으로 적용한다.

- 두더지가 없을 때 / 나왔을 때 / 때렸을 때 / 망치 (대기, 때렸을때)

※ 마우스 커서는 ShowCursor()를 이용한다.


과제 1. 틀린 그림 찾기

- 이미지는 포토샵 편집 / 검색으로 처리한다.

- 스테이지는 총 2개의 스테이지
ㄴ 틀린곳은 다섯 곳 이상

- 게임이 시작되면 타임 게이지가 점점 줄어들며 잘못 클릭하면 게이지가 감소된다.

- 틀린곳을 맞추면 시간 증가

- 타임 게이지가 모두 소진되면 타임오버 메세지를 화면에 띄우며 게임 종료


 
과제 3. 포토샵 설치

- CS6

- 포토샵은 기본적으로 각 버전마다 기능이 매우 상이하거나 단축키가 다르다.




*/

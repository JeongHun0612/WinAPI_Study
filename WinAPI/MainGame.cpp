#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plImage = new GImage;
	_plImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(WINSIZE_X / 2 - 500, WINSIZE_Y / 2 + 200, 173, 291);

	_countA = _countB = 0;
	_alphaA = _alphaB = 0;

	_alphaNum = 1;

	_isAlphaIncrease = false;

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_plImage);
}

void MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK);
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 5.0f;
		_rc.right -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 5.0f;
		_rc.right += 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 5.0f;
		_rc.bottom -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 5.0f;
		_rc.bottom += 5.0f;
	}

	_countA++;
	if (_countA % 3 == 0)
	{
		_alphaA++;

		if (_alphaA >= 255)
		{
			_alphaA = 0;
		}
	}

	_countB++;
	if (_countB % 3 == 0)
	{
		_alphaB += 5;

		if (_alphaB >= 255)
		{
			_alphaB = 0;
		}
	}
}

void MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();

	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ==========================================================

	//_bgImage->render(memDC, 0, 0);
	_bgImage->alphaRender(memDC, _alphaA);

	//_plImage->render(memDC, _rc.left, _rc.top);
	_plImage->alphaRender(memDC, _rc.left, _rc.right, _alphaB);

	_bgImage->render(memDC, _rc.left, _rc.top, 500, 300, 300, 300);

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}


/*
과제 0. 포트폴리오 선행 작업 

 
과제 1. 슬라이스 게임

- 치트 필수

- 화면 왼쪽에 원본 사진 출력 < - > 화면 오른쪽에는 9등분된 이미지 출력

- 9등분 된 이미지 제일 아래 오른쪽 칸이 시작 칸

- 퍼즐이 완성되면 알파블렌딩 효과로 이미지가 나타난다.
ㄴ 중앙에서 완성된 이미지를 보여주면 된다.


과제 2. 미니맵 만들기

- 2가지 버전

- 플레이어의 움직임을 미니맵에서도 확인할 수 있어야 한다.
ㄴ 1. 화면에 표시되는 작은 GUI 형태의 미니맵
ㄴ 2. 화면위에 그려지는 전체화면 미니맵


과제 3. 지렁이 만들기

- 지렁이는 구슬이 꼬리를 물고 이어지는 형태
ㄴ 각 구슬마다 번호를 표기한다.

- 지렁이는 화면밖의 무작위 위치에서 등장을 한다.

- 특별한 키 입력이 없어도 지렁이는 화면안에서 움직인다.

- 벽에 부딪히면 팅겨 나가야 하고 왼쪽 / 오른쪽 방향키로 조종이 가능해야 한다.

- 따라오는 구슬은 머리가 방향을 튼다고 같이 틀면 안되고 머리가 있던 위치까지 와서 방향을 전환한다.

- 임의의 숫자가 표시된 아이템이 게임이 시작되면 생성되고 지렁이가 아이템을 먹으면 해당하는 번호의 지렁이 구슬이 커진다. (색깔도 넣어보기)

※ 얼마나 자연스러운지가 핵심
*/


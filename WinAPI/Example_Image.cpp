#include "Stdafx.h"
#include "Example_Image.h"

HRESULT Example_Image::init(void)
{
	GameNode::init();

	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plImage = new GImage;
	_plImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(WINSIZE_X / 2 - 500, WINSIZE_Y / 2 + 200, 173, 291);

	return S_OK;
}

void Example_Image::release(void)
{
	GameNode::release();

	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_plImage);
}

void Example_Image::update(void)
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
}

void Example_Image::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();

	// PatBlt() : 사각형 안에 영역을 브러쉬로 채우는 함수
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ==========================================================

	_bgImage->render(memDC, 0, 0);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(memDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	}

	_plImage->render(memDC, _rc.left, _rc.top);

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
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

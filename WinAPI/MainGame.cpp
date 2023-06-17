#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
}

void MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		rc.top -= 3;
		rc.bottom -= 3;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		rc.left -= 3;
		rc.right -= 3;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		rc.left += 3;
		rc.right += 3;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		rc.top += 3;
		rc.bottom += 3;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		rc.top += 10;
	}
}

void MainGame::render(HDC hdc)
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
}

/*
과제2. 클레이 사격

- 좌 / 우에서 무작위로 출현하는 타켓을 마우스로 제거한다.

- 타켓을 제거하면 점수 획득
	ㄴ 제거된 타켓은 그자리에서 바로 떨어진다.

- 등장하는 타켓의 종류는 무작위 도형 처리
	ㄴ 사각형 : 50점	/ 원 : -100점 / 다각형 : 100점

- 게임 시간은 60초로 한정하고 시간이 다 되거나 내 점수가 5천점이 되면 게임 종료


타임 어택. API 프레임 워크

- 가상화를 통해 메인 게임 클래스가 만들어지고 키 매니져를 통해 렉트를 움직이는 파트까지

- 실패 시 : 깜지 5번
*/
#include "Stdafx.h"
#include "Report_Horizontal_Shooting.h"

/*
과제 2. 1 VS 1 횡스크롤 슈팅 게임

- 왼쪽에 1P / 오른쪽에 2P

- 체력 바는 대전게임처럼 중앙을 기준으로 좌우 배치
ㄴ 체력 바 상태에 따라 녹 / 노 / 빨

- 공격 당하면 당한쪽은 당연히 체력이 감소해야 한다.

※ 필수 :
스킬 2개 + 2개 = 4개
아이템을 2종 구현해 온다.
*/

HRESULT Report_Horizontal_Shooting::init(void)
{
	_Player1.rc = RectMakeCenter(100, WINSIZE_Y / 2, 100, 30);
	_Player2.rc = RectMakeCenter(WINSIZE_X - 100, WINSIZE_Y / 2, 100, 30);

	return S_OK;
}

void Report_Horizontal_Shooting::release(void)
{
}

void Report_Horizontal_Shooting::update(void)
{
	// Player1 조작
	if (KEYMANAGER->isStayKeyDown(KEY_A) && _Player1.rc.left > 0)
	{
		_Player1.rc.left -= PLAYER_SPEED;
		_Player1.rc.right -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(KEY_D) && _Player1.rc.right < WINSIZE_X / 2 - 50)
	{
		_Player1.rc.left += PLAYER_SPEED;
		_Player1.rc.right += PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(KEY_W) && _Player1.rc.top > 100)
	{
		_Player1.rc.top -= PLAYER_SPEED;
		_Player1.rc.bottom -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(KEY_S) && _Player1.rc.bottom < WINSIZE_Y - 100)
	{
		_Player1.rc.top += PLAYER_SPEED;
		_Player1.rc.bottom += PLAYER_SPEED;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		//RECT _bullet = RectMakeCenter(
		//	_Player1.rc.right + 20,
		//	_Player1.rc.top + (_Player1.rc.bottom - _Player1.rc.top) / 2,
		//	10, 10);
		//_vPlayerBullet1.push_back(_bullet);

		RECT _bullet = RectMakeCenter(50, 50, 10, 10);
		_vPlayerBullet1.push_back(_bullet);
	}

	// Player2 조작
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _Player2.rc.left > WINSIZE_X / 2 + 50)
	{
		_Player2.rc.left -= PLAYER_SPEED;
		_Player2.rc.right -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _Player2.rc.right < WINSIZE_X)
	{
		_Player2.rc.left += PLAYER_SPEED;
		_Player2.rc.right += PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _Player2.rc.top > 100)
	{
		_Player2.rc.top -= PLAYER_SPEED;
		_Player2.rc.bottom -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _Player2.rc.bottom < WINSIZE_Y - 100)
	{
		_Player2.rc.top += PLAYER_SPEED;
		_Player2.rc.bottom += PLAYER_SPEED;
	}
}

void Report_Horizontal_Shooting::render(HDC hdc)
{
	DrawRectMake(hdc, _Player1.rc);
	DrawRectMake(hdc, _Player2.rc);

	//for (auto iter = _vPlayerBullet1.begin(); iter != _vPlayerBullet1.end(); ++iter)
	//{
	//	EllipseMakeCenter(hdc, iter->left, iter->right, iter->top, iter->bottom);
	//}
}
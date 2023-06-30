#include "Stdafx.h"
#include "Report_16_3_MainGame.h"

/*
- 지렁이는 구슬이 꼬리를 물고 이어지는 형태
ㄴ 각 구슬마다 번호를 표기한다.

- 지렁이는 화면밖의 무작위 위치에서 등장을 한다.

- 특별한 키 입력이 없어도 지렁이는 화면안에서 움직인다.

- 벽에 부딪히면 팅겨 나가야 하고 왼쪽 / 오른쪽 방향키로 조종이 가능해야 한다.

- 따라오는 구슬은 머리가 방향을 튼다고 같이 틀면 안되고 머리가 있던 위치까지 와서 방향을 전환한다.

- 임의의 숫자가 표시된 아이템이 게임이 시작되면 생성되고 지렁이가 아이템을 먹으면 해당하는 번호의 지렁이 구슬이 커진다. (색깔도 넣어보기)

※ 얼마나 자연스러운지가 핵심
*/

HRESULT Report_16_3_MainGame::init()
{
	// 지렁이 객체 초기화
	for (int i = 0; i < MAX_WORM; i++)
	{
		_worms[i].x = -50;
		_worms[i].y = -50;
		_worms[i].id = i;
		_worms[i].radius = 20.0f;
		_worms[i].color = RGB(0, 0, 0);
	}

	speed = 4.0f;
	count = 0;

	switch (RND->getInt(4))
	{
	case 0: // Left
		_worms[0].x = 25;
		_worms[0].y = RND->getFromIntTo(50, WINSIZE_Y - 50);
		angle = 0.0f;
		break;
	case 1: // Right
		_worms[0].x = WINSIZE_X - 25;
		_worms[0].y = RND->getFromIntTo(50, WINSIZE_Y - 50);
		angle = 180.0f;
		break;
	case 2: // Up
		_worms[0].x = RND->getFromIntTo(50, WINSIZE_X - 50);
		_worms[0].y = 25;
		angle = 90;
		break;
	case 3: // Down
		_worms[0].x = RND->getFromIntTo(50, WINSIZE_X - 50);
		_worms[0].y = WINSIZE_Y - 25;
		angle = 270;
		break;
	}

	// 아이템 객체 초기화
	_item.x = -50;
	_item.y = -50;

	return S_OK;
}

void Report_16_3_MainGame::release(void)
{
}

void Report_16_3_MainGame::update(void)
{
	// 키입력
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		angle -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		angle += 3;
	}

	// 좌표값 변경
	_worms[0].x += cosf(DEGREE_RADIAN(angle)) * speed;
	_worms[0].y += sinf(DEGREE_RADIAN(angle)) * speed;

	// 벽 충돌
	if (_worms[0].x - _worms[0].radius <= 0)
	{
		_worms[0].x = _worms[0].radius;
		angle = 180 - angle;
	}
	if (_worms[0].x + _worms[0].radius >= WINSIZE_X)
	{
		_worms[0].x = WINSIZE_X - _worms[0].radius - 10;
		angle = 180 - angle;
	}
	if (_worms[0].y - _worms[0].radius <= 0)
	{
		_worms[0].y = _worms[0].radius;
		angle = 360 - angle;
	}
	if (_worms[0].y + _worms[0].radius >= WINSIZE_Y)
	{
		_worms[0].y = WINSIZE_Y - _worms[0].radius;
		angle = 360 - angle;
	}
	
	// 아이템 충돌
	if (PtInRect(&_item.rc, { static_cast<LONG>(_worms[0].x), static_cast<LONG>(_worms[0].y) }))
	{
		_item.x = -50;
		_item.y = -50;
		_item.rc = RectMake(_item.x, _item.y, 30, 30);

		_worms[_item.id].radius += 10;
		_worms[_item.id].color = RGB(RND->getInt(256), RND->getInt(256), RND->getInt(256));
	}
	
	// 꼬리 위치 값 변경
	count++;
	if (count % 5 == 0)
	{
		for (int i = MAX_WORM - 1; i >= 1; i--)
		{
			_worms[i].x = _worms[i - 1].x;
			_worms[i].y = _worms[i - 1].y;
		}
	}

	// 아이템 생성
	if (count % 400 == 0)
	{
		_item.id = RND->getInt(MAX_WORM);
		_item.x = RND->getFromIntTo(50, WINSIZE_X - 50);
		_item.y = RND->getFromIntTo(50, WINSIZE_Y - 50);
		_item.rc = RectMake(_item.x, _item.y, 30, 30);
	}

	if (count == 10000)
	{
		count = 0;
	}
}

void Report_16_3_MainGame::render(void)
{
	HBRUSH hBrush;
	HBRUSH hOldBrush;

	// 지렁이 렌더
	for (int i = MAX_WORM - 1; i >= 0; i--)
	{
		if (_worms[i].color != RGB(0, 0, 0))
		{
			hBrush = CreateSolidBrush(_worms[i].color);`
			hOldBrush = (HBRUSH)SelectObject(getMemDC(), hBrush);

			EllipseMakeCenter(getMemDC(), _worms[i].x, _worms[i].y, _worms[i].radius);

			hBrush = (HBRUSH)SelectObject(getMemDC(), hOldBrush);
			DeleteObject(hBrush);
		}
		else
		{
			EllipseMakeCenter(getMemDC(), _worms[i].x, _worms[i].y, _worms[i].radius);
		}

		sprintf_s(strId, "%d", _worms[i].id);
		TextOut(getMemDC(), _worms[i].x, _worms[i].y, strId, strlen(strId));
	}

	// 아이템 렌더
	DrawRectMake(getMemDC(), _item.rc);
	sprintf_s(strId, "%d", _item.id);
	TextOut(getMemDC(), _item.x + 10, _item.y + 10, strId, strlen(strId));
}

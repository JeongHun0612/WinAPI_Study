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
	GameNode::init();

	for (int i = 0; i < MAX_WORM; i++)
	{
		_worms[i].centerPos = { WINSIZE_X / 2, WINSIZE_Y / 2 - i * 15 };
		_worms[i].angle = 0;
		_worms[i].radius = 15;
		_worms[i].speed = 3.0f;
	}

	//_bead.rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 50, 50);
	//_bead.angle = 0;
	//_bead.centerPos = { WINSIZE_X / 2, WINSIZE_Y / 2 };
	//_bead.radius = 25.0f;
	//_bead.speed = 3.0f;

	return S_OK;
}

void Report_16_3_MainGame::release(void)
{
	GameNode::release();
}

void Report_16_3_MainGame::update(void)
{
	GameNode::update();

	for (int i = 0; i < MAX_WORM; i++)
	{
		_worms[i].centerPos.x += sin(DEGREE_RADIAN(_worms[i].angle)) * _worms[i].speed;
		_worms[i].centerPos.y += cos(DEGREE_RADIAN(_worms[i].angle)) * _worms[i].speed;
	}

	for (int i = 1; i < MAX_WORM; i++)
	{
		if (rotPosX == _worms[i].centerPos.x && rotPosY == _worms[i].centerPos.y)
		{
			_worms[i].angle = _worms[0].angle;
		}
	}


	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		rotPosX = _worms[0].centerPos.x;
		rotPosY = _worms[0].centerPos.y;
		rotAngle = _worms[0].angle;

		_worms[0].angle += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		rotPosX = _worms[0].centerPos.x;
		rotPosY = _worms[0].centerPos.y;

		_worms[0].angle -= 3;
	}
}

void Report_16_3_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	EllipseMakeCenter(memDC, _worms[0].centerPos.x, _worms[0].centerPos.y, _worms[0].radius);

	for (int i = 0; i < MAX_WORM; i++)
	{
		EllipseMakeCenter(memDC, _worms[i].centerPos.x, _worms[i].centerPos.y, _worms[i].radius);
		//EllipseMakeCenter(memDC, 
		//	_worms[0].centerPos.x + sin(DEGREE_RADIAN(_worms[0].angle)) * _worms[0].speed,
		//	_worms[0].centerPos.y + cos(DEGREE_RADIAN(_worms[0].angle)) * _worms[0].speed,
		//	_worms[i].radius);
	}

	this->getDoubleBuffer()->render(hdc, 0, 0);
}

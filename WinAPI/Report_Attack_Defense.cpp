#include "Stdafx.h"
#include "Report_Attack_Defense.h"

/*
과제 1. 캐릭터 공격 및 방어

- 필수 : 이미지 -> 배경 / 체력바 / 플레이어 (대기, 공격, 방어), 적 (대기, 공격, 피격)

- 기본 형식은 대전게임처럼 좌 / 우로 배치
ㄴ + 체력바

- 플레이어는 공격 및 방어를 할 수 있고 적은 공격 및 피격 모션이 존재한다.
ㄴ 적 : 허수아비

- 플레이어는 상시 조종 < - > 적은 공격 on / off 기능만 (이동 X)

- 공격, 방어, 피격 등이 발생하면 상황에 맞는 결과를 화면에 렌더링 한다.
ㄴ 막기, 빗나감, 치명타 등)

- 데미지도 표기한다.
ㄴ 컨버팅 할 수 있으면 해본다.
*/

HRESULT Report_Attack_Defense::init(void)
{
	// 플레이어 이미지
	IMAGEMANAGER->addFrameImage("player_head", "Resources/Images/Player/Head.bmp", 244, 44, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_body", "Resources/Images/Player/Body.bmp", 272, 300, 8, 10, true, RGB(255, 0, 255));

	// 타일 이미지
	IMAGEMANAGER->addImage("dirt", "Resources/Images/Tile/dirt1.bmp", 192, 128);

	_player.headImg = IMAGEMANAGER->findImage("player_head");
	_player.bodyImg = IMAGEMANAGER->findImage("player_body");

	_player.x = WINSIZE_X / 2;
	_player.y = WINSIZE_Y / 2 - 16;

	_player.rc = RectMake(_player.x, _player.y, 64, 64);
	_player.curDirection = PLAYER_DIRECTION::NONE;

	_player.isMove = false;

	_count = 0;

	return S_OK;
}

void Report_Attack_Defense::release(void)
{
	IMAGEMANAGER->deleteImage("player_head");
	IMAGEMANAGER->deleteImage("player_body");
}

void Report_Attack_Defense::update(void)
{
	_count++;

	if (_count % 8 == 0)
	{
		_player.headImg->setFrameX(_player.headImg->getFrameX() + 1);
		_player.bodyImg->setFrameX(_player.bodyImg->getFrameX() + 1);

		if (_player.headImg->getFrameX() == _player.headImg->getMaxFrameX() / 2)
		{
			_player.bodyImg->setFrameX(0);
			_player.headImg->setFrameX(0);
			_count = 0;
		}
	}

	if (_player.isMove)
	{
		moveAction(_player.curDirection);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::LEFT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::RIGHT;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::UP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && !_player.isMove)
	{
		_player.isMove = true;
		_player.curDirection = PLAYER_DIRECTION::DOWN;
	}
}

void Report_Attack_Defense::render(void)
{
	// 타일 그리기
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (j % 2 == 0)
			{
				IMAGEMANAGER->findImage("dirt")->render(getMemDC(), j * 64, i * 64, 0, 0, 64, 64);
			}
			else
			{
				IMAGEMANAGER->findImage("dirt")->render(getMemDC(), j * 64, i * 64, 64, 0, 64, 64);
			}
		}
	}

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		DrawRectMake(getMemDC(), _player.rc);
	}

	_player.headImg->frameRender(getMemDC(),
		_player.x + _player.headImg->getFrameWidth() / 2,
		_player.y + _player.headImg->getFrameHeight() / 2,
		_player.headImg->getFrameX(), _player.headImg->getFrameY());

	_player.bodyImg->frameRender(getMemDC(),
		_player.x + _player.headImg->getFrameWidth() / 2,
		_player.y + _player.headImg->getFrameHeight() / 2 + 16,
		_player.bodyImg->getFrameX(), _player.bodyImg->getFrameY());
}

void Report_Attack_Defense::moveAction(PLAYER_DIRECTION direction)
{
	static int jumpCount = 0;

	switch (direction)
	{
	case Report_Attack_Defense::PLAYER_DIRECTION::LEFT:
		_player.x -= 8;
		break;
	case Report_Attack_Defense::PLAYER_DIRECTION::RIGHT:
		_player.x += 8;
		break;
	case Report_Attack_Defense::PLAYER_DIRECTION::UP:
		_player.y -= 8;
		break;
	case Report_Attack_Defense::PLAYER_DIRECTION::DOWN:
		_player.y += 8;
		break;
	}

	_player.rc = RectMake(_player.x, _player.y - 8, 64, 64);

	_player.y += (jumpCount < 4) ? -4 : 4;

	jumpCount++;

	if (jumpCount == 8)
	{
		jumpCount = 0;
		_player.isMove = false;
	}
}

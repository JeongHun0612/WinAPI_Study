#include "Stdafx.h"
#include "Report_Wall_Catch.h"

/*
과제 1. 캐릭터 벽잡기

- 이미지 필수 : 배경, 벽, 캐릭터 (대기, 이동, 점프, 벽을 잡고 있는 모션)

- 기본적으로 벽을 잡을때는 가장 위쪽 모서리를 잡으며 벽 중간을 잡았을 경우 천천히 지면으로 내려온다.

- 캐릭터가 벽을 잡고 있는 상태에서 위 / 또는 아래 방향키를 누르면 올라가거나 / 내려갈 수 있어야 한다.

- 또한 캐릭터가 벽 위로 올라선 다음 다시 아래로 점프하면 캐릭터는 지면에 착지 할 수 있어야 한다.

- 캐릭터 점프 높이의 지형이 있고 캐릭터는 지형 밑에서 점프로 지형위로 올라 갈 수 있다.

- 캐릭터는 지형에 올라선 상태에서 지면으로 다시 내려올 수 있으면 OK


과제 2. 미니맵 연동

- 플레이어의 움직임을 미니맵에서 그대로 확인해야 한다.
ㄴ 움직임까지 동일하게
*/

HRESULT Report_Wall_Catch::init(void)
{
	_player.anim[EState::IDLE].frameImage = IMAGEMANAGER->addFrameImage("Zero_Idle", "Resources/Images/Object/Zero_Idle.bmp", 600, 150, 4, 2, true, RGB(255, 0, 255));
	_player.anim[EState::IDLE].frameChangeCnt = 10;

	_player.anim[EState::MOVE].frameImage = IMAGEMANAGER->addFrameImage("Zero_Move", "Resources/Images/Object/Zero_Move.bmp", 960, 110, 16, 2, true, RGB(255, 0, 255));
	_player.anim[EState::MOVE].frameChangeCnt = 3;

	_player.anim[EState::JUMP].frameImage = IMAGEMANAGER->addFrameImage("Zero_Jump", "Resources/Images/Object/Zero_Jump.bmp", 550, 180, 11, 2, true, RGB(255, 0, 255));
	_player.anim[EState::JUMP].frameChangeCnt = 5;

	_player.state = EState::IDLE;
	_player.x = WINSIZE_X / 2.0f;
	_player.y = WINSIZE_Y / 2.0f;
	_player.isLeft = false;
	_player.isJump = false;
	_player.isJumpped = false;

	_count = 0;
	_index = 0;


	return S_OK;
}

void Report_Wall_Catch::release(void)
{
	IMAGEMANAGER->deleteImage("Zero_Idle");
	IMAGEMANAGER->deleteImage("Zero_Move");
	IMAGEMANAGER->deleteImage("Zero_Jump");
}

void Report_Wall_Catch::update(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_player.state == EState::IDLE)
		{
			_player.state = EState::MOVE;
			_player.isLeft = true;
			_count = 0;
			_index = 0;
		}

		_player.x -= 4.0f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_player.state == EState::IDLE)
		{
			_player.state = EState::MOVE;
			_player.isLeft = false;
			_count = 0;
			_index = 0;
		}

		_player.x += 4.0f;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) || KEYMANAGER->isOnceKeyUp(VK_LEFT) && !_player.isJump)
	{
		_player.state = EState::IDLE;
		_count = 0;
		_index = 0;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && !_player.isJump)
	{
		_player.isJump = true;
		_player.state = EState::JUMP;
		_count = 0;
		_index = 0;
	}

	if (_player.isJump)
	{
		static float maxPosY = _player.y - 50.0f;
		static float tempPosY = _player.y;

		if (_player.y > maxPosY && !_player.isJumpped)
		{
			_player.y -= 1.0f;

			if (_player.y <= maxPosY)
			{
				_player.isJumpped = true;
			}
		}

		if (_player.isJumpped)
		{
			_player.y += 1.0f;

			if (_player.y >= tempPosY)
			{
				_player.state = EState::IDLE;
				_player.isJumpped = false;
				_player.isJump = false;
			}
		}
	}

	_count++;

	if (_count % _player.anim[_player.state].frameChangeCnt == 0)
	{
		if (!_player.isLeft)
		{
			_index++;

			if (_player.anim[_player.state].frameImage->getFrameY() != 0)
			{
				_player.anim[_player.state].frameImage->setFrameY(0);
			}

			if (_index > _player.anim[_player.state].frameImage->getMaxFrameX())
			{
				_index = 0;
			}
			_player.anim[_player.state].frameImage->setFrameX(_index);
		}
		else
		{
			_index--;

			if (_player.anim[_player.state].frameImage->getFrameY() != 1)
			{
				_player.anim[_player.state].frameImage->setFrameY(1);
			}

			if (_index < 0)
			{
				_index = _player.anim[_player.state].frameImage->getMaxFrameX();
			}
			_player.anim[_player.state].frameImage->setFrameX(_index);
		}
	}
}

void Report_Wall_Catch::render(void)
{
	_player.anim[_player.state].frameImage->frameRender(getMemDC(),
		_player.x - _player.anim[_player.state].frameImage->getFrameWidth() / 2,
		_player.y - _player.anim[_player.state].frameImage->getFrameHeight() / 2);
}


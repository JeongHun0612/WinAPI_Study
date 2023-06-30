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
	IMAGEMANAGER->addFrameImage("zero_idle", "Resources/Images/Object/Zero_Idle.bmp", 600, 150, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("zero_move", "Resources/Images/Object/Zero_Move.bmp", 960, 110, 16, 2, true, RGB(255, 0, 255));

	_player._img = IMAGEMANAGER->findImage("zero_idle");
	_player._state = EState::IDLE;
	_player._isLeft = false;

	_count = _index = 0;

	return S_OK;
}

void Report_Wall_Catch::release(void)
{
}

void Report_Wall_Catch::update(void)
{
	IMAGEMANAGER->findImage("zero_move")->getFrameX();

	_count++;

	_player._img->setFrameY(0);

	if (_count % 10 == 0)
	{
		_index--;

		if (_index < 0)
		{
			_index = _player._img->getMaxFrameX();
		}

		_player._img->setFrameX(_index);
	}

		//// 이미지 프레임 연산
		//if (_isLeft)
		//{
		//	_count++;

		//	_motionImage[_currentIdx].motion->setFrameY(0);

		//	if (_count % 5 == 0)
		//	{
		//		_index++;

		//		if (_index > _motionImage[_currentIdx].motion->getMaxFrameX())
		//		{
		//			_index = 0;
		//		}

		//		_motionImage[_currentIdx].motion->setFrameX(_index);
		//	}
		//}
		//else
		//{
		//	_count++;

		//	_motionImage[_currentIdx].motion->setFrameY(1);

		//	if (_count % 5 == 0)
		//	{
		//		_index--;

		//		if (_index < 0)
		//		{
		//			_index = _motionImage[_currentIdx].motion->getMaxFrameX();
		//		}

		//		_motionImage[_currentIdx].motion->setFrameX(_index);
		//	}
		//}
}

void Report_Wall_Catch::render(void)
{
	_player._img->frameRender(getMemDC(), WINSIZE_X / 2, WINSIZE_Y / 2);
	//IMAGEMANAGER->frameRender("zero_move", getMemDC(), WINSIZE_X / 2, WINSIZE_Y / 2);


}


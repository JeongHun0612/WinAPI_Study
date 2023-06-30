#include "Stdafx.h"
#include "Report_17_1_MainGame.h"

/*
과제 1. 제로 콤보 이미지 완성

- 스페이스 바를 누르면 1타부터 -> 마지막 공격까지 자동으로 재생
ㄴ 무한 반복
*/

HRESULT Report_17_1_MainGame::init(void)
{
    GameNode::init();

	_idle.maxFrameX = 4;
	_idle.maxFrameY = 2;
	_idle.image = new GImage;
	_idle.image->init("Resources/Images/Object/Zero_Idle.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 600, 150, _idle.maxFrameX, _idle.maxFrameY, true, RGB(255, 0, 255));
	_idle.count = _idle.index = 0;

	_attack1.maxFrameX = 12;
	_attack1.maxFrameY = 2;
	_attack1.image = new GImage;
	_attack1.image->init("Resources/Images/Object/Zero_Attack1.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 1800, 150, _attack1.maxFrameX, _attack1.maxFrameY, true, RGB(255, 0, 255));

	_attack2.maxFrameX = 10;
	_attack2.maxFrameY = 2;
	_attack2.image = new GImage;
	_attack2.image->init("Resources/Images/Object/Zero_Attack2.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 1500, 150, _attack2.maxFrameX, _attack2.maxFrameY, true, RGB(255, 0, 255));

	_attack3.maxFrameX = 11;
	_attack3.maxFrameY = 2;
	_attack3.image = new GImage;
	_attack3.image->init("Resources/Images/Object/Zero_Attack3.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 1650, 160, _attack3.maxFrameX, _attack3.maxFrameY, true, RGB(255, 0, 255));

	_isLeft = false;
	_isAttack = false;

	_attackIndex = 0;

    return S_OK;
}

void Report_17_1_MainGame::release(void)
{
    GameNode::release();
}

void Report_17_1_MainGame::update(void)
{
    GameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		_idle.image->setX(_idle.image->getX() - 8.0f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		_idle.image->setX(_idle.image->getX() + 8.0f);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_isAttack = !_isAttack;
		_attackIndex = 0;
	}

	if (!_isAttack)
	{
		_idle.count++;
		if (_idle.count % 10 == 0)
		{
			_idle.index++;

			if (_idle.index > _idle.maxFrameX)
			{
				_idle.index = 0;
			}
			
			_idle.image->setFrameX(_idle.index);
		}
	}
	else
	{
		switch (_attackIndex)
		{
		case 0:
			if (_attack1.count % 10 == 0)
			{
				_attack1.index++;

				if (_attack1.index > _attack1.maxFrameX)
				{
					_attack1.index = 0;
					_attackIndex++;
				}

				_attack1.image->setFrameX(_attack1.index);
			}
			break;
		case 1:
			if (_attack2.count % 10 == 0)
			{
				_attack2.index++;

				if (_attack2.index > _attack2.maxFrameX)
				{
					_attack2.index = 0;
					_attackIndex++;
				}

				_attack2.image->setFrameX(_attack2.index);
			}
			break;
		case 2:
			if (_attack3.count % 10 == 0)
			{
				_attack3.index++;

				if (_attack3.index > _attack3.maxFrameX)
				{
					_attack3.index = 0;
					_attackIndex = 0;
				}

				_attack3.image->setFrameX(_attack3.index);
			}
			break;
		}
	}
}

void Report_17_1_MainGame::render(HDC hdc)
{
	if (!_isAttack)
	{
		_idle.image->frameRender(getMemDC(), _idle.image->getX(), _idle.image->getY());
	}
	else
	{
		switch (_attackIndex)
		{
		case 0:
			_attack1.image->frameRender(getMemDC(), _attack1.image->getX(), _attack1.image->getY());
			break;
		case 1:
			_attack2.image->frameRender(getMemDC(), _attack2.image->getX(), _attack2.image->getY());
			break;
		case 2:
			_attack3.image->frameRender(getMemDC(), _attack3.image->getX(), _attack3.image->getY());
			break;
		}
	}
}

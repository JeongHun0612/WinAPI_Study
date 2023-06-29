#include "Stdafx.h"
#include "Report_17_1_MainGame.h"

HRESULT Report_17_1_MainGame::init(void)
{
    GameNode::init();

	_idle.maxFrameX = 4;
	_idle.maxFrameY = 2;
	_idle.image = new GImage;
	_idle.image->init("Resources/Images/Object/Zero_Idle.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 600, 160, _idle.maxFrameX, _idle.maxFrameY, true, RGB(255, 0, 255));
	_idle.state = EPLAYER_STATE::IDLE;
	_idle.count = _idle.index = 0;

	_attack1.maxFrameX = 12;
	_attack1.maxFrameY = 2;
	_attack1.image = new GImage;
	_attack1.image->init("Resources/Images/Object/Zero_Attack1.bmp", WINSIZE_X / 2, WINSIZE_Y / 2, 1800, 160, _attack1.maxFrameX, _attack1.maxFrameY, true, RGB(255, 0, 255));
	_attack1.state = EPLAYER_STATE::ATTACK;
	_attack1.count = _attack1.index = 0;

	_count = _index = 0;

	_currentState = EPLAYER_STATE::IDLE;
	_isLeft = false;
	_isAttack = false;

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
		//_currentState = EPLAYER_STATE::ATTACK;
		_isAttack = true;
	}


	if (_isLeft)
	{
		_count++;

		if (_isAttack)
		{

		}
		else
		{
			_idle.image->setFrameY(1);

			if (_count % 10 == 0)
			{
				_index--;

				if (_index < 0)
				{
					_index = 10;
				}

				_idle.image->setFrameX(_index);
			}
		}
	}
	else
	{
		if (_isAttack)
		{
			_attack1.count++;
			_attack1.image->setFrameY(0);

			if (_attack1.count % 5 == 0)
			{
				_attack1.index++;

				if (_attack1.index > _attack1.maxFrameX)
				{
					_isAttack = false;
					_attack1.index = 0;
				}

				_attack1.image->setFrameX(_attack1.index);
			}

		}
		else
		{
			_idle.count++;
			_idle.image->setFrameY(0);

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
	}
}

void Report_17_1_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();

	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ==========================================================

	//switch (_currentState)
	//{
	//case EPLAYER_STATE::IDLE:
	//	_idle.image->frameRender(memDC, _idle.image->getX(), _idle.image->getY());
	//	break;
	//case EPLAYER_STATE::ATTACK:
	//	_attack1.image->frameRender(memDC, _attack1.image->getX(), _attack1.image->getY());
	//	break;
	//}

	if (_isAttack)
	{
		_attack1.image->frameRender(memDC, _attack1.image->getX(), _attack1.image->getY());
	}
	else
	{
		_idle.image->frameRender(memDC, _idle.image->getX(), _idle.image->getY());
	}

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);

}

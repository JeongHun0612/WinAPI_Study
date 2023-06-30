#include "Stdafx.h"
#include "Report_Wall_Catch.h"

/*
���� 1. ĳ���� �����

- �̹��� �ʼ� : ���, ��, ĳ���� (���, �̵�, ����, ���� ��� �ִ� ���)

- �⺻������ ���� �������� ���� ���� �𼭸��� ������ �� �߰��� ����� ��� õõ�� �������� �����´�.

- ĳ���Ͱ� ���� ��� �ִ� ���¿��� �� / �Ǵ� �Ʒ� ����Ű�� ������ �ö󰡰ų� / ������ �� �־�� �Ѵ�.

- ���� ĳ���Ͱ� �� ���� �ö� ���� �ٽ� �Ʒ��� �����ϸ� ĳ���ʹ� ���鿡 ���� �� �� �־�� �Ѵ�.

- ĳ���� ���� ������ ������ �ְ� ĳ���ʹ� ���� �ؿ��� ������ �������� �ö� �� �� �ִ�.

- ĳ���ʹ� ������ �ö� ���¿��� �������� �ٽ� ������ �� ������ OK


���� 2. �̴ϸ� ����

- �÷��̾��� �������� �̴ϸʿ��� �״�� Ȯ���ؾ� �Ѵ�.
�� �����ӱ��� �����ϰ�
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

		//// �̹��� ������ ����
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


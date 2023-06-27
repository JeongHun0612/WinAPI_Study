#include "Stdafx.h"
#include "Report_16_3_MainGame.h"

/*
- �����̴� ������ ������ ���� �̾����� ����
�� �� �������� ��ȣ�� ǥ���Ѵ�.

- �����̴� ȭ����� ������ ��ġ���� ������ �Ѵ�.

- Ư���� Ű �Է��� ��� �����̴� ȭ��ȿ��� �����δ�.

- ���� �ε����� �ð� ������ �ϰ� ���� / ������ ����Ű�� ������ �����ؾ� �Ѵ�.

- ������� ������ �Ӹ��� ������ ư�ٰ� ���� Ʋ�� �ȵǰ� �Ӹ��� �ִ� ��ġ���� �ͼ� ������ ��ȯ�Ѵ�.

- ������ ���ڰ� ǥ�õ� �������� ������ ���۵Ǹ� �����ǰ� �����̰� �������� ������ �ش��ϴ� ��ȣ�� ������ ������ Ŀ����. (���� �־��)

�� �󸶳� �ڿ����������� �ٽ�
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

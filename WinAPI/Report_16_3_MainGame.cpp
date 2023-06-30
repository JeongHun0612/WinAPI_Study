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
	// ������ ��ü �ʱ�ȭ
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

	// ������ ��ü �ʱ�ȭ
	_item.x = -50;
	_item.y = -50;

	return S_OK;
}

void Report_16_3_MainGame::release(void)
{
}

void Report_16_3_MainGame::update(void)
{
	// Ű�Է�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		angle -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		angle += 3;
	}

	// ��ǥ�� ����
	_worms[0].x += cosf(DEGREE_RADIAN(angle)) * speed;
	_worms[0].y += sinf(DEGREE_RADIAN(angle)) * speed;

	// �� �浹
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
	
	// ������ �浹
	if (PtInRect(&_item.rc, { static_cast<LONG>(_worms[0].x), static_cast<LONG>(_worms[0].y) }))
	{
		_item.x = -50;
		_item.y = -50;
		_item.rc = RectMake(_item.x, _item.y, 30, 30);

		_worms[_item.id].radius += 10;
		_worms[_item.id].color = RGB(RND->getInt(256), RND->getInt(256), RND->getInt(256));
	}
	
	// ���� ��ġ �� ����
	count++;
	if (count % 5 == 0)
	{
		for (int i = MAX_WORM - 1; i >= 1; i--)
		{
			_worms[i].x = _worms[i - 1].x;
			_worms[i].y = _worms[i - 1].y;
		}
	}

	// ������ ����
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

	// ������ ����
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

	// ������ ����
	DrawRectMake(getMemDC(), _item.rc);
	sprintf_s(strId, "%d", _item.id);
	TextOut(getMemDC(), _item.x + 10, _item.y + 10, strId, strlen(strId));
}

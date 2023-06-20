#include "Stdafx.h"
#include "Example_Mole.h"

#define CENTER_X        WINSIZE_X / 2
#define CENTER_Y        WINSIZE_Y / 2

HRESULT Example_Mole::init(void)
{
	_currentRect = CURRENTRECT_NULL;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rc[i * 4 + j] = RectMakeCenter(100 + j * 200, 200 + i * 200, 100, 100);
		}
	}

	_index = 0;
	_count = 0;
	_score = 0;
	_time = RND->getFromIntTo(30, 60);

	_bIsSelected = false;
	_bIsOnceCheck = false;

    return S_OK;
}

void Example_Mole::release(void)
{
}

void Example_Mole::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		// PtInRect() : 렉트 안에 POINT(x, y)가 있는지 검사하여 포인트가 사각형 안에 있으면 true값을 반환하는 API 함수
		if (PtInRect(&_rc[_index], _ptMouse) && !_bIsOnceCheck)
		{
			_score += 100;
			_bIsOnceCheck = true;
		}
	}

	if (!_bIsSelected)
	{
		_count++;

		if (_count % _time == 0)
		{
			_count = 0;
			_index = RND->getInt(8);
			_currentRect = (CURRENT_RECT)_index;
			_bIsSelected = true;
		}
	}
	else
	{
		_count++;

		if (_count % _time == 0)
		{
			_bIsOnceCheck = false;
			_bIsSelected = false;
			_currentRect = CURRENTRECT_NULL;
			_time = RND->getFromIntTo(30, 60);
			_index = 100;
		}
	}
}

void Example_Mole::render(HDC hdc)
{
	for (int i = 0; i < 8; i++)
	{
		Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
	}

	char strScore[128];

	wsprintf(strScore, "Score : %d", _score);
	TextOut(hdc, 50, 100, strScore, strlen(strScore));

	if (_bIsSelected)
	{
		int r = RND->getInt(256);
		int g = RND->getInt(256);
		int b = RND->getInt(256);

		HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
		FillRect(hdc, &_rc[_index], brush);
		DeleteObject(brush); // 데이터 누수 방지
	}
}

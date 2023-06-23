#include "Stdafx.h"
#include "Report_15_1_MainGame.h"

/*
과제 1. 아날로그 시계

- 초침 / 분침 / 시침

- 오늘 사용한 SYSTEMTIME를 이용해서 만든다.

- 필수 : 시간 표시
*/

int currentX = WINSIZE_X / 2;
int currentY = WINSIZE_Y / 2;

HRESULT Report_15_1_MainGame::init(void)
{
	GameNode::init();

	_radius = 300;

	for (int i = 0; i < 12; i++)
	{
		_hour[i].x = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(i * 30.0f - 90)) * (_radius - 100);
		_hour[i].y = WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(i * 30.0f - 90)) * (_radius - 100);
	}

	for (int i = 0; i < 60; i++)
	{
		_minute[i].x = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(i * 6.0f - 90)) * (_radius - 50);
		_minute[i].y = WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(i * 6.0f - 90)) * (_radius - 50);

		_second[i].x = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(i * 6.0f - 90)) * (_radius - 30);
		_second[i].y = WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(i * 6.0f - 90)) * (_radius - 30);
	}


	return S_OK;
}

void Report_15_1_MainGame::release(void)
{
	GameNode::release();
}

void Report_15_1_MainGame::update(void)
{
	GameNode::update();

	GetLocalTime(&_st);

	_st.wHour;
	_st.wMinute;
	_st.wSecond;
}

void Report_15_1_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==========================================================

	char strTime[128];

	sprintf_s(strTime, "%d시 %d분 %d초", _st.wHour, _st.wMinute, _st.wSecond);
	SetTextAlign(memDC, TA_CENTER);
	TextOut(memDC, WINSIZE_X / 2, 10, strTime, strlen(strTime));

	EllipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _radius + 20);
	EllipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _radius);
	EllipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, 10);

	for (int i = 0; i < 60; i++)
	{
		int startRadius = (i % 5 == 0) ? _radius - 20 : _radius - 10;

		LineMake(
			memDC,
			WINSIZE_X / 2 + cosf(DEGREE_RADIAN(i * 6.0f - 90)) * startRadius,
			WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(i * 6.0f - 90)) * startRadius,
			WINSIZE_X / 2 + cosf(DEGREE_RADIAN(i * 6.0f - 90)) * _radius,
			WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(i * 6.0f - 90)) * _radius
		);
	}

	LineMake(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _hour[_st.wHour % 12].x, _hour[_st.wHour % 12].y);
	LineMake(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _minute[_st.wMinute].x, _minute[_st.wMinute].y);
	LineMake(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _second[_st.wSecond].x, _second[_st.wSecond].y);

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

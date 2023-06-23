#include "Stdafx.h"
#include "Report_15_1_MainGame.h"

/*
���� 1. �Ƴ��α� �ð�

- ��ħ / ��ħ / ��ħ

- ���� ����� SYSTEMTIME�� �̿��ؼ� �����.

- �ʼ� : �ð� ǥ��
*/

int currentX = WINSIZE_X / 2;
int currentY = WINSIZE_Y / 2;

HRESULT Report_15_1_MainGame::init(void)
{
	GameNode::init();

	_hour = { 0, 0 };
	_minute = { 0, 0 };
	_second = { 0, 0 };

	_radius = 300;

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

	_hour.x = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_st.wHour * 30.0f - 90)) * (_radius - 100);
	_hour.y = WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(_st.wHour * 30.0f - 90)) * (_radius - 100);

	_minute.x = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_st.wMinute * 6.0f - 90)) * (_radius - 50);
	_minute.y = WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(_st.wMinute * 6.0f - 90)) * (_radius - 50);

	_second.x = WINSIZE_X / 2 + cosf(DEGREE_RADIAN(_st.wSecond * 6.0f - 90)) * (_radius - 30);
	_second.y = WINSIZE_Y / 2 + sinf(DEGREE_RADIAN(_st.wSecond * 6.0f - 90)) * (_radius - 30);
}

void Report_15_1_MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();
	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==========================================================

	char strTime[128];

	sprintf_s(strTime, "%d�� %d�� %d��", _st.wHour, _st.wMinute, _st.wSecond);
	SetTextAlign(memDC, TA_CENTER);
	TextOut(memDC, WINSIZE_X / 2, 10, strTime, strlen(strTime));

	ElipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _radius + 20);
	ElipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _radius);
	ElipseMakeCenter(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, 10);

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

	LineMake(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _hour.x, _hour.y);
	LineMake(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _minute.x, _minute.y);
	LineMake(memDC, WINSIZE_X / 2, WINSIZE_Y / 2, _second.x, _second.y);

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

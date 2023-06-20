#include "Stdafx.h"
#include "Report_Horizontal_Shooting.h"

HRESULT Report_Horizontal_Shooting::init(void)
{
	return S_OK;
}

void Report_Horizontal_Shooting::release(void)
{
}

void Report_Horizontal_Shooting::update(void)
{
	//if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	//{
	//	isGameOver();
	//}
}

void Report_Horizontal_Shooting::render(HDC hdc)
{
	TextOut(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, "Horizontal", strlen("Horizontal"));
}

bool Report_Horizontal_Shooting::isGameOver(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		return true;
	}
}

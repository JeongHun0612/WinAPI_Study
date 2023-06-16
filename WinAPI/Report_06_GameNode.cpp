#include "Stdafx.h"
#include "Report_06_GameNode.h"

HRESULT Report_06_GameNode::init(void)
{
	SetTimer(_hWnd, 1, 10, NULL);

	return S_OK;
}

void Report_06_GameNode::release(void)
{
	KillTimer(_hWnd, 1);
}

void Report_06_GameNode::update(void)
{
	InvalidateRect(_hWnd, NULL, true);
}

void Report_06_GameNode::render(HDC hdc)
{
	//! Do Noting
}

LRESULT Report_06_GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		this->render(hdc);

		EndPaint(hWnd, &ps);
		break;

	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
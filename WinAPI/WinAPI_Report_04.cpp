#include "Stdafx.h"

/*
과제 1. 사각형 드래그 이동

- 마우스로 사각형을 자유롭게 움직일 수 있으면 된다.

※ T / F 사각형 범위 밖에서 마우스UP 이벤트가 발생할 시 오류


과제 2. 사각형 크기 조절

- 마우스로 사각형의 크기를 자유롭게 조정할 수 있으면 된다.

- 바탕화면에서 드래그 해보면서 똑같이 만들면 OK


과제 3. 사각형 4단 밀기

- 사각형의 갯수는 총 4개

- 마우스로 화면에 그려진 4개의 사각형 중 아무거나 선택해 자유롭게 움직인다.

- 마우스로 움직이고 있는 사각형이 다른 사각형과 충돌되면 충돌된 사각형은 "자연스럽게" 밀려난다.

※ 관성 / 그럴싸해 보이게
ㄴ 에어하키


한줄 조사.디자인 패턴

- 싱글톤 + @ 4개(게임에서 쓸만한 디자인 패턴을 조사)
*/

#define REPORT1			1
#define REPORT2			2
#define REPORT3			3

#define REPORT_TYPE		REPORT2

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);
bool isPointInRect(POINT pt, RECT rc);

RECT rcArray[4] = 
{
	RectMakeCenter(300, 300, 100, 100),
	RectMakeCenter(500, 300, 100, 100),
	RectMakeCenter(300, 500, 100, 100),
	RectMakeCenter(500, 500, 100, 100)
};

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	lpszCmdParam,
	int nCmdShow
)
{
	_hInstance = hInstance;

	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow(WINNAME, WINNAME, WINSTYLE, WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y, NULL, NULL, hInstance, NULL);

	// 클라이언트 영역의 사이즈를 정확히 잡아주기 위해
	setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

	ShowWindow(_hWnd, nCmdShow);

	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (int)message.lParam;
}

#if REPORT_TYPE == REPORT1 
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	static RECT rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);
	static RECT tempRC = { 0, 0, 0, 0 };
	static POINT pt = { 0, 0 };
	static bool isClick = false;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		DrawRectMake(hdc, rc);

		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		isClick = isPointInRect(pt, rc);
		tempRC = { pt.x - rc.left, pt.y - rc.top, rc.right - pt.x, rc.bottom - pt.y };

		break;

	case WM_MOUSEMOVE:
		if (isClick)
		{
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			if (pt.x - tempRC.left < 0 || pt.y - tempRC.top < 0 || pt.x + tempRC.right > WINSIZE_X || pt.y + tempRC.bottom > WINSIZE_Y)
			{
				isClick = false;
				break;
			}
			rc = { pt.x - tempRC.left, pt.y - tempRC.top, pt.x + tempRC.right, pt.y + tempRC.bottom };
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_LBUTTONUP:

		//if (isPointInRect(pt, rc))
		//{
		//	isClick = false;
		//}

		isClick = false;

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#elif REPORT_TYPE == REPORT2
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	static RECT rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);
	static RECT tempRC = { 0, 0, 0, 0 };
	static POINT pt = { 0, 0 };
	static bool isClick = false;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		DrawRectMake(hdc, rc);

		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		//if ((pt.x > rc.left && pt.x < rc.right) || (pt.x > rc.right && pt.x < rc.left))
		//{
		//	if ((pt.y > rc.top && pt.y < rc.bottom) || (pt.y < rc.top && pt.y > rc.bottom))
		//	{
		//		isClick = true;
		//	}
		//}

		isClick = isPointInRect(pt, rc);

		tempRC = { pt.x - rc.left, pt.y - rc.top, rc.right - pt.x, rc.bottom - pt.y };

		InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE:
		if (isClick)
		{
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			rc = { rc.left, rc.top, pt.x + tempRC.right, pt.y + tempRC.bottom };

			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_LBUTTONUP:
		isClick = false;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#else
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	static int curRC;
	static RECT tempRC = { 0, 0, 0, 0 };
	static POINT pt = { 0, 0 };
	static bool isClick = false;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		for (int i = 0; i < 4; i++)
		{
			DrawRectMake(hdc, rcArray[i]);
		}

		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONDOWN:

		if (isPointInRect(pt, rcArray[0]))
		{
			isClick = true;
			curRC = 0;
			tempRC = { pt.x - rcArray[0].left, pt.y - rcArray[0].top, rcArray[0].right - pt.x, rcArray[0].bottom - pt.y };
		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_MOUSEMOVE:
		if (isClick)
		{
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			rcArray[curRC] = { pt.x - tempRC.left, pt.y - tempRC.top, pt.x + tempRC.right, pt.y + tempRC.bottom };

			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_LBUTTONUP:
		isClick = false;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#endif


void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0, 0, width, height };

	// 실제 윈도우 크기 조정
	AdjustWindowRect(&rc, WINSTYLE, false);

	// 얻어온 렉트의 정보로 윈도우 사이즈 셋팅
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}

bool isPointInRect(POINT pt, RECT rc)
{
	if ((pt.x > rc.left && pt.x < rc.right) || (pt.x > rc.right && pt.x < rc.left))
	{
		if ((pt.y > rc.top && pt.y < rc.bottom) || (pt.y < rc.top && pt.y > rc.bottom))
		{
			return true;
		}
	}

	return false;
}


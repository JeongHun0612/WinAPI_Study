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
#define REPORT4			4

#define REPORT_TYPE		REPORT2

HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);
bool isPointInRect(POINT pt, RECT rc);

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
	char strPT[128];

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

		if (isPointInRect(pt, rc))
		{
			isClick = true;
			tempRC = { pt.x - rc.left, pt.y - rc.top, rc.right - pt.x, rc.bottom - pt.y };
		}
		break;

	case WM_MOUSEMOVE:
		if (isClick)
		{
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			rc = { pt.x - tempRC.left, pt.y - tempRC.top, pt.x + tempRC.right, pt.y + tempRC.bottom };
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;

	case WM_LBUTTONUP:

		if (isPointInRect(pt, rc))
		{
			isClick = false;
		}
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

	static int posX = WINSIZE_X / 2;
	static int posY = WINSIZE_Y / 2;
	static int width = 100;
	static int height = 100;

	static RECT rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, width, height);
	static POINT pt = { 0, 0 };
	static bool isClick = false;
	static char str[128] = "";

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		TextOut(hdc, 10, 10, str, strlen(str));
		DrawRectMake(hdc, rc);

		EndPaint(hWnd, &ps);
		break;

	case WM_LBUTTONDOWN:

		hdc = GetDC(hWnd);

		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);


		if ((pt.x > rc.left && pt.x < rc.right - (rc.right - rc.left) / 2) && pt.y < rc.bottom - (rc.bottom -  rc.top) / 2 && pt.y > rc.top)
		{
			wsprintf(str, "좌상단");
		}

		if (isPointInRect(pt, rc))
		{
			isClick = true;
		}

		InvalidateRect(hWnd, NULL, TRUE);

		ReleaseDC(hWnd, hdc);
		break;

	case WM_MOUSEMOVE:
		if (isClick)
		{
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			//rc = { pt.x - tempRC.left, pt.y - tempRC.top, pt.x + tempRC.right, pt.y + tempRC.bottom };
			//rc = { rc.left, rc.top, pt.x + tempRC.right, pt.y + tempRC.bottom};

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
	return pt.x > rc.left && pt.x < rc.right && pt.y > rc.top && pt.y < rc.bottom;
}


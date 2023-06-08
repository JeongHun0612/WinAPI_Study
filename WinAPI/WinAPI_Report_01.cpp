/*
23 / 06 / 08
------------------------------------------------------------------------------------ -
과제1. 구구단

- 예외처리 필수 : 구구단의 본질(2단 ~ 9단)

- 마우스 왼쪽 클릭을 했을 시 1단씩 생기고, 우 클릭을 하면 1단씩 지워진다.
ㄴ 3단 씩 개행 한다.

과제2. WinAPI 출력

- MoveToEX() + LineTo()를 이용한다.

★ 도형 관련 함수 사용 금지

- 1. 자기 이름 출력(한글)

- 2. UnrealEngine(영문)

- 마우스 왼쪽을 누르면 한글자씩 출력이 되면 우 클릭을 하면 한글자씩 지워진다.

- 현재 창 크기 기준 절반 이상의 사이즈로 해온다.

한줄 조사.
- SetTimer

- KillTimer

- InvalidateRect
*/


#include <Windows.h>
#include <tchar.h>

#define REPORT1			1
#define REPORT2			2

#define REPORT_TYPE		REPORT2

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
	wndClass.lpszClassName = _lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 400, 100, 800, 800, NULL, NULL, hInstance, NULL);

	ShowWindow(_hWnd, nCmdShow);

	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (int)message.lParam;
}

#if REPORT_TYPE	== REPORT1
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR str[256];
	RECT r;

	static int curDan = 1;
	int posX = 0;
	int posY = 0;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		break;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hWnd);

		if (curDan < 9)
		{
			curDan++;
		}

		for (int i = 2; i <= curDan; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				wsprintf(str, TEXT("%d X %d = %d"), i, j, i * j);
				TextOut(hdc, posX, posY + (j * 20), str, strlen(str));
			}

			posX += 100;

			if (i % 3 == 1)
			{
				posX = 0;
				posY += 200;
			}
		}
		ReleaseDC(hWnd, hdc);
		break;
	case WM_RBUTTONDOWN:
	{
		hdc = GetDC(hWnd);

		int calcDanX = ((curDan - 2) % 3);
		int calcDanY = ((curDan - 2) / 3);

		r = { calcDanX * 100, calcDanY * 200, 115 + (calcDanX * 100), 220 + (calcDanY * 220) };
		InvalidateRect(hWnd, &r, TRUE);

		if (curDan > 1)
		{
			curDan--;
		}

		ReleaseDC(hWnd, hdc);

		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#else REPORT_TYPE == REPORT2
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int posX = 0;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// ㅅ
		MoveToEx(hdc, 50, 125, NULL);
		LineTo(hdc, 100, 50);
		LineTo(hdc, 150, 125);

		// ㅗ
		MoveToEx(hdc, 100, 100, NULL);
		LineTo(hdc, 100, 150);
		MoveToEx(hdc, 50, 150, NULL);
		LineTo(hdc, 150, 150);


		EndPaint(hWnd, &ps);

		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#endif

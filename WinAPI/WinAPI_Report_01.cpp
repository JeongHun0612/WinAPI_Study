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
#include <math.h>

#define PI		3.1415926535
#define DEG2RAD(deg) (deg * PI) / 180

#define REPORT1			1
#define REPORT2			2

#define REPORT_TYPE		REPORT2


enum class ECircleType
{
	UP,
	DOWN
};

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void drawCircle(HDC hdc, int centerX, int centerY, int radius);
void drawSemiCircle(HDC hdc, int centerX, int centerY, int radius, ECircleType type);

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
	//PAINTSTRUCT ps;
	RECT r;
	static int charCount = 0;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		break;
	case WM_LBUTTONDOWN:
	{
		hdc = GetDC(hWnd);

		if (charCount < 3)
		{
			charCount++;
		}

		switch (charCount)
		{
		case 1:
			// 송
			MoveToEx(hdc, 50, 125, NULL);
			LineTo(hdc, 100, 50);
			LineTo(hdc, 150, 125);
			MoveToEx(hdc, 100, 100, NULL);
			LineTo(hdc, 100, 150);
			MoveToEx(hdc, 50, 150, NULL);
			LineTo(hdc, 150, 150);
			drawCircle(hdc, 100, 200, 30);
			break;
		case 2:
			// 정
			MoveToEx(hdc, 200, 50, NULL);
			LineTo(hdc, 270, 50);
			MoveToEx(hdc, 200, 135, NULL);
			LineTo(hdc, 235, 50);
			LineTo(hdc, 270, 135);
			MoveToEx(hdc, 270, 87, NULL);
			LineTo(hdc, 300, 87);
			MoveToEx(hdc, 300, 50, NULL);
			LineTo(hdc, 300, 125);
			drawCircle(hdc, 260, 200, 30);
			break;
		case 3:
			// 훈
			MoveToEx(hdc, 400, 50, NULL);
			LineTo(hdc, 400, 70);
			MoveToEx(hdc, 350, 70, NULL);
			LineTo(hdc, 450, 70);
			drawCircle(hdc, 400, 110, 30);
			MoveToEx(hdc, 350, 150, NULL);
			LineTo(hdc, 450, 150);
			MoveToEx(hdc, 400, 150, NULL);
			LineTo(hdc, 400, 190);
			MoveToEx(hdc, 365, 180, NULL);
			LineTo(hdc, 365, 230);
			LineTo(hdc, 435, 230);
			break;
		}
		ReleaseDC(hWnd, hdc);

		break;
	}
	case WM_RBUTTONDOWN:
	{
		hdc = GetDC(hWnd);

		int startX = 50;
		int startY = 150;

		if (0 < charCount)
		{
			charCount--;
		}

		r = { startX + (charCount * 150), 50, startY + (charCount * 200), 235 };
		InvalidateRect(hWnd, &r, TRUE);


		ReleaseDC(hWnd, hdc);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

void drawCircle(HDC hdc, int centerX, int centerY, int radius)
{
	MoveToEx(hdc, centerX + radius, centerY, NULL);
	for (int i = 0; i <= 360; i++)
	{
		LineTo(hdc, centerX + (cos(DEG2RAD(i)) * radius), centerY + (sin(DEG2RAD(i)) * radius));
	}
}

void drawSemiCircle(HDC hdc, int centerX, int centerY, int radius, ECircleType type)
{
	switch (type)
	{
	case ECircleType::UP:
		//MoveToEx(hdc, centerX - radius, centerY, NULL);
		for (int i = 180; i <= 360; i++)
		{
			LineTo(hdc, centerX + cos(DEG2RAD(i)) * radius, centerY + sin(DEG2RAD(i)) * radius);
		}
		break;
	case ECircleType::DOWN:
		//MoveToEx(hdc, centerX + radius, centerY, NULL);
		for (int i = 0; i <= 180; i++)
		{
			LineTo(hdc, centerX + cos(DEG2RAD(i)) * radius, centerY + sin(DEG2RAD(i)) * radius);
		}
		break;
	}
}

#endif

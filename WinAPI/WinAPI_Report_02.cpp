/*
23/06/09
------------------------------------------------------------------------------------ -
과제1. 오망성 출력

- 오망성을 마법진 처럼 만들어 온다.

- 양식은 자유지만 본인이 생각했을때 가장 효율적인 방법으로
ㄴ 특히 배열은 무조건 사용해본다.


과제2. 애플 로고 출력

- SetPixel을 이용해서 만든다.

- Ellipse를 사용하면 외각을 따는게 쉽다.


과제3. 사각형 이동

- 방향키를 통해 사각형을 움직인다.

- 예외처리 : 사각형은 화면 밖으로 나갈 수 없다.


과제4. 사각형 2개 움직이기

- 총 사각형 갯수 : 2개

- 하나는 움직일 수 있는 사각형 / 다른 하나는 움직일 수 없는 사각형

- 움직일 수 없는 사각형을 움직일 수 있는 사각형을 밀어낼 수 있으면 된다.

- 2개의 사각형을 초기 위치로 돌리는 기능도 추가한다.

- 예외처리 : 2개의 사각형은 화면 밖으로 나갈 수 없다.

※ 별다른 언급을 하기 전까지는 충돌 함수 사용 금지
*/

#include <Windows.h>
#include <tchar.h>
#include <math.h>

#define SCR_WIDTH		800
#define SCR_HEIGHT		800

#define PI		3.1415926535
#define DEG2RAD(deg) (deg * PI) / 180

#define REPORT1			1
#define REPORT2			2
#define REPORT3			3
#define REPORT4			4

#define REPORT_TYPE		REPORT3

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

	_hWnd = CreateWindow(_lpszClass, _lpszClass, WS_OVERLAPPEDWINDOW, 400, 100, SCR_WIDTH, SCR_HEIGHT, NULL, NULL, hInstance, NULL);

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

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		int curPosX = 400;
		int curPosY = 200;
		float length = 380;

		int starDeg[5] = { 72 , 216, 0, 144, 288 };

		Ellipse(hdc, 180, 180, 620, 620);
		Ellipse(hdc, 200, 200, 600, 600);
		MoveToEx(hdc, curPosX, curPosY, NULL);

		for (int i = 0; i < 5; i++)
		{
			LineTo(hdc, curPosX + cos(DEG2RAD(starDeg[i])) * length, curPosY + sin(DEG2RAD(starDeg[i])) * length);

			curPosX += cos(DEG2RAD(starDeg[i])) * length;
			curPosY += sin(DEG2RAD(starDeg[i])) * length;
		}

		curPosX = 400;
		curPosY = 200;
		length = 234;

		int pentagonDeg[5] = { 36 , 108, 180, 252, 324 };

		for (int i = 0; i < 5; i++)
		{
			LineTo(hdc, curPosX + cos(DEG2RAD(pentagonDeg[i])) * length, curPosY + sin(DEG2RAD(pentagonDeg[i])) * length);

			curPosX += cos(DEG2RAD(pentagonDeg[i])) * length;
			curPosY += sin(DEG2RAD(pentagonDeg[i])) * length;
		}


		EndPaint(hWnd, &ps);
		break;
	}
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

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}


#elif REPORT_TYPE == REPORT3
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc = { 0, 0, 0, 0 };

	static int posX = 50;
	static int posY = 50;
	int width = 100;
	int height = 100;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, posX, posY, posX + width, posY + height);
		EndPaint(hWnd, &ps);
		break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_UP:
			if (posY < 1) break;
			rc = { posX, posY + height, posX + width, 1 };
			posY--;
			break;
		case VK_DOWN:
			if (posY + height > SCR_HEIGHT - 40) break;
			rc = { posX, posY + 1, posX + width, 1 };
			posY++;
			break;
		case VK_LEFT:
			if (posX < 1) break;
			rc = { posX + width, posY, 1, posY + height };
			posX--;
			break;
		case VK_RIGHT:
			if (posX + width > SCR_WIDTH - 17) break;
			rc = { posX, posY, 1, posY + height };
			posX++;
			break;
		}

		InvalidateRect(hWnd, &rc, TRUE);
		//Rectangle(hdc, posX, posY, posX + width, posY + height);

		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#elif REPORT_TYPE == REPORT4
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#endif

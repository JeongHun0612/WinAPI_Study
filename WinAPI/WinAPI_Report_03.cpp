#include "Stdafx.h"

//과제 1. 사각형 영혼 밀어넣기
//
//- 시작은 큰 사각형 2개와 작은 사각형 1개
//
//- 내가 움직일 수 있는 사각형 안에는 작은 사각형이 들어 있다.
//
//- 큰 사각형을 움직이면 작은 사각형 역시 움직이는 버전 1개 / 움직이지 않는 버전 1개
//ㄴ 총 2가지 버전
//ㄴ 예외처리 : 작은 사각형은 큰 사각형을 벗어날 수 없다.
//
//- 큰 사각형끼리 충돌이 되면 작은 사각형은 충돌이 된 반대편 사각형으로 이동한다.
//
//※ 핵심은 움직일 수 있는 주도권은 작은 사각형을 가지고 있는 "큰 사각형"
//
//예외처리 : 큰 사각형끼리의 모서리에 대한 정밀도를 예외 처리한다.

#define SCR_WIDTH		800
#define SCR_HEIGHT		800

#define REPORT1			1
#define REPORT2			2

#define REPORT_TYPE		REPORT2

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int width = 100;
int height = 100;
int sWidth = 50;
int sHeight = 50;
int dist = 5;

RECT bigRC1 = RectMakeCenter(400, 400, width, height);
RECT bigRC2 = RectMakeCenter(500, 400, width, height);
RECT smallRC = RectMakeCenter(400, 400, sWidth, sHeight);

void MoveToRect(int direction, RECT *rc)
{
	switch (direction)
	{
	case VK_UP:
		rc->top -= dist;
		rc->bottom -= dist;
		break;
	case VK_DOWN:
		rc->top += dist;
		rc->bottom += dist;
		break;
	case VK_LEFT:
		rc->left -= dist;
		rc->right -= dist;
		break;
	case VK_RIGHT:
		rc->left += dist;
		rc->right += dist;
		break;
	}
}

void TempRectAngle(RECT* destRC, RECT* sourRC)
{
	RECT temp;

	temp = *destRC;
	*destRC = *sourRC;
	*sourRC = temp;
}

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

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		DrawRectMake(hdc, bigRC1);
		DrawRectMake(hdc, bigRC2);
		DrawRectMake(hdc, smallRC);

		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_UP:
			if (bigRC1.top < 1) break;

			MoveToRect(VK_UP, &bigRC1);
			MoveToRect(VK_UP, &smallRC);

			if (abs(bigRC1.top - bigRC2.bottom) <= dist && (bigRC1.left < bigRC2.right) && (bigRC1.right > bigRC2.left))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;

		case VK_DOWN:
			if (bigRC1.bottom > SCR_HEIGHT - 40) break;

			MoveToRect(VK_DOWN, &bigRC1);
			MoveToRect(VK_DOWN, &smallRC);

			if (abs(bigRC1.bottom - bigRC2.top) <= dist && (bigRC1.left < bigRC2.right) && (bigRC1.right > bigRC2.left))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;

		case VK_LEFT:
			if (bigRC1.left < 1) break;

			MoveToRect(VK_LEFT, &bigRC1);
			MoveToRect(VK_LEFT, &smallRC);

			if (abs(bigRC1.left - bigRC2.right) <= dist && (bigRC1.bottom > bigRC2.top) && (bigRC1.top < bigRC2.bottom))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;

		case VK_RIGHT:
			if (bigRC1.right > SCR_WIDTH - 17) break;

			MoveToRect(VK_RIGHT, &bigRC1);
			MoveToRect(VK_RIGHT, &smallRC);

			if (abs(bigRC1.right - bigRC2.left) <= dist && (bigRC1.bottom > bigRC2.top) && (bigRC1.top < bigRC2.bottom))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;
		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
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

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		DrawRectMake(hdc, bigRC1);
		DrawRectMake(hdc, bigRC2);
		DrawRectMake(hdc, smallRC);

		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_UP:
			if (bigRC1.top < 1) break;

			if (bigRC1.bottom == smallRC.bottom)
			{
				MoveToRect(VK_UP, &smallRC);
			}

			MoveToRect(VK_UP, &bigRC1);

			if (abs(bigRC1.top - bigRC2.bottom) <= dist && (bigRC1.left < bigRC2.right) && (bigRC1.right > bigRC2.left))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;

		case VK_DOWN:
			if (bigRC1.bottom > SCR_HEIGHT - 40) break;

			if (bigRC1.top == smallRC.top)
			{
				MoveToRect(VK_DOWN, &smallRC);
			}

			MoveToRect(VK_DOWN, &bigRC1);

			if (abs(bigRC1.bottom - bigRC2.top) <= dist && (bigRC1.left < bigRC2.right) && (bigRC1.right > bigRC2.left))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;

		case VK_LEFT:
			if (bigRC1.left < 1) break;

			if (bigRC1.right == smallRC.right)
			{
				MoveToRect(VK_LEFT, &smallRC);
			}

			MoveToRect(VK_LEFT, &bigRC1);

			if (abs(bigRC1.left - bigRC2.right) <= dist && (bigRC1.bottom > bigRC2.top) && (bigRC1.top < bigRC2.bottom))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;

		case VK_RIGHT:
			if (bigRC1.right > SCR_WIDTH - 17) break;

			if (bigRC1.left == smallRC.left)
			{
				MoveToRect(VK_RIGHT, &smallRC);
			}

			MoveToRect(VK_RIGHT, &bigRC1);

			if (abs(bigRC1.right - bigRC2.left) <= dist && (bigRC1.bottom > bigRC2.top) && (bigRC1.top < bigRC2.bottom))
			{
				TempRectAngle(&bigRC1, &bigRC2);
				smallRC = { bigRC1.left + sWidth / 2, bigRC1.top + sHeight / 2, bigRC1.right - sWidth / 2, bigRC1.bottom - sHeight / 2 };
			}
			break;
		}

		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#endif

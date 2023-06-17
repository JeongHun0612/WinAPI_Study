#include "Stdafx.h"

//���� 1. �簢�� ��ȥ �о�ֱ�
//
//- ������ ū �簢�� 2���� ���� �簢�� 1��
//
//- ���� ������ �� �ִ� �簢�� �ȿ��� ���� �簢���� ��� �ִ�.
//
//- ū �簢���� �����̸� ���� �簢�� ���� �����̴� ���� 1�� / �������� �ʴ� ���� 1��
//�� �� 2���� ����
//�� ����ó�� : ���� �簢���� ū �簢���� ��� �� ����.
//
//- ū �簢������ �浹�� �Ǹ� ���� �簢���� �浹�� �� �ݴ��� �簢������ �̵��Ѵ�.
//
//�� �ٽ��� ������ �� �ִ� �ֵ����� ���� �簢���� ������ �ִ� "ū �簢��"
//
//����ó�� : ū �簢�������� �𼭸��� ���� ���е��� ���� ó���Ѵ�.

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

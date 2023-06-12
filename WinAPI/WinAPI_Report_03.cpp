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

HINSTANCE _hInstance;
HWND _hWnd;
LPTSTR _lpszClass = TEXT("Windows API");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

bool OnCollisionBox(int key, RECT rc1, RECT rc2)
{
	switch (key)
	{
	case VK_UP:
		if (rc1.top != rc2.bottom || rc1.bottom < rc2.top)
		{
			return false;
		}
		else
		{
			return (rc1.left < rc2.right) && (rc1.right > rc2.left);
		}
	case VK_DOWN:
		if (rc1.bottom != rc2.top || rc1.top > rc2.bottom)
		{
			return false;
		}
		else
		{
			return (rc1.left < rc2.right) && (rc1.right > rc2.left);
		}
	case VK_LEFT:
		if (rc1.left != rc2.right || rc1.right < rc2.left)
		{
			return false;
		}
		else
		{
			return (rc1.bottom > rc2.top) && (rc1.top < rc2.bottom);
		}
	case VK_RIGHT:
		if (rc1.right != rc2.left || rc1.left > rc2.right)
		{
			return false;
		}
		else
		{
			return (rc1.bottom > rc2.top) && (rc1.top < rc2.bottom);
		}
	default:
		return false;
	}

	//if ((rc1.top == rc2.bottom || rc1.top <= rc2.bottom) && (rc1.left < rc2.right && rc1.right > rc2.left))
	//{
	//	return true;
	//}
	//else if ((rc1.top == rc2.bottom || rc1.bottom >= rc2.top) && (rc1.left < rc2.right && rc1.right > rc2.left))
	//{
	//	return true;
	//}
	//else if ((rc1.left == rc2.right || rc1.left <= rc2.right) && (rc1.bottom > rc2.top && rc1.top < rc2.bottom))
	//{
	//	return true;
	//}
	//else if ((rc1.left == rc2.right || rc1.right >= rc2.left) && (rc1.bottom > rc2.top && rc1.top < rc2.bottom))
	//{
	//	return true;
	//}

	//return false;


	//switch (key)
	//{
	//case VK_UP:
	//		return (rc1.top == rc2.bottom || rc1.top <= rc2.bottom) && (rc1.left < rc2.right&& rc1.right > rc2.left);
	//case VK_DOWN:
	//	if (rc1.bottom <= rc2.top)
	//	{
	//		return rc1.bottom >= rc2.top && (rc1.left < rc2.right&& rc1.right > rc2.left);
	//	}
	//case VK_LEFT:
	//	if (rc1.left >= rc2.right)
	//	{
	//		return rc1.left <= rc2.right && (rc1.bottom > rc2.top && rc1.top < rc2.bottom);
	//	}
	//case VK_RIGHT:
	//	if (rc1.right <= rc2.left)
	//	{
	//		return rc1.right >= rc2.left && (rc1.bottom > rc2.top && rc1.top < rc2.bottom);
	//	}
	//}

	//return false;


	//if (rc1.top <= rc2.bottom && (rc1.left < rc2.right && rc1.right > rc2.left))
	//{
	//	return true;
	//}
	//else if (rc1.bottom >= rc2.top && (rc1.left < rc2.right && rc1.right > rc2.left))
	//{
	//	return true;
	//}
	//else if (rc1.left <= rc2.right && (rc1.bottom > rc2.top && rc1.top < rc2.bottom))
	//{
	//	return true;
	//}
	//else if (rc1.right >= rc2.left && (rc1.bottom > rc2.top && rc1.top < rc2.bottom))
	//{
	//	return true;
	//}

	//return false;


	/*if (rc1.top <= rc2.bottom && rc1.left < rc2.right && rc1.right > rc2.left)
	if (rc1.bottom >= rc2.top && rc1.left < rc2.right && rc1.right > rc2.left)

	if (rc1.left <= rc2.right && rc1.bottom > rc2.top && rc1.top < rc2.bottom)
	if (rc1.right >= rc2.left && rc1.bottom > rc2.top && rc1.top < rc2.bottom)*/
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

//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	RECT playerRC;
//	RECT enemyRC;
//	RECT smallRC;
//
//	static int curPX = 300;
//	static int curPY = 300;
//	static int curEX = 500;
//	static int curEY = 500;
//	int width = 100;
//	int height = 100;
//	int dist = 10;
//	static bool isPlayer = true;
//
//	playerRC = RectMakeCenter(curPX, curPY, width, height);
//	enemyRC = RectMakeCenter(curEX, curEY, width, height);
//	smallRC = RectMakeCenter(curPX, curPY, width / 2, height / 2);
//
//	switch (iMessage)
//	{
//	case WM_CREATE:
//		break;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//
//		DrawRectMake(hdc, playerRC);
//		DrawRectMake(hdc, enemyRC);
//		DrawRectMake(hdc, smallRC);
//
//		EndPaint(hWnd, &ps);
//		break;
//	case WM_KEYDOWN:
//	{
//		switch (wParam)
//		{
//		case VK_UP:
//			if (curPY < 1 || curEY < 1) break;
//
//			if (curPY == curEY + height && curPX + width > curEX + 1 && curPX < curEX + width)
//			{
//				curPY = curEY;
//			}
//			curPY -= dist;
//
//			break;
//		case VK_DOWN:
//			if (curPY + height > SCR_HEIGHT - 40) break;
//			if (isPlayer)
//			{
//				curPY += dist;
//			}
//			else
//			{
//				curEY += dist;
//			}
//
//			if (curPY + height == curEY && curPX + width > curEX + 1 && curPX < curEX + width)
//			{
//				isPlayer = !isPlayer;
//			}
//			break;
//		case VK_LEFT:
//			if (curPX < 1) break;
//
//			if (isPlayer)
//			{
//				curPX -= dist;
//			}
//			else
//			{
//				curEX -= dist;
//			}
//
//			if (curPX == curEX + width && curPY + height > curEY + 1 && curPY < curEY + height)
//			{
//				isPlayer = !isPlayer;
//			}
//			break;
//		case VK_RIGHT:
//			if (curPX + width > SCR_WIDTH - 17) break;
//
//			if (isPlayer)
//			{
//				curPX += dist;
//			}
//			else
//			{
//				curEX += dist;
//			}
//
//			if (curPX + width == curEX && curPY + height > curEY + 1 && curPY < curEY + height)
//			{
//				isPlayer = !isPlayer;
//			}
//
//			break;
//		}
//
//		InvalidateRect(hWnd, NULL, TRUE);
//		break;
//	}
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//
//	return DefWindowProc(hWnd, iMessage, wParam, lParam);
//}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc1;
	RECT rc2;

	static int curPX = 300;
	static int curPY = 100;
	static int curEX = 500;
	static int curEY = 100;
	int width = 100;
	int height = 100;
	int dist = 7;
	static bool isPlayer = true;

	rc1 = { curPX, curPY, curPX + width, curPY + height };
	rc2 = { curEX, curEY, curEX + width, curEY + height };

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		DrawRectMake(hdc, rc1);
		DrawRectMake(hdc, rc2);

		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_UP:
			if (curPY < 1 || curEY < 1) break;

			if (OnCollisionBox(VK_UP, rc1, rc2))
			{
				curEY -= dist;
			}
			curPY -= dist;

			break;
		case VK_DOWN:
			if (curPY + height > SCR_HEIGHT - 40) break;

			if (OnCollisionBox(VK_DOWN, rc1, rc2))
			{
				curEY += dist;
			}
			curPY += dist;

			break;
		case VK_LEFT:
			if (curPX < 1) break;

			if (OnCollisionBox(VK_LEFT, rc1, rc2))
			{
				curEX -= dist;
			}
			curPX -= dist;

			break;
		case VK_RIGHT:
			if (curPX + width > SCR_WIDTH - 17) break;

			if (OnCollisionBox(VK_RIGHT, rc1, rc2))
			{
				curEX += dist;
			}
			curPX += dist;

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
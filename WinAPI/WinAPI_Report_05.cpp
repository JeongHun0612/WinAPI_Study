#include "Stdafx.h"
/*
23/06/14
-------------------------------------------------------------------------------------
���� 1. ���콺�� ������ ���� ���

- ���콺�� Ŭ���� ��ǥ�� ������ ������ ����Ѵ�.

- ������ ũ�� + ������ ��� + ������ �������� ��� ������ ó���Ѵ�.

- ������ ���� : �簢��, ��, �ﰢ�� �� �ٰ���

�� �ﰢ�� + �ٰ���->Polygon() + �迭�� �̿��Ѵ�.


<�Ⱓ 2��>
���� 2. ������ Ȱ���� �� �� �׷�����

- ������ Ȱ���Ѵ�.


���� 3. �� Ƣ���(�̱��� Ȱ���� ����)

- ū �簢���ȿ� ���� ���� �ִ�.

- �������� ū �簢�� �ȿ��� ������� ���ٸ� �Է��� ��� �簢�� �鿡 ƨ��鼭 ���������� �����δ�.

- ū �簢���� Ű���� �Է��� ������ ũ�⸦ �ø��ų� ���� �� �ִ�.

- ũ�Ⱑ �þ�ų� �پ��� �翬�� ���ʿ� �ִ� ���� ������ �޴´�.
�� ���콺 �� Ŭ�� �� : �� �ӵ� ����
�� ���콺 �� Ŭ�� �� : �� �ӵ� ����

���� ����.
- GetAsyncKeyState
�� ���°� ���� Ȯ��
*/

#define PI		3.1415926535
#define DEG2RAD(deg) (deg * PI) / 180

#define REPORT1			1
#define REPORT2			2
#define REPORT3			3

#define REPORT_TYPE		REPORT3

HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

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

	// Ŭ���̾�Ʈ ������ ����� ��Ȯ�� ����ֱ� ����
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

	static POINT polygonPoint[5];
	static POINT pt = { 0, 0 };

	int rndNum = 0;
	int radius = 0;
	int degree = 0;
	int internalAngle = 0;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		break;

	case WM_LBUTTONDOWN:
	{
		hdc = GetDC(hWnd);

		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		rndNum = RND->getFromIntTo(2, 6);

		if (rndNum == 2)
		{
			EllipseMakeCenter(hdc, pt.x, pt.y, RND->getFromIntTo(100, WINSIZE_X / 2), RND->getFromIntTo(100, WINSIZE_X / 2));
		}
		else
		{
			internalAngle = 360 / rndNum;
			radius = RND->getFromIntTo(100, WINSIZE_X / 4);

			for (int i = 0; i < rndNum; i++)
			{
				degree = RND->getFromIntTo(internalAngle * i, internalAngle * (i + 1));

				polygonPoint[i].x = pt.x + (cos(DEG2RAD(degree)) * radius);
				polygonPoint[i].y = pt.y + (sin(DEG2RAD(degree)) * radius);
			}

			Polygon(hdc, polygonPoint, rndNum);
		}

		ReleaseDC(hWnd, hdc);

		break;
	}
	case WM_RBUTTONDOWN:
		InvalidateRect(hWnd, NULL, TRUE);
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
#else
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	static RECT rc;
	static RECT invalRc;

	int rcWidth = 400;
	int rcHeight = 400;
	int dist = 5;

	static int ballX = WINSIZE_X / 2;
	static int ballY = WINSIZE_Y / 2;
	int ballWidth = 20;
	int ballHeight = 20;

	static int moveX = -1;
	static int moveY = -1;
	static int ballSpeed = 1;

	switch (iMessage)
	{
	case WM_CREATE:
		rc = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, rcWidth, rcHeight);
		invalRc = { rc.left - 5, rc.top - 5, rc.right + 5, rc.bottom + 5 };
		SetTimer(hWnd, 1, 10, NULL);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		DrawRectMake(hdc, rc);
		EllipseMake(hdc, ballX, ballY, ballWidth, ballHeight);

		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		if (ballX <= rc.left || ballX + ballWidth >= rc.right)
		{
			moveX = -moveX;
		}
		if (ballY <= rc.top || ballY + ballHeight >= rc.bottom)
		{
			moveY = -moveY;
		}
		
		ballX += moveX * ballSpeed;
		ballY += moveY * ballSpeed;

		InvalidateRect(hWnd, &invalRc, true);
		break;
	case WM_LBUTTONDOWN:
		if (ballSpeed == 10) break;
		ballSpeed++;
		break;
	case WM_RBUTTONDOWN:
		if (ballSpeed == 1) break;
		ballSpeed--;
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			if (rc.right < rc.left + 50) break;
			rc.right -= dist;
			break;
		case VK_RIGHT:
			if (rc.right >= rc.left + rcWidth) break;
			rc.right += dist;
			break;
		case VK_UP:
			if (rc.bottom < rc.top + 50) break;
			rc.bottom -= dist;
			break;
		case VK_DOWN:
			if (rc.bottom >= rc.top + rcHeight) break;
			rc.bottom += dist;
			break;
		}

		invalRc = { rc.left - 5, rc.top - 5, rc.right + 5, rc.bottom + 5 };

		InvalidateRect(hWnd, &invalRc, true);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

#endif


void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0, 0, width, height };

	// ���� ������ ũ�� ����
	AdjustWindowRect(&rc, WINSTYLE, false);

	// ���� ��Ʈ�� ������ ������ ������ ����
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}
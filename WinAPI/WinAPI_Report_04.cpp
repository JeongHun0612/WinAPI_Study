#include "Stdafx.h"

/*
���� 1. �簢�� �巡�� �̵�

- ���콺�� �簢���� �����Ӱ� ������ �� ������ �ȴ�.

�� T / F �簢�� ���� �ۿ��� ���콺UP �̺�Ʈ�� �߻��� �� ����


���� 2. �簢�� ũ�� ����

- ���콺�� �簢���� ũ�⸦ �����Ӱ� ������ �� ������ �ȴ�.

- ����ȭ�鿡�� �巡�� �غ��鼭 �Ȱ��� ����� OK


���� 3. �簢�� 4�� �б�

- �簢���� ������ �� 4��

- ���콺�� ȭ�鿡 �׷��� 4���� �簢�� �� �ƹ��ų� ������ �����Ӱ� �����δ�.

- ���콺�� �����̰� �ִ� �簢���� �ٸ� �簢���� �浹�Ǹ� �浹�� �簢���� "�ڿ�������" �з�����.

�� ���� / �׷����� ���̰�
�� ������Ű


���� ����.������ ����

- �̱��� + @ 4��(���ӿ��� ������ ������ ������ ����)
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
			wsprintf(str, "�»��");
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

	// ���� ������ ũ�� ����
	AdjustWindowRect(&rc, WINSTYLE, false);

	// ���� ��Ʈ�� ������ ������ ������ ����
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}

bool isPointInRect(POINT pt, RECT rc)
{
	return pt.x > rc.left && pt.x < rc.right && pt.y > rc.top && pt.y < rc.bottom;
}


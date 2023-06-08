/*
23 / 06 / 08
------------------------------------------------------------------------------------ -
����1. ������

- ����ó�� �ʼ� : �������� ����(2�� ~ 9��)

- ���콺 ���� Ŭ���� ���� �� 1�ܾ� �����, �� Ŭ���� �ϸ� 1�ܾ� ��������.
�� 3�� �� ���� �Ѵ�.

����2. WinAPI ���

- MoveToEX() + LineTo()�� �̿��Ѵ�.

�� ���� ���� �Լ� ��� ����

- 1. �ڱ� �̸� ���(�ѱ�)

- 2. UnrealEngine(����)

- ���콺 ������ ������ �ѱ��ھ� ����� �Ǹ� �� Ŭ���� �ϸ� �ѱ��ھ� ��������.

- ���� â ũ�� ���� ���� �̻��� ������� �ؿ´�.

���� ����.
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
		// ��
		MoveToEx(hdc, 50, 125, NULL);
		LineTo(hdc, 100, 50);
		LineTo(hdc, 150, 125);

		// ��
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

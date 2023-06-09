/*
23/06/09
------------------------------------------------------------------------------------ -
����1. ������ ���

- �������� ������ ó�� ����� �´�.

- ����� �������� ������ ���������� ���� ȿ������ �������
�� Ư�� �迭�� ������ ����غ���.


����2. ���� �ΰ� ���

- SetPixel�� �̿��ؼ� �����.

- Ellipse�� ����ϸ� �ܰ��� ���°� ����.


����3. �簢�� �̵�

- ����Ű�� ���� �簢���� �����δ�.

- ����ó�� : �簢���� ȭ�� ������ ���� �� ����.


����4. �簢�� 2�� �����̱�

- �� �簢�� ���� : 2��

- �ϳ��� ������ �� �ִ� �簢�� / �ٸ� �ϳ��� ������ �� ���� �簢��

- ������ �� ���� �簢���� ������ �� �ִ� �簢���� �о �� ������ �ȴ�.

- 2���� �簢���� �ʱ� ��ġ�� ������ ��ɵ� �߰��Ѵ�.

- ����ó�� : 2���� �簢���� ȭ�� ������ ���� �� ����.

�� ���ٸ� ����� �ϱ� �������� �浹 �Լ� ��� ����
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

#include "Stdafx.h"
/*
23/06/14
------------------------------------------------------------------------------------ -
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

#define REPORT_TYPE		REPORT1

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

	static POINT ptA[5];
	static POINT pt = { 0, 0 };

	static bool isClick = false;
	static int rndNum = 0;

	//static POINT PolygonPoint[6] = { {100,100}, {250,50}, {400,100}, {550,350}, {400,400}, {50,300} };

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

		int radius = 100;


		ptA[0].x = pt.x + (cos(DEG2RAD(30)) * radius);
		ptA[0].y = pt.y + (sin(DEG2RAD(30)) * radius);

		for (int i = 0; i < 5; i++)
		{

			//LineTo(hdc, centerX + (cos(DEG2RAD(i)) * radius), centerY + (sin(DEG2RAD(i)) * radius));

			/*pt.x + cos(DEG2RAD(RND->getInt(360)) * radius);*/

			ptA[i] = { (LONG)(cos(DEG2RAD(RND->getInt(360)) * radius), pt.y };
		}
	

		//polygonPoint[0] = { pt.x, pt.y };

		//int rndNum = RND->getInt(5) + 2;

		//for (int i = 1; i < rndNum; i++)
		//{
		//	polygonPoint[i] = { RND->getInt(800), RND->getInt(800) };
		//}

		//switch (rndNum)
		//{
		//case 2:
		//	EllipseMakeCenter(hdc, pt.x, pt.y, RND->getFromIntTo(100, 400), RND->getFromIntTo(100, 400));
		//	break;
		//case 3:
		//	Polygon(hdc, polygonPoint, 3);
		//	break;
		//case 4:
		//	Polygon(hdc, polygonPoint, 4);
		//	break;
		//case 5:
		//	Polygon(hdc, polygonPoint, 5);
		//	break;
		//case 6:
		//	Polygon(hdc, polygonPoint, 6);
		//	break;
		//}

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
	if ((pt.x > rc.left && pt.x < rc.right) || (pt.x > rc.right && pt.x < rc.left))
	{
		if ((pt.y > rc.top && pt.y < rc.bottom) || (pt.y < rc.top && pt.y > rc.bottom))
		{
			return true;
		}
	}

	return false;
}

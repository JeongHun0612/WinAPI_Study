#include "Stdafx.h"
/*
23/06/14
-------------------------------------------------------------------------------------
과제 1. 마우스로 무작위 도형 출력

- 마우스로 클릭한 좌표에 무작위 도형을 출력한다.

- 도형의 크기 + 도형의 모양 + 도형의 종류까지 모두 무작위 처리한다.

- 도형의 종류 : 사각형, 원, 삼각형 및 다각형

※ 삼각형 + 다각형->Polygon() + 배열을 이용한다.


<기간 2일>
과제 2. 도형을 활용한 내 얼굴 그려오기

- 도형을 활용한다.


과제 3. 공 튀기기(싱글톤 활용해 보기)

- 큰 사각형안에 작은 공이 있다.

- 작은공은 큰 사각형 안에서 사용자의 별다른 입력이 없어도 사각형 면에 튕기면서 지속적으로 움직인다.

- 큰 사각형은 키보드 입력을 받으며 크기를 늘리거나 줄일 수 있다.

- 크기가 늘어나거나 줄어들면 당연히 안쪽에 있는 공도 영향을 받는다.
ㄴ 마우스 왼 클릭 시 : 공 속도 증가
ㄴ 마우스 우 클릭 시 : 공 속도 감소

한줄 조사.
- GetAsyncKeyState
ㄴ 상태값 까지 확인
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

	// 클라이언트 영역의 사이즈를 정확히 잡아주기 위해
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

	// 실제 윈도우 크기 조정
	AdjustWindowRect(&rc, WINSTYLE, false);

	// 얻어온 렉트의 정보로 윈도우 사이즈 셋팅
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}
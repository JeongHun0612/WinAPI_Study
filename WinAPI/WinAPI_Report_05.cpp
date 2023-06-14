#include "Stdafx.h"
/*
23/06/14
------------------------------------------------------------------------------------ -
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

	// 실제 윈도우 크기 조정
	AdjustWindowRect(&rc, WINSTYLE, false);

	// 얻어온 렉트의 정보로 윈도우 사이즈 셋팅
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

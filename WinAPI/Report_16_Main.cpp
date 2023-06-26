#include "Stdafx.h"
#include "Report_16_1_MainGame.h"
#include "Report_16_2_MainGame.h"

#define REPORT_1		1
#define REPORT_2		2

#define REPORT_TYPE		REPORT_1

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0, 0 };

// 콜백
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

#if REPORT_TYPE == REPORT_1
Report_16_1_MainGame* _mg;
#elif REPORT_TYPE == REPORT_2
Report_16_2_MainGame* _mg;
#endif

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR    lpszCmdParam,
	int       nCmdShow)
{

#if REPORT_TYPE == REPORT_1
	_mg = new Report_16_1_MainGame();
#elif REPORT_TYPE == REPORT_2
	_mg = new Report_16_2_MainGame();
#endif

	_hInstance = hInstance;

	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;                                            // 클래스 여분 메모리
	wndClass.cbWndExtra = 0;                                            // 윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));     // 백그라운드
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                     // 마우스 커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);                   // 아이콘
	wndClass.hInstance = hInstance;                                     // 윈도우를 소요할 프로그램의 식별자 정보
	wndClass.lpfnWndProc = (WNDPROC)WndProc;                            // 윈도우 프로시저
	wndClass.lpszClassName = WINNAME;									// 클래스 이름 (식별자 정보)
	wndClass.lpszMenuName = NULL;                                       // 메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;                           // 윈도우 스타일 (다시 그리기 정보)


	RegisterClass(&wndClass);

	_hWnd = CreateWindow
	(
		WINNAME,				// 윈도우 클래스 식별자
		WINNAME,				// 윈도우 타이틀 바 이름
		WINSTYLE,				// 윈도우 스타일
		WINSTART_X,             // 윈도우 화면 X 좌표
		WINSTART_Y,             // 윈도우 화면 Y 좌표
		WINSIZE_X,              // 윈도우 화면 가로 크기
		WINSIZE_Y,              // 윈도우 화면 세로 크기
		NULL,                   // 부모 윈도우 -> GetDesktopWindow
		(HMENU)NULL,            // 메뉴 핸들
		hInstance,              // 인스턴스 지정
		NULL                    // 윈도우의 자식 윈도우를 생성하면 지정하고 그렇지 않다면 NULL을 잡아라
								//  ㄴ 필요에 의해서 사용하기도 하지만 지금은 NULL
	);

	setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

	ShowWindow(_hWnd, nCmdShow);

	// 메인 게임 클래스 초기화를 실패하면 종료
	if (FAILED(_mg->init()))
	{
		return 0;
	}

	MSG message;

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	_mg->release();
	UnregisterClass(WINNAME, hInstance);

	return (int)message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _mg->MainProc(hWnd, iMessage, wParam, lParam);
}

void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0, 0, width, height };

	AdjustWindowRect(&rc, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}
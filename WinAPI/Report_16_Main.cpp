#include "Stdafx.h"
#include "Report_16_1_MainGame.h"
#include "Report_16_2_MainGame.h"
#include "Report_16_3_MainGame.h"

/*
과제 1. 슬라이스 게임

- 치트 필수

- 화면 왼쪽에 원본 사진 출력 < - > 화면 오른쪽에는 9등분된 이미지 출력

- 9등분 된 이미지 제일 아래 오른쪽 칸이 시작 칸

- 퍼즐이 완성되면 알파블렌딩 효과로 이미지가 나타난다.
ㄴ 중앙에서 완성된 이미지를 보여주면 된다.


과제 2. 미니맵 만들기

- 2가지 버전

- 플레이어의 움직임을 미니맵에서도 확인할 수 있어야 한다.
ㄴ 1. 화면에 표시되는 작은 GUI 형태의 미니맵
ㄴ 2. 화면위에 그려지는 전체화면 미니맵


과제 3. 지렁이 만들기

- 지렁이는 구슬이 꼬리를 물고 이어지는 형태
ㄴ 각 구슬마다 번호를 표기한다.

- 지렁이는 화면밖의 무작위 위치에서 등장을 한다.

- 특별한 키 입력이 없어도 지렁이는 화면안에서 움직인다.

- 벽에 부딪히면 팅겨 나가야 하고 왼쪽 / 오른쪽 방향키로 조종이 가능해야 한다.

- 따라오는 구슬은 머리가 방향을 튼다고 같이 틀면 안되고 머리가 있던 위치까지 와서 방향을 전환한다.

- 임의의 숫자가 표시된 아이템이 게임이 시작되면 생성되고 지렁이가 아이템을 먹으면 해당하는 번호의 지렁이 구슬이 커진다. (색깔도 넣어보기)

※ 얼마나 자연스러운지가 핵심
*/

#define REPORT_1		1
#define REPORT_2		2
#define REPORT_3		3

#define REPORT_TYPE		REPORT_2

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
#elif REPORT_TYPE == REPORT_3
Report_16_3_MainGame* _mg;
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
#elif REPORT_TYPE == REPORT_3
	_mg = new Report_16_3_MainGame();
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
#pragma region WinAPI
/*
▶ API

- 운영체제가 응용 프로그램 개발을 위해 제공하는 함수의 집합

- 명령어의 집합으로 어플리케이션 프로그램에서 오퍼레이팅 시스템의 기본적인 기능을 사용할 필요가 있을 경우 API에서 명령어 호출이 진행된다.

EX)
하드웨어 ---------- 운영체제 (Windows) ---------- 응용 프로그램
( API 함수 )


▷ 장점

- 운영체제가 같으면 같은 기능의 집합을 사용하기에 확장성 및 연동성, 그리고 유지보수면에서 아주 유리하다. ( 윈도우즈 != 리눅스 )

- 운영체제에 종속되기 때문에 개발 확장성이 아주 좋다. (게임 분야)


▷ 단점

- 플랫폼에 고착화
	ㄴ C 언어 개발

▶ API 구조

- 크게 진입점, 메세지 루프, Windows Procesdure로 나뉜다.
*/
#pragma endregion

// stdafx.h : 자주 사용하지만 자주 변경되지는 않는 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이 들어 있는 포함 파일입니다.
#include "Stdafx.h"

// 전역 변수
/*
※ 인스턴스
- 윈도우 OS가 현재 실행되고 있는 프로그램을 확인하기 위한 값
- 기본적으로 같은 프로그램이면 같은 인스턴스 값을 가진다.
- 클래스가 메모리에 실제로 구현된 실체
 ㄴ 실행되고 있는 각각의 프로그램들
*/

HINSTANCE _hInstance;
HWND _hWnd;
//TCHAR* pszString = _T("Windows API");

/*
▶ TCHAR

- THCAR형은 프로젝트의 문자셋 설정에 따라 자동적으로 char 또는 wchar_t로 Type_Casting 되는 중간 매크로 자료형

- 멀티 바이트와 유니 코드 환경에서 별도의 수정 작업 없이 프로그램을 구동하기 위해서는 TCHAR형으로 문자열을 표현할 것을 추천

- 일반적으로 윈도우 응용 프로그램에서 문자열 상수를 쓰기 위해서는 중간 설정에 따라 char* 또는 wchar_t*로 변환해 주는 _T 매크로를 이용해야 한다.
*/

/*
LPSTR       ->      Long Pointer       =    char*
LPCSTR      ->      Constant           =    const char*
LPCTSTR     ->      t_string           =    const tchar*
*/


// 콜백
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

/*
hInstance       ->   프로그램 인스턴스 핸들
hPrevInstance   ->   이전에 실행된 인스턴스 핸들
lpszCmdParam    ->   명령형으로 입력된 프로그램 인수
nCmdShow        ->   프로그램이 시작될 형태 (최소화 / 크기 등등)
*/

/*
// 문자셋
int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   TCHAR*    lpszCmdParam,
					   int       nCmdShow)
*/

RECT _rc1, _rc2;
int centerX;
int centerY;

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR    lpszCmdParam,
	int       nCmdShow)
{
	// 인스턴스를 전역 변수에 담는다.
	_hInstance = hInstance;

	/*
	- WinMian의 역할

	1. 윈도우 창을 세팅 후 화면에 띄우기
		ㄴ 화면에 창을 띄우기 위해서는 4가지를 모두 처리해야 한다.

	2. 메세지 루프
	*/

	// 1-1. 윈도우창 구조체 선언 및 초기화
	// WNDCLASS : 이 구조체는 윈도우즈 운영체제에서 윈도우 생성을 명령하기 위해서
	//            커스텀한 윈도우를 식별할 수 있는 정보 등을 기록하는 역학을 수행한다.
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;                                            // 클래스 여분 메모리
	wndClass.cbWndExtra = 0;                                            // 윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));     // 백그라운드
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                     // 마우스 커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);                   // 아이콘
	wndClass.hInstance = hInstance;                                     // 윈도우를 소요할 프로그램의 식별자 정보
	wndClass.lpfnWndProc = (WNDPROC)WndProc;                            // 윈도우 프로시저
	wndClass.lpszClassName = WINNAME;                                // 클래스 이름 (식별자 정보)
	wndClass.lpszMenuName = NULL;                                       // 메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;                           // 윈도우 스타일 (다시 그리기 정보)


	// 1-2. 윈도우 클래스 등록
	RegisterClass(&wndClass);

	// 1-3. 화면에 보여줄 윈도우 창 생성
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

	// 클라이언트 영역의 사이즈를 정확히 잡아주기 위해
	setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

	// 1-4. 화면에 윈도우창 보여주기
	ShowWindow(_hWnd, nCmdShow);

	// 단일 프로젝트 (단기/과제) 업데이트 처리 해야 한다.
	//UpdateWindow(_hWnd);


	// 2. 메세지 루프
	// MSG : 운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
	MSG message;
	//ZeroMemory(&message, sizeof(message));

	/*	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}
	*/

	/*
	★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
	▶ 메세지 루프 종류

	1. GetMessage
	ㄴ 메세지를 꺼내 올 수 있을때까지 멈춰있는 함수 (대기)
	ㄴ GetMessage는 메세지 큐로부터 하나의 메세지를 가져오는 역할을 수행한다.
	ㄴ 단, 메세지 큐가 비어 있을 경우 메세지가(발생한 메세지 X) 들어올때까지 대기한다.


	2. PeekMessage (게임에서 주로 사용하는 메세지 루프)
	ㄴ 메세지가 없더라도 반환 되는 함수
	*/

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	/*
	TranslateMessage
	ㄴ 키보드의 입력 메시지 처리를 담당
	ㄴ 입력된 키가 문자키인지 확인 후 대문자 혹은 소문자, 한글 / 영문인지에 대해 WH_CHAR 메세지를 발생 시킨다.

	DispatchMessage
	ㄴ 윈도우 프로시저에서 전달된 메세지를 실제 윈도우로 전달해 준다.
	*/

	return (int)message.wParam;
}

/*
hWnd		->		어느 윈도우에서 발생한 메세지인지 구분
iMessage	->		메세지 구분 번호
wParam		->		unsigned int -> 마우스 버튼의 상태, 키보드 조합 키의 상태를 전달
lParam		->		unsigned long -> 마우스 클릭 좌표를 전달
*/

// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;			// 핸들 DC
	PAINTSTRUCT ps;		// 페인트 구조체
	
	static POINT pt = { 0, 0 };
	char strPT[128];

	/*
	char[] : 수정이 가능
	char*  : 수정이 불가능
	*/

	/*
	▶ Window Procedure
	ㄴ 메세지를 운영체제에 전달 -> 강제로 운영체제가 호출되게 해준다.
	ㄴ WinMain()이 아닌 운영체제에 의해 호출이 되는 콜백(Callback) 함수
	ㄴ 윈도우를 생성할 때 반드시 지정을 해줘야 한다.

	- 기억해야 할건 윈도우 프로시저 내부에서는 윈도우에서 발생한 모든 메세지를 처리하는 것이 아니라
	  특정 메세지만을 처리하고 나머지 메세지는 DefWindowProc 함수가 처리하도록 로직을 설계하는게 일반적이다.

	※ 위 내용은 반드시 기억할것
	*/

	switch (iMessage)
	{
	case WM_CREATE:		// 생성자
		_rc1 = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);
		_rc2 = RectMakeCenter(WINSIZE_X / 2 + 200, WINSIZE_Y / 2, 100, 100);

		centerX = WINSIZE_X / 2;
		centerY = WINSIZE_Y / 2;
		break;

		/*
		WM_PAINT

		- 윈도우를 다시 그려야 할때 사용하는 메세지

		1. 윈도우가 처음 만들어졌을때
		2. 윈도우 크기를 조절하고 싶을때
		3. 윈도우가 다른 윈도우에 가려졌다가 다시 보일때
		4. 특정 함수가 호출이 될 때 -> InvalidateRect, Invalidate, UpdateAllViews 등등..
			ㄴ 기본적으로 렌더링 관련된 함수가 나오면 PAINT를 떠올려야 한다.
		*/
	case WM_PAINT:		// 출력에 관한 모든것을 담당한다. (문자, 그림, 도형 등등 화면에 보이는 모든 것을 의미)
		hdc = BeginPaint(hWnd, &ps);

		// wsprintf() : 숫자 -> 문자열 출력
		wsprintf(strPT, "X : %d       Y : %d", pt.x, pt.y);
		TextOut(hdc, 10, 10, strPT, strlen(strPT));

		//Rectangle(hdc, _rc1.left, _rc1.top, _rc1.right, _rc1.bottom);
		//DrawRectMake(hdc, _rc2);
		//EllipseMakeCenter(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);

		Rectangle(hdc, centerX, centerY, 100, 100);

		//SetPixel(hdc, 300, 200, RGB(255, 0, 0));
		//for (int i = 0; i < 10000; i++)
		//{
		//	SetPixel(hdc, rand() % 800, rand() % 800, RGB(rand() % 255, rand() % 255, rand() % 255));
		//}

		/*
		strcpy(x, y) : y를 x에 복사
		strcat(x, y) : x문자열 + y문자열
		strlen(x, y) : 문자열 길이
		strcmp(x, y) : 두 문자열이 같은지 확인
		ㄴ x == y		=>	 0리턴
		ㄴ x < y			=>	-1리턴
		ㄴ x > y			=>	 1리턴

		strcpy	->	 wcscpy		->		_tcscpy
		strcat	->	 wsccat		->		_tcscat
		strlen	->	 wcslen		->		_tcslen
		strcmp	->	 wcscmp		->		_tcscmp
		strtok	->	 wcstok		->		_tcstok		(문자열 자르기)
		strchr	->	 wcschr		->		_tcschr		(문자 찾기)
		strstr	->	 wcsstr		->		_tcsstr		(문자열 찾기)
		*/

		// 데카르트 좌표 != 윈도우 좌표계


		// TextOut() : 문자 출력(hdc, 좌표X, 좌표Y, 문자열, 문자열 길이)
		//TextOut(hdc, 300, 300, "과제가 너무 재밌다 하하하...", strlen("과제가 너무 재밌다 하하하..."));
		// ㄴ strlen는 할당받은 메모리에 바인딩 된 문자열에서 NULL값을 제외한 문자열 길이
		
		// 문자열 글자색 변경
		//SetTextColor(hdc, RGB(255, 0, 0));
		//TextOut(hdc, 300, 400, "과제 좀 더 내주세요...", strlen("과제 좀 더 내주세요..."));

		//MoveToEx(hdc, 400, 400, NULL);
		//LineTo(hdc, 200, 400);

		//MoveToEx(hdc, 400, 400, NULL);
		//LineTo(hdc, 200, 200);

		EndPaint(hWnd, &ps);
		break;

	case WM_MOUSEMOVE:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		InvalidateRect(hWnd, NULL, TRUE);
		break;

	case WM_LBUTTONDOWN:	// 마우스 왼쪽 버튼이 눌렀을 때 메세지 발생
		centerX = RND->getInt(WINSIZE_X);
		centerY = RND->getInt(WINSIZE_Y);

		InvalidateRect(hWnd, NULL, true);

		break;

	case WM_RBUTTONDOWN:

		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	
	case WM_DESTROY:	// 소멸자
		// PostQuitMessage() : 이 함수는 메세지 큐에 Quit 메세지를 보내는 역할을 한다.
		// 즉, Quit 메세지를 수신하는 순간 GetMessage 함수가 FALSE를 반환함으로 메세지 루프가 종료된다.
		PostQuitMessage(0);
		return 0;
	}

	// 윈도우 프로시저에서 처리되지 않은 나머지 메세지를 처리해 준다.
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void setWindowSize(int x, int y, int width, int height)
{
	RECT rc = { 0, 0, width, height };

	// 실제 윈도우 크기 조정
	// AdjustWindowRect() : RECT 구조체, 윈도우 스타일, 메뉴 사용 여부
	AdjustWindowRect(&rc, WINSTYLE, false);
	
	// 얻어온 렉트의 정보로 윈도우 사이즈 셋팅
	// ZORDER : 이미지 간의 레이어에 대한 처리를 하는 기법
	// NOZORDER : 이미지 레이어를 비켜주지 않겠다.
	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}


/*
23/06/07
-------------------------------------------------------------------------------------
과제1. 윈도우 창 만들기

- 시간은 10분

- 실패시 깜지 7번


한줄 조사. 노트에 열심히 적는다.

- Callback Function, DC, GetDC / Release DC, beginPaint / EndPaint
WM_PAINT, PAINSTRUCT


23/06/08
-------------------------------------------------------------------------------------
과제1. 구구단

- 예외처리 필수 : 구구단의 본질 (2단 ~ 9단)

- 마우스 왼쪽 클릭을 했을 시 1단씩 생기고, 우 클릭을 하면 1단씩 지워진다.
ㄴ 3단 씩 개행 한다.

과제2. WinAPI 출력

- MoveToEX() + LineTo()를 이용한다.

★ 도형 관련 함수 사용 금지

- 1. 자기 이름 출력 (한글)

- 2. UnrealEngine (영문)

- 마우스 왼쪽을 누르면 한글자씩 출력이 되면 우 클릭을 하면 한글자씩 지워진다.

- 현재 창 크기 기준 절반 이상의 사이즈로 해온다.

한줄 조사.
- SetTimer

- KillTimer

- InvalidateRect


23/06/09
-------------------------------------------------------------------------------------
과제1. 오망성 출력

- 오망성을 마법진 처럼 만들어 온다.

- 양식은 자유지만 본인이 생각했을때 가장 효율적인 방법으로
 ㄴ 특히 배열은 무조건 사용해본다.


과제2. 애플 로고 출력

- SetPixel을 이용해서 만든다.


과제3. 사각형 이동

- 방향키를 통해 사각형을 움직인다.

- 예외처리 : 사각형은 화면 밖으로 나갈 수 없다.


과제4. 사각형 2개 움직이기

- 총 사각형 갯수 : 2개

- 하나는 움직일 수 있는 사각형 / 다른 하나는 움직일 수 없는 사각형

- 움직일 수 없는 사각형을 움직일 수 있는 사각형을 밀어낼 수 있으면 된다.

- 2개의 사각형을 초기 위치로 돌리는 기능도 추가한다.

- 예외처리 : 2개의 사각형은 화면 밖으로 나갈 수 없다.

※ 별다른 언급을 하기 전까지는 충돌 함수 사용 금지


23/06/12
-------------------------------------------------------------------------------------
과제 1. 사각형 영혼 밀어넣기

- 시작은 큰 사각형 2개와 작은 사각형 1개

- 내가 움직일 수 있는 사각형 안에는 작은 사각형이 들어 있다.

- 큰 사각형을 움직이면 작은 사각형 역시 움직이는 버전 1개 / 움직이지 않는 버전 1개
 ㄴ 총 2가지 버전
 ㄴ 예외처리 : 작은 사각형은 큰 사각형을 벗어날 수 없다.

- 큰 사각형끼리 충돌이 되면 작은 사각형은 충돌이 된 반대편 사각형으로 이동한다.

※ 핵심은 움직일 수 있는 주도권은 작은 사각형을 가지고 있는 "큰 사각형"

예외처리 : 큰 사각형끼리의 모서리에 대한 정밀도를 예외 처리한다.


23/06/13
-------------------------------------------------------------------------------------
과제 1. 사각형 드래그 이동

- 마우스로 사각형을 자유롭게 움직일 수 있으면 된다.

※ T / F 사각형 범위와에서 마우스UP 이벤트가 발생할 시 오류


과제 2. 사각형 크기 조절

- 마우스로 사각형의 크기를 자유롭게 조정할 수 있으면 된다.

- 바탕화면에서 드래그 해보면서 똑같이 만들면 OK


과제 3. 사각형 4단 밀기

- 사각형의 갯수는 총 4개

- 마우스로 화면에 그려진 4개의 사각형 중 아무거나 선택해 자유롭게 움직인다.

- 마우스로 움직이고 있는 사각형이 다른 사각형과 충돌되면 충돌된 사각형은 "자연스럽게" 밀려난다.

※ 관성 / 그럴싸해 보이게
ㄴ 에어하키


한줄 조사. 디자인 패턴

- 싱글톤 + @ 4개 (게임에서 쓸만한 디자인 패턴을 조사)


23/06/14
-------------------------------------------------------------------------------------
과제 1. 마우스로 무작위 도형 출력

- 마우스로 클릭한 좌표에 무작위 도형을 출력한다.

- 도형의 크기 + 도형의 모양 + 도형의 종류까지 모두 무작위 처리한다.

- 도형의 종류 : 사각형, 원, 삼각형 및 다각형

※ 삼각형 + 다각형 -> Polygon() + 배열을 이용한다.


<기간 2일>
과제 2. 도형을 활용한 내 얼굴 그려오기

- 도형을 활용한다.


과제 3. 공 튀기기 (싱글톤 활용해 보기)

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

#include "Stdafx.h"
#include "Report_16_1_MainGame.h"
#include "Report_16_2_MainGame.h"
#include "Report_16_3_MainGame.h"

/*
���� 1. �����̽� ����

- ġƮ �ʼ�

- ȭ�� ���ʿ� ���� ���� ��� < - > ȭ�� �����ʿ��� 9��е� �̹��� ���

- 9��� �� �̹��� ���� �Ʒ� ������ ĭ�� ���� ĭ

- ������ �ϼ��Ǹ� ���ĺ��� ȿ���� �̹����� ��Ÿ����.
�� �߾ӿ��� �ϼ��� �̹����� �����ָ� �ȴ�.


���� 2. �̴ϸ� �����

- 2���� ����

- �÷��̾��� �������� �̴ϸʿ����� Ȯ���� �� �־�� �Ѵ�.
�� 1. ȭ�鿡 ǥ�õǴ� ���� GUI ������ �̴ϸ�
�� 2. ȭ������ �׷����� ��üȭ�� �̴ϸ�


���� 3. ������ �����

- �����̴� ������ ������ ���� �̾����� ����
�� �� �������� ��ȣ�� ǥ���Ѵ�.

- �����̴� ȭ����� ������ ��ġ���� ������ �Ѵ�.

- Ư���� Ű �Է��� ��� �����̴� ȭ��ȿ��� �����δ�.

- ���� �ε����� �ð� ������ �ϰ� ���� / ������ ����Ű�� ������ �����ؾ� �Ѵ�.

- ������� ������ �Ӹ��� ������ ư�ٰ� ���� Ʋ�� �ȵǰ� �Ӹ��� �ִ� ��ġ���� �ͼ� ������ ��ȯ�Ѵ�.

- ������ ���ڰ� ǥ�õ� �������� ������ ���۵Ǹ� �����ǰ� �����̰� �������� ������ �ش��ϴ� ��ȣ�� ������ ������ Ŀ����. (���� �־��)

�� �󸶳� �ڿ����������� �ٽ�
*/

#define REPORT_1		1
#define REPORT_2		2
#define REPORT_3		3

#define REPORT_TYPE		REPORT_2

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0, 0 };

// �ݹ�
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

	wndClass.cbClsExtra = 0;                                            // Ŭ���� ���� �޸�
	wndClass.cbWndExtra = 0;                                            // ������ ���� �޸�
	wndClass.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));     // ��׶���
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                     // ���콺 Ŀ��
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);                   // ������
	wndClass.hInstance = hInstance;                                     // �����츦 �ҿ��� ���α׷��� �ĺ��� ����
	wndClass.lpfnWndProc = (WNDPROC)WndProc;                            // ������ ���ν���
	wndClass.lpszClassName = WINNAME;									// Ŭ���� �̸� (�ĺ��� ����)
	wndClass.lpszMenuName = NULL;                                       // �޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;                           // ������ ��Ÿ�� (�ٽ� �׸��� ����)


	RegisterClass(&wndClass);

	_hWnd = CreateWindow
	(
		WINNAME,				// ������ Ŭ���� �ĺ���
		WINNAME,				// ������ Ÿ��Ʋ �� �̸�
		WINSTYLE,				// ������ ��Ÿ��
		WINSTART_X,             // ������ ȭ�� X ��ǥ
		WINSTART_Y,             // ������ ȭ�� Y ��ǥ
		WINSIZE_X,              // ������ ȭ�� ���� ũ��
		WINSIZE_Y,              // ������ ȭ�� ���� ũ��
		NULL,                   // �θ� ������ -> GetDesktopWindow
		(HMENU)NULL,            // �޴� �ڵ�
		hInstance,              // �ν��Ͻ� ����
		NULL                    // �������� �ڽ� �����츦 �����ϸ� �����ϰ� �׷��� �ʴٸ� NULL�� ��ƶ�
								//  �� �ʿ信 ���ؼ� ����ϱ⵵ ������ ������ NULL
	);

	setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

	ShowWindow(_hWnd, nCmdShow);

	// ���� ���� Ŭ���� �ʱ�ȭ�� �����ϸ� ����
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
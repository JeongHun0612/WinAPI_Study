#include "Stdafx.h"
#include "Report_MainGame.h"

HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0, 0 };

// �ݹ�
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

Report_MainGame* _mg;

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR    lpszCmdParam,
	int       nCmdShow)
{

	_mg = new Report_MainGame();

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
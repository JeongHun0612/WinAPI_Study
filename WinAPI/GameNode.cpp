#include "Stdafx.h"
#include "GameNode.h"

HRESULT GameNode::init(void)
{
	// Ÿ�̸� �ʱ�ȭ
	SetTimer(_hWnd, 1, 10, NULL);

	RND->init();
	KEYMANAGER->init();
	MOUSEMANAGER->init();

	// �Լ��� ���������� ���� �Ǿ����� �˸���.
	return S_OK;
}

void GameNode::release(void)
{
	// �����Ҵ�� ���� �������� �ʰ� �����ϸ� �޸� ������ �߻��Ѵ�.
	KillTimer(_hWnd, 1);

	RND->releaseSingleton();
	KEYMANAGER->releaseSingleton();
	MOUSEMANAGER->releaseSingleton();
}

void GameNode::update(void)
{
	InvalidateRect(_hWnd, NULL, true);
}

void GameNode::render(HDC hdc)
{
	//! Do Noting
}

// ���� ���ν���
LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;			
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_TIMER:
		this->update();
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		this->render(hdc);

		EndPaint(hWnd, &ps);
		break;

	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;

	case WM_DESTROY: // �Ҹ���
		// PostQuitMessage() : �� �Լ��� �޼��� ť�� Quit �޼����� ������ ������ �Ѵ�.
		// ��, Quit �޼����� �����ϴ� ���� GetMessage �Լ��� FALSE�� ��ȯ������ �޼��� ������ ����ȴ�.
		PostQuitMessage(0);
		return 0;
	}

	// ������ ���ν������� ó������ ���� ������ �޼����� ó���� �ش�.
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
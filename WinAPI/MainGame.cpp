#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	_mg->init();

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	_mg->release();
}

void MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "������ �����Ͻðڽ��ϱ�?", "����Ȯ��", MB_OKCANCEL) == IDOK);
		{
			PostQuitMessage(0);
		}
	}

	_mg->update();
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	_mg->render();

	this->getBackBuffer()->render(getHDC(), 0, 0);
}

/*
���� 1. ĳ���� �����

- �̹��� �ʼ� : ���, ��, ĳ���� (���, �̵�, ����, ���� ��� �ִ� ���)

- �⺻������ ���� �������� ���� ���� �𼭸��� ������ �� �߰��� ����� ��� õõ�� �������� �����´�.

- ĳ���Ͱ� ���� ��� �ִ� ���¿��� �� / �Ǵ� �Ʒ� ����Ű�� ������ �ö󰡰ų� / ������ �� �־�� �Ѵ�.

- ���� ĳ���Ͱ� �� ���� �ö� ���� �ٽ� �Ʒ��� �����ϸ� ĳ���ʹ� ���鿡 ���� �� �� �־�� �Ѵ�.

- ĳ���� ���� ������ ������ �ְ� ĳ���ʹ� ���� �ؿ��� ������ �������� �ö� �� �� �ִ�.

- ĳ���ʹ� ������ �ö� ���¿��� �������� �ٽ� ������ �� ������ OK


���� 2. �̴ϸ� ����

- �÷��̾��� �������� �̴ϸʿ��� �״�� Ȯ���ؾ� �Ѵ�.
�� �����ӱ��� �����ϰ�
*/
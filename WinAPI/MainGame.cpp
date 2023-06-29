#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	_loading = new GImage;
	_loading->init("Resources/Images/Object/zero_loading.bmp", WINSIZE_X / 2 - 200, WINSIZE_Y / 2 - 200,
		640 , 240,
		8 , 2,
		true, RGB(255, 0, 255));

	_alphaA = 0;
	_count = _index = 0;

	_isLeft = false;
	_isAlphaIncrease = false;

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
	
	SAFE_DELETE(_loading);
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

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isLeft = true;
		_loading->setX(_loading->getX() - 8.0f);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isLeft = false;
		_loading->setX(_loading->getX() + 8.0f);
	}

	if (_isLeft)
	{
		_count++;

		_loading->setFrameY(1);

		if (_count % 3 == 0)
		{
			_index--;

			if (_index < 0)
			{
				_index = 10;
			}

			_loading->setFrameX(_index);
		}
	}
	else
	{
		_count++;
		_loading->setFrameY(0);

		if (_count % 2 == 0)
		{
			_index++;

			if (_index > 10)
			{
				_index = 0;
			}

			_loading->setFrameX(_index);
		}
	}
}

void MainGame::render(HDC hdc)
{
	HDC memDC = this->getDoubleBuffer()->getMemDC();

	PatBlt(memDC, 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ==========================================================

	_loading->frameRender(memDC, _loading->getX(), _loading->getY());

	// ==========================================================
	this->getDoubleBuffer()->render(hdc, 0, 0);
}

/*
���� 1. ���� �޺� �̹��� �ϼ�

- �����̽� �ٸ� ������ 1Ÿ���� -> ������ ���ݱ��� �ڵ����� ���
�� ���� �ݺ�


���� 2. ������ �̹��� ó��

- ���� �� + ���� ��

- ���Ӿ������� �Ʒ��� �̹����� GUIȭ ���Ѽ� ��� ��Ų��. (��ư)
�� ������ ����)

- �ʼ� �̹���
�� ���, ���, �̵� (�� + ��), ��� (�� + ��), �밢�� ���,
	���� ��� (�� + ��), �� ������, �¸� ���� (�� ������), ��ų Ŭ���̸��� ����, �й�

*/
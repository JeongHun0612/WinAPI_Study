#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	_currentRect = CURRENTRECT_NULL;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rc[i * 4 + j] = RectMakeCenter(100 + j * 200, 200 + i * 200, 100, 100);
		}
	}

	_index = 0;
	_count = 0;
	_score = 0;
	_time = RND->getFromIntTo(30, 60);

	_bIsSelected = false;
	_bIsOnceCheck = false;

	_mole = new Example_Mole;
	_mole->init();

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	_mole->release();
	SAFE_DELETE(_mole);
}

void MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		// PtInRect() : ��Ʈ �ȿ� POINT(x, y)�� �ִ��� �˻��Ͽ� ����Ʈ�� �簢�� �ȿ� ������ true���� ��ȯ�ϴ� API �Լ�
		if (PtInRect(&_rc[_index], _ptMouse) && !_bIsOnceCheck)
		{
			_score += 100;
			_bIsOnceCheck = true;
		}
	}

	if (!_bIsSelected)
	{
		_count++;

		if (_count % _time == 0)
		{
			_count = 0;
			_index = RND->getInt(8);
			_currentRect = (CURRENT_RECT)_index;
			_bIsSelected = true;
		}
	}
	else
	{
		_count++;

		if (_count % _time == 0)
		{
			_bIsOnceCheck = false;
			_bIsSelected = false;
			_currentRect = CURRENTRECT_NULL;
			_time = RND->getFromIntTo(30, 60);
			_index = 100;
		}
	}

	_mole->update();
}

void MainGame::render(HDC hdc)
{
	for (int i = 0; i < 8; i++)
	{
		Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
	}

	char strScore[128];

	wsprintf(strScore, "Score : %d", _score);
	TextOut(hdc, 50, 100, strScore, strlen(strScore));

	if (_bIsSelected)
	{
		int r = RND->getInt(256);
		int g = RND->getInt(256);
		int b = RND->getInt(256);

		HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
		FillRect(hdc, &_rc[_index], brush);
		DeleteObject(brush); // ������ ���� ����
	}

	_mole->render(hdc);
}

/*
- �ָ� ���� ����

�� �𸮾� 1��_�� �׸���_������
�� ���� ���� 9��
�� ���� ���� �����ؼ�

���� 1. �� ���ϱ�

- ���� ��ư�� �����鼭 ���� ����

- ������ ���۵ǰ� �÷��̾ ���������� ��ƾ �ð��� ȭ���� ����Ѵ�.

- �ʼ� : ����� + �ٽ��ϱ�

- �÷��̾�� ��� ������� �¿� ����� �ٸ��� ����

���� 2. �Ѿ� �߻�

- �ϴܿ��� �¿�� ������ �� �ִ� �÷��̾ ����

- �����̽� �ٸ� ������ �÷��̾ �Ѿ��� �߻��Ѵ�.

���� 3. �Ǿ��̻� ����

- �Ǿ��̻��� �ּ� 8�� �̻�

- �Ǿ��̻��� ���ȴ��� �ƴ����� ���ؼ� Ȯ���� �����ؾ� �Ѵ�.

- �ʼ� : �Ǿ��̻��� ������ �ִϸ��̼� ����

*/

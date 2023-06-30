#include "Stdafx.h"
#include "Example_Cliping.h"

HRESULT Example_Cliping::init(void)
{
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plImage = new GImage;
	_plImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(WINSIZE_X / 2 - 500, WINSIZE_Y / 2 + 200, 173, 291);

	_countA = _countB = 0;
	_alphaA = _alphaB = 0;

	_alphaNum = 1;

	_isAlphaIncrease = false;

	return S_OK;
}

void Example_Cliping::release(void)
{
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_plImage);
}

void Example_Cliping::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "������ �����Ͻðڽ��ϱ�?", "����Ȯ��", MB_OKCANCEL) == IDOK);
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 5.0f;
		_rc.right -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 5.0f;
		_rc.right += 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 5.0f;
		_rc.bottom -= 5.0f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 5.0f;
		_rc.bottom += 5.0f;
	}

	_countA++;
	if (_countA % 3 == 0)
	{
		_alphaA++;

		if (_alphaA >= 255)
		{
			_alphaA = 0;
		}
	}

	_countB++;
	if (_countB % 3 == 0)
	{
		_alphaB += 5;

		if (_alphaB >= 255)
		{
			_alphaB = 0;
		}
	}
}

void Example_Cliping::render(void)
{
	//_bgImage->render(getMemDC(), 0, 0);
	_bgImage->alphaRender(getMemDC(), _alphaA);

	//_plImage->render(getMemDC(), _rc.left, _rc.top);
	_plImage->alphaRender(getMemDC(), _rc.left, _rc.right, _alphaB);

	_bgImage->render(getMemDC(), _rc.left, _rc.top, 500, 300, 300, 300);
}


/*
���� 0. ��Ʈ������ ���� �۾�


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


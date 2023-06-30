#include "Stdafx.h"
#include "Example_Image.h"

HRESULT Example_Image::init(void)
{
	_bgImage = new GImage;
	_bgImage->init("Resources/Images/BackGround/DeadSpace.bmp", WINSIZE_X, WINSIZE_Y);

	_plImage = new GImage;
	_plImage->init("Resources/Images/Object/Airplane.bmp", 173, 291, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(WINSIZE_X / 2 - 500, WINSIZE_Y / 2 + 200, 173, 291);

	return S_OK;
}

void Example_Image::release(void)
{
	SAFE_DELETE(_bgImage);
	SAFE_DELETE(_plImage);
}

void Example_Image::update(void)
{
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
}

void Example_Image::render(void)
{
	_bgImage->render(getMemDC(), 0, 0);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	}

	_plImage->render(getMemDC(), _rc.left, _rc.top);
}

/*
�̹��� �߰� ���� 1. �δ��� ����

- ��Ȳ�� �´� �̹��� �ʼ������� �����Ѵ�.

- �δ����� ���� �� / ������ �� / ������ �� / ��ġ (���, ��������)

�� ���콺 Ŀ���� ShowCursor()�� �̿��Ѵ�.


���� 1. Ʋ�� �׸� ã��

- �̹����� ���伥 ���� / �˻����� ó���Ѵ�.

- ���������� �� 2���� ��������
�� Ʋ������ �ټ� �� �̻�

- ������ ���۵Ǹ� Ÿ�� �������� ���� �پ��� �߸� Ŭ���ϸ� �������� ���ҵȴ�.

- Ʋ������ ���߸� �ð� ����

- Ÿ�� �������� ��� �����Ǹ� Ÿ�ӿ��� �޼����� ȭ�鿡 ���� ���� ����


���� 3. ���伥 ��ġ

- CS6

- ���伥�� �⺻������ �� �������� ����� �ſ� �����ϰų� ����Ű�� �ٸ���.
*/

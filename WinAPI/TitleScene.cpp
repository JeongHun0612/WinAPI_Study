#include "Stdafx.h"
#include "TitleScene.h"



HRESULT TitleScene::init(void)
{
	// ���� ���� �ʱ�ȭ


	// ���� ���� �ʱ�ȭ
	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		_exampleBtn[i].rc = RectMake(20 + (i % 6) * 200, 50 + (i / 6) * 80, 150, 50);
	}

	wsprintf(_exampleBtn[EXAMPLE_MOLE].name, "�δ��� ����");
	wsprintf(_exampleBtn[EXAMPLE_BULLET].name, "�Ѿ� �߻�");
	wsprintf(_exampleBtn[EXAMPLE_MATH].name, "�ﰢ �Լ�");
	wsprintf(_exampleBtn[EXAMPLE_IMAGE].name, "�̹��� ���");
	wsprintf(_exampleBtn[EXAMPLE_CLIPING].name, "Ŭ���� �̹���");
	wsprintf(_exampleBtn[EXAMPLE_FRAME_IMAGE].name, "������ �̹���");

	return S_OK;
}

void TitleScene::release(void)
{
}

void TitleScene::update(void)
{
}

void TitleScene::render(void)
{
	SetTextAlign(getMemDC(), TA_LEFT);
	TextOut(getMemDC(), 20, 20, "���� ����", strlen("���� ����"));

	SetTextAlign(getMemDC(), TA_CENTER);
	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		DrawRectMake(getMemDC(), _exampleBtn[i].rc);
		TextOut(getMemDC(),
			_exampleBtn[i].rc.left + (_exampleBtn[i].rc.right - _exampleBtn[i].rc.left) / 2,
			_exampleBtn[i].rc.top + (_exampleBtn[i].rc.bottom - _exampleBtn[i].rc.top) / 2 - 10,
			_exampleBtn[i].name, strlen(_exampleBtn[i].name));
	}

	LineMake(getMemDC(), 0, WINSIZE_Y / 2, WINSIZE_X, WINSIZE_Y / 2);


	SetTextAlign(getMemDC(), TA_LEFT);
	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 20, "���� ����", strlen("���� ����"));
}

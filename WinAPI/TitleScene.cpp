#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	// ���� ���� �ʱ�ȭ
	for (int i = 0; i < REPORT_INDEX::REPORT_END; i++)
	{
		_reportBtn[i].idx = i;
		_reportBtn[i].rc = RectMake(20 + (i % 6) * 210, 50 + (i / 6) * 80, 180, 50);
	}

	wsprintf(_reportBtn[REPORT_CARD_MATCH].name, "¦ ���߱�");
	wsprintf(_reportBtn[REPORT_MOLE].name, "�δ��� ����");
	wsprintf(_reportBtn[REPORT_CLAYSHOOTING].name, "Ŭ���� ���");
	wsprintf(_reportBtn[REPORT_AVOID].name, "�� ���ϱ�");
	wsprintf(_reportBtn[REPORT_BULLET_SHOOTING].name, "�Ѿ� �߻�");
	wsprintf(_reportBtn[REPORT_CROCODILE].name, "�Ǿ� �̻� ����");
	wsprintf(_reportBtn[REPORT_VERTICAL_SHOOTING].name, "����ũ�� ����");
	wsprintf(_reportBtn[REPORT_HORIZONTAL_SHOOTING].name, "Ⱦ��ũ�� ����");
	wsprintf(_reportBtn[REPORT_MOLE_IMAGE].name, "�δ��� ����(�̹���)");
	wsprintf(_reportBtn[REPORT_ANALOG_CLOCK].name, "�Ƴ��α� �ð�");
	wsprintf(_reportBtn[REPORT_SHELL_FIRE].name, "��ź �߻�");
	wsprintf(_reportBtn[REPORT_BULLET_GRAVITY].name, "�Ѿ� �߷�");
	wsprintf(_reportBtn[REPORT_SLICE_GAME].name, "�̹��� �����̽�");
	wsprintf(_reportBtn[REPORT_MINI_MAP].name, "�̴ϸ�");
	wsprintf(_reportBtn[REPORT_WORM_GAME].name, "������ ����");
	wsprintf(_reportBtn[REPORT_ATTACK_COMBO].name, "���� �޺� ���");
	wsprintf(_reportBtn[REPORT_MOTION_ANIMATION].name, "ĳ���� ���");
	wsprintf(_reportBtn[REPORT_WALL_CATCH].name, "�� ���");


	// ���� ���� �ʱ�ȭ
	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		_exampleBtn[i].idx = REPORT_INDEX::REPORT_END + i;
		_exampleBtn[i].rc = RectMake(20 + (i % 6) * 210, (WINSIZE_Y / 2 + 50) + (i / 6) * 80, 180, 50);
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
	for (int i = 0; i < REPORT_INDEX::REPORT_END; i++)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && PtInRect(&_reportBtn[i].rc, _ptMouse))
		{
			cout << _reportBtn[i].idx << endl;
			cout << _reportBtn[i].name << endl;

			_currentSceneIdx = _reportBtn[i].idx;
		}
	}

	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && PtInRect(&_exampleBtn[i].rc, _ptMouse))
		{
			cout << _exampleBtn[i].idx << endl;
			cout << _exampleBtn[i].name << endl;

			_currentSceneIdx = _exampleBtn[i].idx;
		}
	}
}

void TitleScene::render(void)
{
	SetTextAlign(getMemDC(), TA_LEFT);
	TextOut(getMemDC(), 20, 20, "���� ����", strlen("���� ����"));
	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 20, "���� ����", strlen("���� ����"));

	LineMake(getMemDC(), 0, WINSIZE_Y / 2, WINSIZE_X, WINSIZE_Y / 2);


	SetTextAlign(getMemDC(), TA_CENTER);
	for (int i = 0; i < REPORT_INDEX::REPORT_END; i++)
	{
		DrawRectMake(getMemDC(), _reportBtn[i].rc);
		TextOut(getMemDC(),
			_reportBtn[i].rc.left + (_reportBtn[i].rc.right - _reportBtn[i].rc.left) / 2,
			_reportBtn[i].rc.top + (_reportBtn[i].rc.bottom - _reportBtn[i].rc.top) / 2 - 10,
			_reportBtn[i].name, strlen(_reportBtn[i].name));
	}

	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		DrawRectMake(getMemDC(), _exampleBtn[i].rc);
		TextOut(getMemDC(),
			_exampleBtn[i].rc.left + (_exampleBtn[i].rc.right - _exampleBtn[i].rc.left) / 2,
			_exampleBtn[i].rc.top + (_exampleBtn[i].rc.bottom - _exampleBtn[i].rc.top) / 2 - 10,
			_exampleBtn[i].name, strlen(_exampleBtn[i].name));
	}
}

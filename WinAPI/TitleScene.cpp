#include "Stdafx.h"
#include "TitleScene.h"


HRESULT TitleScene::init(void)
{
	for (int i = 0; i < SCENE_INDEX::REPORT_END; i++)
	{
		_sceneBtn[i].idx = i;
		_sceneBtn[i].rc = RectMake(20 + (i % 6) * 210, 50 + (i / 6) * 80, 180, 50);
	}

	for (int i = 0; i < SCENE_INDEX::SCENE_END - SCENE_INDEX::REPORT_END; i++)
	{
		_sceneBtn[i + SCENE_INDEX::REPORT_END].idx = i + SCENE_INDEX::REPORT_END;
		_sceneBtn[i + SCENE_INDEX::REPORT_END].rc = RectMake(20 + (i % 6) * 210, (WINSIZE_Y / 2 + 150) + (i / 6) * 80, 180, 50);
	}

	// ���� ���� �̸�
	wsprintf(_sceneBtn[REPORT_CARD_MATCH].name, "¦ ���߱�");
	wsprintf(_sceneBtn[REPORT_MOLE].name, "�δ��� ����");
	wsprintf(_sceneBtn[REPORT_CLAYSHOOTING].name, "Ŭ���� ���");
	wsprintf(_sceneBtn[REPORT_AVOID].name, "�� ���ϱ�");
	wsprintf(_sceneBtn[REPORT_BULLET_SHOOTING].name, "�Ѿ� �߻�");
	wsprintf(_sceneBtn[REPORT_CROCODILE].name, "�Ǿ� �̻� ����");
	wsprintf(_sceneBtn[REPORT_VERTICAL_SHOOTING].name, "����ũ�� ����");
	wsprintf(_sceneBtn[REPORT_HORIZONTAL_SHOOTING].name, "Ⱦ��ũ�� ����");
	wsprintf(_sceneBtn[REPORT_MOLE_IMAGE].name, "�δ��� ����(�̹���)");
	wsprintf(_sceneBtn[REPORT_ANALOG_CLOCK].name, "�Ƴ��α� �ð�");
	wsprintf(_sceneBtn[REPORT_SHELL_FIRE].name, "��ź �߻�");
	wsprintf(_sceneBtn[REPORT_BULLET_GRAVITY].name, "�Ѿ� �߷�");
	wsprintf(_sceneBtn[REPORT_SLICE_GAME].name, "�̹��� �����̽�");
	wsprintf(_sceneBtn[REPORT_MINI_MAP].name, "�̴ϸ�");
	wsprintf(_sceneBtn[REPORT_WORM_GAME].name, "������ ����");
	wsprintf(_sceneBtn[REPORT_ATTACK_COMBO].name, "���� �޺� ���");
	wsprintf(_sceneBtn[REPORT_MOTION_ANIMATION].name, "ĳ���� ���");
	wsprintf(_sceneBtn[REPORT_WALL_CATCH].name, "�� ���");
	wsprintf(_sceneBtn[REPORT_RACING_GAME].name, "���̽� ����");
	wsprintf(_sceneBtn[REPORT_BLACK_HOLE].name, "��Ȧ");
	wsprintf(_sceneBtn[REPORT_ATTACK_DEFENSE].name, "���� �� ���");
	wsprintf(_sceneBtn[REPORT_3D_MATRIX].name, "3D Matrix");
	wsprintf(_sceneBtn[REPORT_TILEMAP].name, "Ÿ�ϸ�");

	// ���� ���� �̸�
	wsprintf(_sceneBtn[EXAMPLE_MOLE].name, "�δ��� ����");
	wsprintf(_sceneBtn[EXAMPLE_BULLET].name, "�Ѿ� �߻�");
	wsprintf(_sceneBtn[EXAMPLE_MATH].name, "�ﰢ �Լ�");
	wsprintf(_sceneBtn[EXAMPLE_IMAGE].name, "�̹��� ���");
	wsprintf(_sceneBtn[EXAMPLE_CLIPING].name, "Ŭ���� �̹���");
	wsprintf(_sceneBtn[EXAMPLE_FRAME_IMAGE].name, "������ �̹���");
	wsprintf(_sceneBtn[EXAMPLE_LOOP_RENDER].name, "���� �̹���");
	wsprintf(_sceneBtn[EXAMPLE_TEMP_SOUND].name, "���� ���");
	wsprintf(_sceneBtn[EAMPLE_SHOOTING_GAME].name, "���� ����");

	return S_OK;
}

void TitleScene::release(void)
{
}

void TitleScene::update(void)
{
	for (int i = 0; i < SCENE_INDEX::SCENE_END; i++)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && PtInRect(&_sceneBtn[i].rc, _ptMouse))
		{
			cout << _sceneBtn[i].idx << endl;
			cout << _sceneBtn[i].name << endl;

			//_currentSceneIdx = _sceneBtn[i].idx;
			SCENEMANAGER->changeScene(_sceneBtn[i].idx);
		}
	}
}

void TitleScene::render(void)
{
	TextOut(getMemDC(), 20, 20, "���� ����", strlen("���� ����"));
	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 70, "���� ����", strlen("���� ����"));

	LineMake(getMemDC(), 0, WINSIZE_Y / 2 + 100, WINSIZE_X, WINSIZE_Y / 2 + 100);

	SetTextAlign(getMemDC(), TA_CENTER);
	for (int i = 0; i < SCENE_INDEX::SCENE_END; i++)
	{
		DrawRectMake(getMemDC(), _sceneBtn[i].rc);
		TextOut(getMemDC(),
			_sceneBtn[i].rc.left + (_sceneBtn[i].rc.right - _sceneBtn[i].rc.left) / 2,
			_sceneBtn[i].rc.top + (_sceneBtn[i].rc.bottom - _sceneBtn[i].rc.top) / 2 - 10,
			_sceneBtn[i].name, strlen(_sceneBtn[i].name));
	}

	SetTextAlign(getMemDC(), TA_LEFT);
}

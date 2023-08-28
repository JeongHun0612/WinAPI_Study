#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	for (int i = 0; i < SCENEMANAGER->getSceneLiset().size(); i++)
	{
		// Ÿ��Ʋ ���� ��ư���� ����
		if (SCENEMANAGER->getSceneLiset()[i].first == "Ÿ��Ʋ ��") continue;

		addButton(20 + (i % 6) * 210, 50 + (i / 6) * 80, 180, 50, SCENEMANAGER->getSceneLiset()[i].first);
	}
	

	//for (int i = 0; i < SCENEMANAGER->getSceneList().size(); i++)
	//{

	//	cout << SCENEMANAGER->getSceneList().begin()->first << endl;

	//	//cout << SCENEMANAGER->getSceneList().end()->first << endl;
	//}

	//for (int i = 0; i < SCENE_INDEX::REPORT_END; i++)
	//{
	//	_sceneBtn[i].idx = i;
	//	_sceneBtn[i].rc = RectMake(20 + (i % 6) * 210, 50 + (i / 6) * 80, 180, 50);
	//}

	//for (int i = 0; i < SCENE_INDEX::SCENE_END - SCENE_INDEX::REPORT_END; i++)
	//{
	//	_sceneBtn[i + SCENE_INDEX::REPORT_END].idx = i + SCENE_INDEX::REPORT_END;
	//	_sceneBtn[i + SCENE_INDEX::REPORT_END].rc = RectMake(20 + (i % 6) * 210, (WINSIZE_Y / 2 + 150) + (i / 6) * 80, 180, 50);
	//}

	// ���� ���� �̸�
	//wsprintf(_sceneBtn[REPORT_CARD_MATCH].name, "¦ ���߱�");
	//wsprintf(_sceneBtn[REPORT_MOLE].name, "�δ��� ����");
	//wsprintf(_sceneBtn[REPORT_CLAYSHOOTING].name, "Ŭ���� ���");
	//wsprintf(_sceneBtn[REPORT_AVOID].name, "�� ���ϱ�");
	//wsprintf(_sceneBtn[REPORT_BULLET_SHOOTING].name, "�Ѿ� �߻�");
	//wsprintf(_sceneBtn[REPORT_CROCODILE].name, "�Ǿ� �̻� ����");
	//wsprintf(_sceneBtn[REPORT_VERTICAL_SHOOTING].name, "����ũ�� ����");
	//wsprintf(_sceneBtn[REPORT_HORIZONTAL_SHOOTING].name, "Ⱦ��ũ�� ����");
	//wsprintf(_sceneBtn[REPORT_MOLE_IMAGE].name, "�δ��� ����(�̹���)");
	//wsprintf(_sceneBtn[REPORT_ANALOG_CLOCK].name, "�Ƴ��α� �ð�");
	//wsprintf(_sceneBtn[REPORT_SHELL_FIRE].name, "��ź �߻�");
	//wsprintf(_sceneBtn[REPORT_BULLET_GRAVITY].name, "�Ѿ� �߷�");
	//wsprintf(_sceneBtn[REPORT_SLICE_GAME].name, "�̹��� �����̽�");
	//wsprintf(_sceneBtn[REPORT_MINI_MAP].name, "�̴ϸ�");
	//wsprintf(_sceneBtn[REPORT_WORM_GAME].name, "������ ����");
	//wsprintf(_sceneBtn[REPORT_ATTACK_COMBO].name, "���� �޺� ���");
	//wsprintf(_sceneBtn[REPORT_MOTION_ANIMATION].name, "ĳ���� ���");
	//wsprintf(_sceneBtn[REPORT_WALL_CATCH].name, "�� ���");
	//wsprintf(_sceneBtn[REPORT_RACING_GAME].name, "���̽� ����");
	//wsprintf(_sceneBtn[REPORT_BLACK_HOLE].name, "��Ȧ");
	//wsprintf(_sceneBtn[REPORT_ATTACK_DEFENSE].name, "���� �� ���");
	//wsprintf(_sceneBtn[REPORT_3D_MATRIX].name, "3D Matrix");
	//wsprintf(_sceneBtn[REPORT_TILEMAP].name, "Ÿ�ϸ�");

	//_sceneBtn[0].name = "¦ ���߱�";
	//_sceneBtn[1].name = "�δ��� ����";
	//_sceneBtn[2].name = "Ŭ���� ���";
	//_sceneBtn[3].name = "�� ���ϱ�";
	//_sceneBtn[4].name = "�Ѿ� �߻�";
	//_sceneBtn[5].name = "�Ǿ� �̻� ����";
	//_sceneBtn[6].name = "����ũ�� ����";
	//_sceneBtn[7].name = "Ⱦ��ũ�� ����";
	//_sceneBtn[8].name = "�δ��� ����(�̹���)";
	//_sceneBtn[9].name = "�Ƴ��α� �ð�";
	//_sceneBtn[10].name = "��ź �߻�";
	//_sceneBtn[11].name = "�Ѿ� �߷�";
	//_sceneBtn[12].name = "�̹��� �����̽�";
	//_sceneBtn[13].name = "�̴ϸ�";
	//_sceneBtn[14].name = "������ ����";
	//_sceneBtn[15].name = "���� �޺� ���";
	//_sceneBtn[16].name = "ĳ���� ���";
	//_sceneBtn[17].name = "�� ���";
	//_sceneBtn[18].name = "���̽� ����";
	//_sceneBtn[19].name = "��Ȧ";
	//_sceneBtn[20].name = "���� �� ���";
	//_sceneBtn[21].name = "3D Matrix";
	//_sceneBtn[22].name = "Ÿ�ϸ�";

	// ���� ���� �̸�
	//wsprintf(_sceneBtn[EXAMPLE_MOLE].name, "�δ��� ����");
	//wsprintf(_sceneBtn[EXAMPLE_BULLET].name, "�Ѿ� �߻�");
	//wsprintf(_sceneBtn[EXAMPLE_MATH].name, "�ﰢ �Լ�");
	//wsprintf(_sceneBtn[EXAMPLE_IMAGE].name, "�̹��� ���");
	//wsprintf(_sceneBtn[EXAMPLE_CLIPING].name, "Ŭ���� �̹���");
	//wsprintf(_sceneBtn[EXAMPLE_FRAME_IMAGE].name, "������ �̹���");
	//wsprintf(_sceneBtn[EXAMPLE_LOOP_RENDER].name, "���� �̹���");
	//wsprintf(_sceneBtn[EXAMPLE_TEMP_SOUND].name, "���� ���");
	//wsprintf(_sceneBtn[EAMPLE_SHOOTING_GAME].name, "���� ����");
	//wsprintf(_sceneBtn[EXAMPLE_TENGAI].name, "�ٰ���");
	//wsprintf(_sceneBtn[EXAMPLE_ANIMATION].name, "�ִϸ��̼�");

	return S_OK;
}

void TitleScene::release(void)
{
}

void TitleScene::update(void)
{
	//for (_viSceneBtn = _vSceneBtn.begin(); _viSceneBtn != _vSceneBtn.end(); ++_viSceneBtn)
	//{
	//	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && PtInRect(&_viSceneBtn->rc, _ptMouse))
	//	{
	//		SCENEMANAGER->changeScene(_viSceneBtn->name);
	//	}
	//}
}

void TitleScene::render(void)
{
	TextOut(getMemDC(), 20, 20, "���� ����", strlen("���� ����"));
	LineMake(getMemDC(), 0, 50, WINSIZE_X, 50);

	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 70, "���� ����", strlen("���� ����"));
	LineMake(getMemDC(), 0, WINSIZE_Y / 2 + 100, WINSIZE_X, WINSIZE_Y / 2 + 100);

	SetTextAlign(getMemDC(), TA_CENTER);

	//for (auto iter = _vSceneBtn.begin(); iter != _vSceneBtn.end(); ++iter)
	//{
	//	DrawRectMake(getMemDC(), iter->rc);
	//	//RectangleMakeCenter(getMemDC(), iter->x, iter->y, 180, 50);
	//}

	//for (auto iter : _vSceneBtn)
	//{
	//	DrawRectMake(getMemDC(), iter.rc);
	//}

	for (_viSceneBtn = _vSceneBtn.begin(); _viSceneBtn != _vSceneBtn.end(); ++_viSceneBtn)
	{
		//DrawRectMake(getMemDC(), _viSceneBtn->rc);
		Rectangle(getMemDC(), _viSceneBtn->rc.left, _viSceneBtn->rc.top, _viSceneBtn->rc.right, _viSceneBtn->rc.bottom);
		//TextOut(getMemDC(), _viSceneBtn->x, _viSceneBtn->y, _viSceneBtn->name.c_str(), _viSceneBtn->name.length());
	}

	SetTextAlign(getMemDC(), TA_LEFT);
}

void TitleScene::addButton(float x, float y, int width, int height, string text)
{
	Button btn;
	btn.x = x;
	btn.y = y;
	btn.rc = RectMakeCenter(btn.x, btn.y, width, height);
	btn.name = text;

	_vSceneBtn.push_back(btn);
}

#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	Button sceneBtn;

	SOUNDMANAGER->play("Ÿ��Ʋ", 1.0f);

	// ���� �� ��ư ��� ===============================================================================================================
	sceneBtn.init("¦ ���߱�", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	//sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("¦ ���߱�"); });

	sceneBtn.setOnClick(bind(testFunc, "¦ ���߱�"));

	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�δ��� ����", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�δ��� ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("Ŭ���� ���", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("Ŭ���� ���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�� ���ϱ�", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�� ���ϱ�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�Ѿ� �߻�", REPORT_START_X + (WIDTH + INTERVAL_X) * 4, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�Ѿ� �߻�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�Ǿ� �̻� ����", REPORT_START_X + (WIDTH + INTERVAL_X) * 5, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�Ǿ� �̻� ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("����ũ�� ����", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("����ũ�� ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("Ⱦ��ũ�� ����", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("Ⱦ��ũ�� ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�δ��� ����(�̹���)", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�δ��� ����(�̹���)"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�Ƴ��α� �ð�", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�Ƴ��α� �ð�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("��ź �߻�", REPORT_START_X + (WIDTH + INTERVAL_X) * 4, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("��ź �߻�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�Ѿ� �߷�", REPORT_START_X + (WIDTH + INTERVAL_X) * 5, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�Ѿ� �߷�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�̹��� �����̽�", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�̹��� �����̽�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�̴ϸ�", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�̴ϸ�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("������ ����", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("������ ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("���� �޺� ���", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("���� �޺� ���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�� ���", REPORT_START_X + (WIDTH + INTERVAL_X) * 4, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�� ���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("���̽� ����", REPORT_START_X + (WIDTH + INTERVAL_X) * 5, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 2, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("���̽� ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("��Ȧ", REPORT_START_X + (WIDTH + INTERVAL_X) * 0, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("��Ȧ"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("���� �� ���", REPORT_START_X + (WIDTH + INTERVAL_X) * 1, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("���� �� ���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("3D Matrix", REPORT_START_X + (WIDTH + INTERVAL_X) * 2, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("3D Matrix"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("Ÿ�ϸ�", REPORT_START_X + (WIDTH + INTERVAL_X) * 3, REPORT_START_Y + (HEIGHT + INTERVAL_Y) * 3, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("Ÿ�ϸ�"); });
	_vSceneBtn.push_back(sceneBtn);


	// ���� ���� �� ��ư ��� ===============================================================================================================

	sceneBtn.init("�δ��� ����", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 0, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�δ��� ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�Ѿ� �߻�", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 1, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�Ѿ� �߻�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�ﰢ �Լ�", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 2, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�ﰢ �Լ�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�̹��� ���", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 3, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�̹��� ���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("Ŭ���� �̹���", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 4, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("Ŭ���� �̹���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("������ �̹���", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 5, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 0, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("������ �̹���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("���� �̹���", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 0, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("���� �̹���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("���� ���", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 1, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("���� ���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("���� ����", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 2, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("���� ����"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�ٰ���", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 3, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�ٰ���"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("�ִϸ��̼�", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 4, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("�ִϸ��̼�"); });
	_vSceneBtn.push_back(sceneBtn);

	sceneBtn.init("INI ������", EXAMPLE_START_X + (WIDTH + INTERVAL_X) * 5, EXAMPLE_START_Y + (HEIGHT + INTERVAL_Y) * 1, WIDTH, HEIGHT);
	sceneBtn.setOnClick([]() { SCENEMANAGER->changeScene("INI ������"); });
	_vSceneBtn.push_back(sceneBtn);

	return S_OK;
}

void TitleScene::release(void)
{
}

void TitleScene::update(void)
{
	for (_viSceneBtn = _vSceneBtn.begin(); _viSceneBtn != _vSceneBtn.end(); ++_viSceneBtn)
	{
		_viSceneBtn->update();
	}
}

void TitleScene::render(void)
{
	TextOut(getMemDC(), 20, 20, "���� ����", strlen("���� ����"));
	LineMake(getMemDC(), 0, 50, WINSIZE_X, 50);

	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 70, "���� ����", strlen("���� ����"));
	LineMake(getMemDC(), 0, WINSIZE_Y / 2 + 100, WINSIZE_X, WINSIZE_Y / 2 + 100);

	for (_viSceneBtn = _vSceneBtn.begin(); _viSceneBtn != _vSceneBtn.end(); ++_viSceneBtn)
	{
		_viSceneBtn->render();
	}
}

void TitleScene::testFunc(string sceneName)
{
	SCENEMANAGER->changeScene(sceneName);
}

#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	Button sceneBtn;

	// ��ư ���
	int count = 0;
	int startPosX = REPORT_START_X;
	int startPosY = REPORT_START_Y;

	for (int i = 0; i < SCENEMANAGER->getSceneLiset().size() - 1; i++, count++)
	{
		// ���⼭ ���� ���� ��
		if (SCENEMANAGER->getSceneLiset()[i].first == "�δ��� ����")
		{
			count = 0;
			startPosX = EXAMPLE_START_X;
			startPosY = EXAMPLE_START_Y;
		}

		Button sceneBtn;

		sceneBtn.init(SCENEMANAGER->getSceneLiset()[i].first, startPosX + (WIDTH + INTERVAL_X) * (count % 6), startPosY + (HEIGHT + INTERVAL_Y) * (count / 6), WIDTH, HEIGHT);
		sceneBtn.setOnClick(bind(nextSceneEvent, SCENEMANAGER->getSceneLiset()[i].first));
		_vSceneBtn.push_back(sceneBtn);
	}

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

void TitleScene::nextSceneEvent(string sceneName)
{
	SCENEMANAGER->changeScene(sceneName);
}

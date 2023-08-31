#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	Button sceneBtn;

	// 버튼 등록
	int count = 0;
	int startPosX = REPORT_START_X;
	int startPosY = REPORT_START_Y;

	for (int i = 0; i < SCENEMANAGER->getSceneLiset().size() - 1; i++, count++)
	{
		// 여기서 부터 과제 씬
		if (SCENEMANAGER->getSceneLiset()[i].first == "두더지 예제")
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
	TextOut(getMemDC(), 20, 20, "과제 파일", strlen("과제 파일"));
	LineMake(getMemDC(), 0, 50, WINSIZE_X, 50);

	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 70, "수업 파일", strlen("수업 파일"));
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

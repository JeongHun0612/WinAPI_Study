#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	for (int i = 0; i < SCENEMANAGER->getSceneLiset().size(); i++)
	{
		// 타이틀 씬은 버튼에서 제외
		if (SCENEMANAGER->getSceneLiset()[i].first == "타이틀 씬") continue;

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

	// 과제 파일 이름
	//wsprintf(_sceneBtn[REPORT_CARD_MATCH].name, "짝 맞추기");
	//wsprintf(_sceneBtn[REPORT_MOLE].name, "두더지 게임");
	//wsprintf(_sceneBtn[REPORT_CLAYSHOOTING].name, "클레이 사격");
	//wsprintf(_sceneBtn[REPORT_AVOID].name, "똥 피하기");
	//wsprintf(_sceneBtn[REPORT_BULLET_SHOOTING].name, "총알 발사");
	//wsprintf(_sceneBtn[REPORT_CROCODILE].name, "악어 이빨 게임");
	//wsprintf(_sceneBtn[REPORT_VERTICAL_SHOOTING].name, "종스크롤 슈팅");
	//wsprintf(_sceneBtn[REPORT_HORIZONTAL_SHOOTING].name, "횡스크롤 슈팅");
	//wsprintf(_sceneBtn[REPORT_MOLE_IMAGE].name, "두더지 게임(이미지)");
	//wsprintf(_sceneBtn[REPORT_ANALOG_CLOCK].name, "아날로그 시계");
	//wsprintf(_sceneBtn[REPORT_SHELL_FIRE].name, "포탄 발사");
	//wsprintf(_sceneBtn[REPORT_BULLET_GRAVITY].name, "총알 중력");
	//wsprintf(_sceneBtn[REPORT_SLICE_GAME].name, "이미지 슬라이스");
	//wsprintf(_sceneBtn[REPORT_MINI_MAP].name, "미니맵");
	//wsprintf(_sceneBtn[REPORT_WORM_GAME].name, "지렁이 게임");
	//wsprintf(_sceneBtn[REPORT_ATTACK_COMBO].name, "공격 콤보 모션");
	//wsprintf(_sceneBtn[REPORT_MOTION_ANIMATION].name, "캐릭터 모션");
	//wsprintf(_sceneBtn[REPORT_WALL_CATCH].name, "벽 잡기");
	//wsprintf(_sceneBtn[REPORT_RACING_GAME].name, "레이싱 게임");
	//wsprintf(_sceneBtn[REPORT_BLACK_HOLE].name, "블랙홀");
	//wsprintf(_sceneBtn[REPORT_ATTACK_DEFENSE].name, "공격 및 방어");
	//wsprintf(_sceneBtn[REPORT_3D_MATRIX].name, "3D Matrix");
	//wsprintf(_sceneBtn[REPORT_TILEMAP].name, "타일맵");

	//_sceneBtn[0].name = "짝 맞추기";
	//_sceneBtn[1].name = "두더지 게임";
	//_sceneBtn[2].name = "클레이 사격";
	//_sceneBtn[3].name = "똥 피하기";
	//_sceneBtn[4].name = "총알 발사";
	//_sceneBtn[5].name = "악어 이빨 게임";
	//_sceneBtn[6].name = "종스크롤 슈팅";
	//_sceneBtn[7].name = "횡스크롤 슈팅";
	//_sceneBtn[8].name = "두더지 게임(이미지)";
	//_sceneBtn[9].name = "아날로그 시계";
	//_sceneBtn[10].name = "포탄 발사";
	//_sceneBtn[11].name = "총알 중력";
	//_sceneBtn[12].name = "이미지 슬라이스";
	//_sceneBtn[13].name = "미니맵";
	//_sceneBtn[14].name = "지렁이 게임";
	//_sceneBtn[15].name = "공격 콤보 모션";
	//_sceneBtn[16].name = "캐릭터 모션";
	//_sceneBtn[17].name = "벽 잡기";
	//_sceneBtn[18].name = "레이싱 게임";
	//_sceneBtn[19].name = "블랙홀";
	//_sceneBtn[20].name = "공격 및 방어";
	//_sceneBtn[21].name = "3D Matrix";
	//_sceneBtn[22].name = "타일맵";

	// 수업 예제 이름
	//wsprintf(_sceneBtn[EXAMPLE_MOLE].name, "두더지 예제");
	//wsprintf(_sceneBtn[EXAMPLE_BULLET].name, "총알 발사");
	//wsprintf(_sceneBtn[EXAMPLE_MATH].name, "삼각 함수");
	//wsprintf(_sceneBtn[EXAMPLE_IMAGE].name, "이미지 출력");
	//wsprintf(_sceneBtn[EXAMPLE_CLIPING].name, "클리핑 이미지");
	//wsprintf(_sceneBtn[EXAMPLE_FRAME_IMAGE].name, "프레임 이미지");
	//wsprintf(_sceneBtn[EXAMPLE_LOOP_RENDER].name, "루프 이미지");
	//wsprintf(_sceneBtn[EXAMPLE_TEMP_SOUND].name, "사운드 재생");
	//wsprintf(_sceneBtn[EAMPLE_SHOOTING_GAME].name, "슈팅 게임");
	//wsprintf(_sceneBtn[EXAMPLE_TENGAI].name, "텐가이");
	//wsprintf(_sceneBtn[EXAMPLE_ANIMATION].name, "애니메이션");

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
	TextOut(getMemDC(), 20, 20, "과제 파일", strlen("과제 파일"));
	LineMake(getMemDC(), 0, 50, WINSIZE_X, 50);

	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 70, "수업 파일", strlen("수업 파일"));
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

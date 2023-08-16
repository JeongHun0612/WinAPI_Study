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

	// 과제 파일 이름
	wsprintf(_sceneBtn[REPORT_CARD_MATCH].name, "짝 맞추기");
	wsprintf(_sceneBtn[REPORT_MOLE].name, "두더지 게임");
	wsprintf(_sceneBtn[REPORT_CLAYSHOOTING].name, "클레이 사격");
	wsprintf(_sceneBtn[REPORT_AVOID].name, "똥 피하기");
	wsprintf(_sceneBtn[REPORT_BULLET_SHOOTING].name, "총알 발사");
	wsprintf(_sceneBtn[REPORT_CROCODILE].name, "악어 이빨 게임");
	wsprintf(_sceneBtn[REPORT_VERTICAL_SHOOTING].name, "종스크롤 슈팅");
	wsprintf(_sceneBtn[REPORT_HORIZONTAL_SHOOTING].name, "횡스크롤 슈팅");
	wsprintf(_sceneBtn[REPORT_MOLE_IMAGE].name, "두더지 게임(이미지)");
	wsprintf(_sceneBtn[REPORT_ANALOG_CLOCK].name, "아날로그 시계");
	wsprintf(_sceneBtn[REPORT_SHELL_FIRE].name, "포탄 발사");
	wsprintf(_sceneBtn[REPORT_BULLET_GRAVITY].name, "총알 중력");
	wsprintf(_sceneBtn[REPORT_SLICE_GAME].name, "이미지 슬라이스");
	wsprintf(_sceneBtn[REPORT_MINI_MAP].name, "미니맵");
	wsprintf(_sceneBtn[REPORT_WORM_GAME].name, "지렁이 게임");
	wsprintf(_sceneBtn[REPORT_ATTACK_COMBO].name, "공격 콤보 모션");
	wsprintf(_sceneBtn[REPORT_MOTION_ANIMATION].name, "캐릭터 모션");
	wsprintf(_sceneBtn[REPORT_WALL_CATCH].name, "벽 잡기");
	wsprintf(_sceneBtn[REPORT_RACING_GAME].name, "레이싱 게임");
	wsprintf(_sceneBtn[REPORT_BLACK_HOLE].name, "블랙홀");
	wsprintf(_sceneBtn[REPORT_ATTACK_DEFENSE].name, "공격 및 방어");
	wsprintf(_sceneBtn[REPORT_3D_MATRIX].name, "3D Matrix");
	wsprintf(_sceneBtn[REPORT_TILEMAP].name, "타일맵");

	// 수업 예제 이름
	wsprintf(_sceneBtn[EXAMPLE_MOLE].name, "두더지 예제");
	wsprintf(_sceneBtn[EXAMPLE_BULLET].name, "총알 발사");
	wsprintf(_sceneBtn[EXAMPLE_MATH].name, "삼각 함수");
	wsprintf(_sceneBtn[EXAMPLE_IMAGE].name, "이미지 출력");
	wsprintf(_sceneBtn[EXAMPLE_CLIPING].name, "클리핑 이미지");
	wsprintf(_sceneBtn[EXAMPLE_FRAME_IMAGE].name, "프레임 이미지");
	wsprintf(_sceneBtn[EXAMPLE_LOOP_RENDER].name, "루프 이미지");
	wsprintf(_sceneBtn[EXAMPLE_TEMP_SOUND].name, "사운드 재생");
	wsprintf(_sceneBtn[EAMPLE_SHOOTING_GAME].name, "슈팅 게임");

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
	TextOut(getMemDC(), 20, 20, "과제 파일", strlen("과제 파일"));
	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 70, "수업 파일", strlen("수업 파일"));

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

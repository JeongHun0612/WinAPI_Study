#include "Stdafx.h"
#include "TitleScene.h"

HRESULT TitleScene::init(void)
{
	// 과제 파일 초기화
	for (int i = 0; i < REPORT_INDEX::REPORT_END; i++)
	{
		_reportBtn[i].idx = i;
		_reportBtn[i].rc = RectMake(20 + (i % 6) * 210, 50 + (i / 6) * 80, 180, 50);
	}

	wsprintf(_reportBtn[REPORT_CARD_MATCH].name, "짝 맞추기");
	wsprintf(_reportBtn[REPORT_MOLE].name, "두더지 게임");
	wsprintf(_reportBtn[REPORT_CLAYSHOOTING].name, "클레이 사격");
	wsprintf(_reportBtn[REPORT_AVOID].name, "똥 피하기");
	wsprintf(_reportBtn[REPORT_BULLET_SHOOTING].name, "총알 발사");
	wsprintf(_reportBtn[REPORT_CROCODILE].name, "악어 이빨 게임");
	wsprintf(_reportBtn[REPORT_VERTICAL_SHOOTING].name, "종스크롤 슈팅");
	wsprintf(_reportBtn[REPORT_HORIZONTAL_SHOOTING].name, "횡스크롤 슈팅");
	wsprintf(_reportBtn[REPORT_MOLE_IMAGE].name, "두더지 게임(이미지)");
	wsprintf(_reportBtn[REPORT_ANALOG_CLOCK].name, "아날로그 시계");
	wsprintf(_reportBtn[REPORT_SHELL_FIRE].name, "포탄 발사");
	wsprintf(_reportBtn[REPORT_BULLET_GRAVITY].name, "총알 중력");
	wsprintf(_reportBtn[REPORT_SLICE_GAME].name, "이미지 슬라이스");
	wsprintf(_reportBtn[REPORT_MINI_MAP].name, "미니맵");
	wsprintf(_reportBtn[REPORT_WORM_GAME].name, "지렁이 게임");
	wsprintf(_reportBtn[REPORT_ATTACK_COMBO].name, "공격 콤보 모션");
	wsprintf(_reportBtn[REPORT_MOTION_ANIMATION].name, "캐릭터 모션");
	wsprintf(_reportBtn[REPORT_WALL_CATCH].name, "벽 잡기");


	// 수업 파일 초기화
	for (int i = 0; i < EXAMPLE_INDEX::EXAMPLE_END; i++)
	{
		_exampleBtn[i].idx = REPORT_INDEX::REPORT_END + i;
		_exampleBtn[i].rc = RectMake(20 + (i % 6) * 210, (WINSIZE_Y / 2 + 50) + (i / 6) * 80, 180, 50);
	}

	wsprintf(_exampleBtn[EXAMPLE_MOLE].name, "두더지 게임");
	wsprintf(_exampleBtn[EXAMPLE_BULLET].name, "총알 발사");
	wsprintf(_exampleBtn[EXAMPLE_MATH].name, "삼각 함수");
	wsprintf(_exampleBtn[EXAMPLE_IMAGE].name, "이미지 출력");
	wsprintf(_exampleBtn[EXAMPLE_CLIPING].name, "클리핑 이미지");
	wsprintf(_exampleBtn[EXAMPLE_FRAME_IMAGE].name, "프레임 이미지");

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
	TextOut(getMemDC(), 20, 20, "과제 파일", strlen("과제 파일"));
	TextOut(getMemDC(), 20, WINSIZE_Y / 2 + 20, "수업 파일", strlen("수업 파일"));

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

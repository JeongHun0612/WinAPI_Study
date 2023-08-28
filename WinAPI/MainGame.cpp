#include "Stdafx.h"
#include "MainGame.h"
#include "TitleScene.h"

// 과제 ==========================================================
#include "Report_CardMatch.h"
#include "Report_Mole.h"
#include "Report_ClayShooting.h"
#include "Report_Avoid.h"
#include "Report_BulletShooting.h"
#include "Report_Crocodile.h"
#include "Report_Vertical_Shooting.h";
#include "Report_Horizontal_Shooting.h"
#include "Report_Mole_Image.h"
#include "Report_Analog_Clock.h"
#include "Report_Shell_Fire.h"
#include "Report_Bullet_Gravity.h"
#include "Report_Slice_Game.h"
#include "Report_Mini_Map.h"
#include "Report_Worm_Game.h"
#include "Report_Attack_Combo.h"
#include "Report_Motion_Animation.h"
#include "Report_Wall_Catch.h"
#include "Report_Racing_Game.h"
#include "Report_Black_Hole.h"
#include "Report_Attack_Defense.h"
#include "Report_3D_Matrix.h"
#include "Report_TileMap.h"


// 수업 예제 =====================================================
#include "Example_Mole.h"
#include "Example_Bullet.h"
#include "Example_Math.h"
#include "Example_Image.h"
#include "Example_Cliping.h"
#include "Example_FrameImage.h"
#include "Example_Loop_Render.h"
#include "Example_TempSound.h"
#include "Example_Shooting_Game.h"
#include "Example_Tengai.h"
#include "Example_Animation.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	// 씬 추가
	addScene();

	// 초기 화면 (타이틀) <->
	SCENEMANAGER->changeScene("타이틀 씬");

	/*
	▶ assert

	<-> assert를 찾기 위해 사용하는 키워드 (프로그래머 팁)
	- C
	assert(_currentScene != nullptr, "MainGame 초기화 부분에서 노드 파트 오류 발생");
	- C++
	static_assert()

	- 디버깅 모드에서 동작하는 오류 검출용 함수
	ㄴ 릴리즈 모드에서는 동작하지 않는다.

	- assert 함수에 걸리게 되면 버그 발생 위치 / 콜 스택 등 여러 정보를 알 수 있다.
		ㄴ Expression -> flase -> assert error

	- 대부분의 문법이 true일때만 동작하지만 assert()는 false일때 동작을 한다.
		ㄴ 그렇기 때문에 일어나면 안되는 조건이 아니라 꼭 일어나야 하는 조건을 명시해야 한다.

	EX) assert(A != NULL);
		ㄴ A가 NULL이 아니면 true이 나오게 되므로 패스
		ㄴ A가 NULL이 맞다면 false가 나오게 되므로 assert error


		aeert() : "C" -> 컴파일 타임을 지나 프로그램을 실행 시키고 문제를 파악
		static_assert : "C++" -> 컴파일 중에 문제를 파악 (상수 값을 떠올려야 한다.)
	*/

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
}

void MainGame::update(void)
{
	GameNode::update();

	SCENEMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK)
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		// 타이틀 씬 복귀
		SCENEMANAGER->changeScene("타이틀 씬");
	}
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==================================================================

	SCENEMANAGER->render();

	// ==================================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

void MainGame::addScene()
{
	// 타이틀 씬 추가
	SCENEMANAGER->addScene("타이틀 씬", new TitleScene);

	// 과제 씬 추가
	SCENEMANAGER->addScene("짝 맞추기", new Report_CardMatch);
	SCENEMANAGER->addScene("두더지 게임", new Report_Mole);
	SCENEMANAGER->addScene("클레이 사격", new Report_ClayShooting);
	SCENEMANAGER->addScene("똥 피하기", new Report_Avoid);
	SCENEMANAGER->addScene("총알 발사", new Report_BulletShooting);
	SCENEMANAGER->addScene("악어 이빨 게임", new Report_Crocodile);
	SCENEMANAGER->addScene("종스크롤 슈팅", new Report_Vertical_Shooting);
	SCENEMANAGER->addScene("횡스크롤 슈팅", new Report_Horizontal_Shooting);
	SCENEMANAGER->addScene("두더지 게임(이미지)", new Report_Mole_Image);
	SCENEMANAGER->addScene("아날로그 시계", new Report_Analog_Clock);
	SCENEMANAGER->addScene("포탄 발사", new Report_Shell_Fire);
	SCENEMANAGER->addScene("총알 중력", new Report_Bullet_Gravity);
	SCENEMANAGER->addScene("이미지 슬라이스", new Report_Slice_Game);
	SCENEMANAGER->addScene("미니맵", new Report_Mini_Map);
	SCENEMANAGER->addScene("지렁이 게임", new Report_Worm_Game);
	SCENEMANAGER->addScene("공격 콤보 모션", new Report_Attack_Combo);
	SCENEMANAGER->addScene("캐릭터 모션", new Report_Motion_Animation);
	SCENEMANAGER->addScene("벽 잡기", new Report_Wall_Catch);
	SCENEMANAGER->addScene("레이싱 게임", new Report_Racing_Game);
	SCENEMANAGER->addScene("블랙홀", new Report_Black_Hole);
	SCENEMANAGER->addScene("공격 및 방어", new Report_Attack_Defense);
	SCENEMANAGER->addScene("3D Matrix", new Report_3D_Matrix);
	SCENEMANAGER->addScene("타일맵", new Report_TileMap);


	// 수업 예제 씬 추가
	//SCENEMANAGER->addScene(EXAMPLE_MOLE, new Example_Mole);
	//SCENEMANAGER->addScene(EXAMPLE_BULLET, new Example_Bullet);
	//SCENEMANAGER->addScene(EXAMPLE_MATH, new Example_Math);
	//SCENEMANAGER->addScene(EXAMPLE_IMAGE, new Example_Image);
	//SCENEMANAGER->addScene(EXAMPLE_CLIPING, new Example_Cliping);
	//SCENEMANAGER->addScene(EXAMPLE_FRAME_IMAGE, new Example_FrameImage);
	//SCENEMANAGER->addScene(EXAMPLE_LOOP_RENDER, new Example_Loop_Render);
	//SCENEMANAGER->addScene(EXAMPLE_TEMP_SOUND, new Example_TempSound);
	//SCENEMANAGER->addScene(EAMPLE_SHOOTING_GAME, new Example_Shooting_Game);
	//SCENEMANAGER->addScene(EXAMPLE_TENGAI, new Example_Tengai);
	//SCENEMANAGER->addScene(EXAMPLE_ANIMATION, new Example_Animation);
}
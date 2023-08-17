#include "Stdafx.h"
#include "MainGame.h"
#include "TitleScene.h"

// ���� ==========================================================
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


// ���� ���� =====================================================
#include "Example_Mole.h"
#include "Example_Bullet.h"
#include "Example_Math.h"
#include "Example_Image.h"
#include "Example_Cliping.h"
#include "Example_FrameImage.h"
#include "Example_Loop_Render.h"
#include "Example_TempSound.h"
#include "Example_Shooting_Game.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	// �� �߰�
	addScene();

	// �ʱ� ȭ�� (Ÿ��Ʋ) <->
	assert(SCENEMANAGER->changeScene(TITLE_SCENE));

	/*
	�� assert

	<-> assert�� ã�� ���� ����ϴ� Ű���� (���α׷��� ��)
	- C
	assert(_currentScene != nullptr, "MainGame �ʱ�ȭ �κп��� ��� ��Ʈ ���� �߻�");
	- C++
	static_assert()

	- ����� ��忡�� �����ϴ� ���� ����� �Լ�
	�� ������ ��忡���� �������� �ʴ´�.

	- assert �Լ��� �ɸ��� �Ǹ� ���� �߻� ��ġ / �� ���� �� ���� ������ �� �� �ִ�.
		�� Expression -> flase -> assert error

	- ��κ��� ������ true�϶��� ���������� assert()�� false�϶� ������ �Ѵ�.
		�� �׷��� ������ �Ͼ�� �ȵǴ� ������ �ƴ϶� �� �Ͼ�� �ϴ� ������ ����ؾ� �Ѵ�.

	EX) assert(A != NULL);
		�� A�� NULL�� �ƴϸ� true�� ������ �ǹǷ� �н�
		�� A�� NULL�� �´ٸ� false�� ������ �ǹǷ� assert error


		aeert() : "C" -> ������ Ÿ���� ���� ���α׷��� ���� ��Ű�� ������ �ľ�
		static_assert : "C++" -> ������ �߿� ������ �ľ� (��� ���� ���÷��� �Ѵ�.)
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
	TIMEMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		if (MessageBox(_hWnd, "������ �����Ͻðڽ��ϱ�?", "����Ȯ��", MB_OKCANCEL) == IDOK)
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		// Ÿ��Ʋ �� ����
		SCENEMANAGER->changeScene(TITLE_SCENE);
	}
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	// ==================================================================

	SCENEMANAGER->render();
	//TIMEMANAGER->render(getMemDC());

	// ==================================================================
	SetTextAlign(getMemDC(), TA_LEFT);
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

void MainGame::addScene()
{
	// Ÿ��Ʋ �� �߰�
	SCENEMANAGER->addScene(TITLE_SCENE, new TitleScene);

	// ���� �� �߰�
	SCENEMANAGER->addScene(REPORT_CARD_MATCH, new Report_CardMatch);
	SCENEMANAGER->addScene(REPORT_MOLE, new Report_Mole);
	SCENEMANAGER->addScene(REPORT_CLAYSHOOTING, new Report_ClayShooting);
	SCENEMANAGER->addScene(REPORT_AVOID, new Report_Avoid);
	SCENEMANAGER->addScene(REPORT_BULLET_SHOOTING, new Report_BulletShooting);
	SCENEMANAGER->addScene(REPORT_CROCODILE, new Report_Crocodile);
	SCENEMANAGER->addScene(REPORT_VERTICAL_SHOOTING, new Report_Vertical_Shooting);
	SCENEMANAGER->addScene(REPORT_HORIZONTAL_SHOOTING, new Report_Horizontal_Shooting);
	SCENEMANAGER->addScene(REPORT_MOLE_IMAGE, new Report_Mole_Image);
	SCENEMANAGER->addScene(REPORT_ANALOG_CLOCK, new Report_Analog_Clock);
	SCENEMANAGER->addScene(REPORT_SHELL_FIRE, new Report_Shell_Fire);
	SCENEMANAGER->addScene(REPORT_BULLET_GRAVITY, new Report_Bullet_Gravity);
	SCENEMANAGER->addScene(REPORT_SLICE_GAME, new Report_Slice_Game);
	SCENEMANAGER->addScene(REPORT_MINI_MAP, new Report_Mini_Map);
	SCENEMANAGER->addScene(REPORT_WORM_GAME, new Report_Worm_Game);
	SCENEMANAGER->addScene(REPORT_ATTACK_COMBO, new Report_Attack_Combo);
	SCENEMANAGER->addScene(REPORT_MOTION_ANIMATION, new Report_Motion_Animation);
	SCENEMANAGER->addScene(REPORT_WALL_CATCH, new Report_Wall_Catch);
	SCENEMANAGER->addScene(REPORT_RACING_GAME, new Report_Racing_Game);
	SCENEMANAGER->addScene(REPORT_BLACK_HOLE, new Report_Black_Hole);
	SCENEMANAGER->addScene(REPORT_ATTACK_DEFENSE, new Report_Attack_Defense);
	SCENEMANAGER->addScene(REPORT_3D_MATRIX, new Report_3D_Matrix);
	SCENEMANAGER->addScene(REPORT_TILEMAP, new Report_TileMap);


	// ���� ���� �� �߰�
	SCENEMANAGER->addScene(EXAMPLE_MOLE, new Example_Mole);
	SCENEMANAGER->addScene(EXAMPLE_BULLET, new Example_Bullet);
	SCENEMANAGER->addScene(EXAMPLE_MATH, new Example_Math);
	SCENEMANAGER->addScene(EXAMPLE_IMAGE, new Example_Image);
	SCENEMANAGER->addScene(EXAMPLE_CLIPING, new Example_Cliping);
	SCENEMANAGER->addScene(EXAMPLE_FRAME_IMAGE, new Example_FrameImage);
	SCENEMANAGER->addScene(EXAMPLE_LOOP_RENDER, new Example_Loop_Render);
	SCENEMANAGER->addScene(EXAMPLE_TEMP_SOUND, new Example_TempSound);
	SCENEMANAGER->addScene(EAMPLE_SHOOTING_GAME, new Example_Shooting_Game);
}
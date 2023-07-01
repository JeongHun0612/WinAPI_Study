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


// 수업 예제 =====================================================
#include "Example_Mole.h"
#include "Example_Bullet.h"
#include "Example_Math.h"
#include "Example_Image.h"
#include "Example_Cliping.h"
#include "Example_FrameImage.h"


HRESULT MainGame::init(void)
{
	GameNode::init(true);

	_currentSceneIdx = SCENE_INDEX::TITLE_SCENE;
	_titleScene = new TitleScene;
	_titleScene->init();
	_currentScene = nullptr;

	_isTitle = true;

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	_titleScene->release();
}

void MainGame::update(void)
{
	GameNode::update();

	if (_isTitle)
	{
		_titleScene->update();
	}
	else
	{
		_currentScene->update();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		// 게임 종료
		if (_isTitle)
		{
			if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK)
			{
				PostQuitMessage(0);
			}
		}

		// 타이틀 씬 복귀
		else
		{
			_currentSceneIdx = SCENE_INDEX::TITLE_SCENE;
			_isTitle = true;
			_currentScene->release();
			_currentScene = nullptr;
		}
	}

	if (_currentSceneIdx != SCENE_INDEX::TITLE_SCENE && _currentScene == nullptr)
	{
		switch (_currentSceneIdx)
		{
		// 과제 클래스 초기화 =============================================================================================================
		case SCENE_INDEX::REPORT_CARD_MATCH:
			_currentScene = new Report_CardMatch;
			break;
		case SCENE_INDEX::REPORT_MOLE:
			_currentScene = new Report_Mole;
			break;
		case SCENE_INDEX::REPORT_CLAYSHOOTING:
			_currentScene = new Report_ClayShooting;
			break;
		case SCENE_INDEX::REPORT_AVOID:
			_currentScene = new Report_Avoid;
			break;
		case SCENE_INDEX::REPORT_BULLET_SHOOTING:
			_currentScene = new Report_BulletShooting;
			break;
		case SCENE_INDEX::REPORT_CROCODILE:
			_currentScene = new Report_Crocodile;
			break;
		case SCENE_INDEX::REPORT_VERTICAL_SHOOTING:
			_currentScene = new Report_Vertical_Shooting;
			break;
		case SCENE_INDEX::REPORT_HORIZONTAL_SHOOTING:
			_currentScene = new Report_Horizontal_Shooting;
			break;
		case SCENE_INDEX::REPORT_MOLE_IMAGE:
			_currentScene = new Report_Mole_Image;
			break;
		case SCENE_INDEX::REPORT_ANALOG_CLOCK:
			_currentScene = new Report_Analog_Clock;
			break;
		case SCENE_INDEX::REPORT_SHELL_FIRE:
			_currentScene = new Report_Shell_Fire;
			break;
		case SCENE_INDEX::REPORT_BULLET_GRAVITY:
			_currentScene = new Report_Bullet_Gravity;
			break;
		case SCENE_INDEX::REPORT_SLICE_GAME:
			_currentScene = new Report_Slice_Game;
			break;
		case SCENE_INDEX::REPORT_MINI_MAP:
			_currentScene = new Report_Mini_Map;
			break;
		case SCENE_INDEX::REPORT_WORM_GAME:
			_currentScene = new Report_Worm_Game;
			break;
		case SCENE_INDEX::REPORT_ATTACK_COMBO:
			_currentScene = new Report_Attack_Combo;
			break;
		case SCENE_INDEX::REPORT_MOTION_ANIMATION:
			_currentScene = new Report_Motion_Animation;
			break;
		case SCENE_INDEX::REPORT_WALL_CATCH:
			_currentScene = new Report_Wall_Catch;
			break;

		// 수업 예제 클래스 초기화 =============================================================================================================
		case SCENE_INDEX::EXAMPLE_MOLE:
			_currentScene = new Example_Mole;
			break;
		case SCENE_INDEX::EXAMPLE_BULLET:
			_currentScene = new Example_Bullet;
			break;
		case SCENE_INDEX::EXAMPLE_MATH:
			_currentScene = new Example_Math;
			break;
		case SCENE_INDEX::EXAMPLE_IMAGE:
			_currentScene = new Example_Image;
			break;
		case SCENE_INDEX::EXAMPLE_CLIPING:
			_currentScene = new Example_Cliping;
			break;
		case SCENE_INDEX::EXAMPLE_FRAME_IMAGE:
			_currentScene = new Example_FrameImage;
			break;
		}

		_isTitle = false;
		_currentScene->init();
	}
}

void MainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	if (_isTitle)
	{
		_titleScene->render();
	}
	else
	{
		_currentScene->render();
	}

	SetTextAlign(getMemDC(), TA_LEFT);
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
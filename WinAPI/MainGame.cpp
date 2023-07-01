#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

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

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		if (MessageBox(_hWnd, "게임을 종료하시겠습니까?", "종료확인", MB_OKCANCEL) == IDOK);
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_currentSceneIdx = -1;
		_isTitle = true;
		_currentScene->release();
		_currentScene = nullptr;
	}

	if (_currentScene == nullptr)
	{
		switch (_currentSceneIdx)
		{
		// 과제 클래스 초기화 =============================================================================================================
		case REPORT_INDEX::REPORT_CARD_MATCH:
			_currentScene = new Report_CardMatch;
			break;
		case REPORT_INDEX::REPORT_MOLE:
			_currentScene = new Report_Mole;
			break;
		case REPORT_INDEX::REPORT_CLAYSHOOTING:
			_currentScene = new Report_ClayShooting;
			break;
		case REPORT_INDEX::REPORT_AVOID:
			_currentScene = new Report_Avoid;
			break;
		case REPORT_INDEX::REPORT_BULLET_SHOOTING:
			_currentScene = new Report_BulletShooting;
			break;
		case REPORT_INDEX::REPORT_CROCODILE:
			_currentScene = new Report_Crocodile;
			break;
		case REPORT_INDEX::REPORT_VERTICAL_SHOOTING:
			_currentScene = new Report_Vertical_Shooting;
			break;
		case REPORT_INDEX::REPORT_HORIZONTAL_SHOOTING:
			_currentScene = new Report_Horizontal_Shooting;
			break;
		case REPORT_INDEX::REPORT_MOLE_IMAGE:
			_currentScene = new Report_Mole_Image;
			break;
		case REPORT_INDEX::REPORT_ANALOG_CLOCK:
			_currentScene = new Report_Analog_Clock;
			break;
		case REPORT_INDEX::REPORT_SHELL_FIRE:
			_currentScene = new Report_Shell_Fire;
			break;
		case REPORT_INDEX::REPORT_BULLET_GRAVITY:
			_currentScene = new Report_Bullet_Gravity;
			break;
		case REPORT_INDEX::REPORT_SLICE_GAME:
			_currentScene = new Report_Slice_Game;
			break;
		case REPORT_INDEX::REPORT_MINI_MAP:
			_currentScene = new Report_Mini_Map;
			break;
		case REPORT_INDEX::REPORT_WORM_GAME:
			_currentScene = new Report_Worm_Game;
			break;
		case REPORT_INDEX::REPORT_ATTACK_COMBO:
			_currentScene = new Report_Attack_Combo;
			break;
		case REPORT_INDEX::REPORT_MOTION_ANIMATION:
			_currentScene = new Report_Motion_Animation;
			break;
		case REPORT_INDEX::REPORT_WALL_CATCH:
			_currentScene = new Report_Wall_Catch;
			break;

		// 수업 예제 클래스 초기화 =============================================================================================================

		}

		if (_currentScene != nullptr)
		{
			_isTitle = false;
			_currentScene->init();
		}
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
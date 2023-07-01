#pragma once
#include "GameNode.h"

// ���� ���� =====================================================
#include "Example_Mole.h"
#include "Example_Bullet.h"
#include "Example_Math.h"
#include "Example_Image.h"
#include "Example_Cliping.h"
#include "Example_FrameImage.h"

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

#include "TitleScene.h"

class MainGame : public GameNode
{
private:
	// ���� ���� ===============================================================================================================
	//GameNode* _mg = new Example_Mole;															// �δ��� ���� ����
	//GameNode* _mg = new Example_Bullet;														// �Ѿ� �߻� ����
	//GameNode* _mg = new Example_Math;															// �ﰢ�Լ� ����
	//GameNode* _mg = new Example_Image;														// �̹��� ����
	//GameNode* _mg = new Example_Cliping;														// �̹��� Ŭ���� ����
	//GameNode* _mg = new Example_FrameImage;													// ������ �̹��� ����


	// ���� ====================================================================================================================
	//GameNode* _mg = new Report_CardMatch;														// ¦ ���߱�	
	//GameNode* _mg = new Report_Mole;															// �δ��� ����
	//GameNode* _mg = new Report_ClayShooting;													// Ŭ���� ���
	//GameNode* _mg = new Report_Avoid;															// �� ���ϱ�
	//GameNode* _mg = new Report_BulletShooting;												// �Ѿ� �߻�
	//GameNode* _mg = new Report_Crocodile;														// �Ǿ� �̻� ����
	//GameNode* _mg = new Report_Vertical_Shooting;												// �� ��ũ�� ���� ����
	//GameNode* _mg = new Report_Horizontal_Shooting;											// Ⱦ ��ũ�� ���� ����
	//GameNode* _mg = new Report_Mole_Image;													// �δ��� ���� (�̹���)
	//GameNode* _mg = new Report_Analog_Clock;													// �Ƴ��α� �ð�
	//GameNode* _mg = new Report_Shell_Fire;													// ��ź �߻� (�� �浹, �� ���� �浹)
	//GameNode* _mg = new Report_Bullet_Gravity;												// �Ѿ� �߷� ����
	//GameNode* _mg = new Report_Slice_Game;													// �̹��� �����̽� ����
	//GameNode* _mg = new Report_Mini_Map;														// �̴ϸ� �����
	//GameNode* _mg = new Report_Worm_Game;														// ������ ����
	//GameNode* _mg = new Report_Attack_Combo;													// ���� ���� �޺� (������ �̹���)
	//GameNode* _mg = new Report_Motion_Animation;												// ��� �ִϸ��̼� ���
	//GameNode* _mg = new Report_Wall_Catch;														// ĳ���� ����� (�̴ϸ�)

	
	GameNode* _titleScene;
	GameNode* _currentScene;

	bool _isTitle;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {}
	~MainGame() {}
};
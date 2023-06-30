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

class MainGame : public GameNode
{
private:
	// ���� ���� ===============================================================================================================
	//Example_Mole* _mg = new Example_Mole;															// �δ��� ���� ����
	//Example_Bullet* _mg = new Example_Bullet;														// �Ѿ� �߻� ����
	//Example_Math* _mg = new Example_Math;															// �ﰢ�Լ� ����
	//Example_Image* _mg = new Example_Image;														// �̹��� ����
	//Example_Cliping* _mg = new Example_Cliping;													// �̹��� Ŭ���� ����
	//Example_FrameImage* _mg = new Example_FrameImage;												// ������ �̹��� ����


	// ���� ====================================================================================================================
	//Report_CardMatch* _mg = new Report_CardMatch;													// ¦ ���߱�	
	Report_Mole* _mg = new Report_Mole;															// �δ��� ����
	//Report_ClayShooting* _mg = new Report_ClayShooting;											// Ŭ���� ���
	//Report_Avoid* _mg = new Report_Avoid;															// �� ���ϱ�
	//Report_BulletShooting* _mg = new Report_BulletShooting;										// �Ѿ� �߻�
	//Report_Crocodile* _mg = new Report_Crocodile;													// �Ǿ� �̻� ����
	//Report_Vertical_Shooting* _mg = new Report_Vertical_Shooting;									// �� ��ũ�� ���� ����
	//Report_Horizontal_Shooting* _mg = new Report_Horizontal_Shooting;								// Ⱦ ��ũ�� ���� ����

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {}
	~MainGame() {}
};
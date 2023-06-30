#pragma once
#include "GameNode.h"

// 수업 예제 =====================================================
#include "Example_Mole.h"
#include "Example_Bullet.h"
#include "Example_Math.h"
#include "Example_Image.h"
#include "Example_Cliping.h"
#include "Example_FrameImage.h"

// 과제 ==========================================================
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
	// 수업 예제 ===============================================================================================================
	//Example_Mole* _mg = new Example_Mole;															// 두더지 게임 예제
	//Example_Bullet* _mg = new Example_Bullet;														// 총알 발사 예제
	//Example_Math* _mg = new Example_Math;															// 삼각함수 예제
	//Example_Image* _mg = new Example_Image;														// 이미지 예제
	//Example_Cliping* _mg = new Example_Cliping;													// 이미지 클리핑 예제
	//Example_FrameImage* _mg = new Example_FrameImage;												// 프레임 이미지 예제


	// 과제 ====================================================================================================================
	//Report_CardMatch* _mg = new Report_CardMatch;													// 짝 맞추기	
	Report_Mole* _mg = new Report_Mole;															// 두더지 게임
	//Report_ClayShooting* _mg = new Report_ClayShooting;											// 클레이 사격
	//Report_Avoid* _mg = new Report_Avoid;															// 똥 피하기
	//Report_BulletShooting* _mg = new Report_BulletShooting;										// 총알 발사
	//Report_Crocodile* _mg = new Report_Crocodile;													// 악어 이빨 게임
	//Report_Vertical_Shooting* _mg = new Report_Vertical_Shooting;									// 종 스크롤 슈팅 게임
	//Report_Horizontal_Shooting* _mg = new Report_Horizontal_Shooting;								// 횡 스크롤 슈팅 게임

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {}
	~MainGame() {}
};
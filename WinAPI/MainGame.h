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
	// 수업 예제 ===============================================================================================================
	//GameNode* _mg = new Example_Mole;															// 두더지 게임 예제
	//GameNode* _mg = new Example_Bullet;														// 총알 발사 예제
	//GameNode* _mg = new Example_Math;															// 삼각함수 예제
	//GameNode* _mg = new Example_Image;														// 이미지 예제
	//GameNode* _mg = new Example_Cliping;														// 이미지 클리핑 예제
	//GameNode* _mg = new Example_FrameImage;													// 프레임 이미지 예제


	// 과제 ====================================================================================================================
	//GameNode* _mg = new Report_CardMatch;														// 짝 맞추기	
	//GameNode* _mg = new Report_Mole;															// 두더지 게임
	//GameNode* _mg = new Report_ClayShooting;													// 클레이 사격
	//GameNode* _mg = new Report_Avoid;															// 똥 피하기
	//GameNode* _mg = new Report_BulletShooting;												// 총알 발사
	//GameNode* _mg = new Report_Crocodile;														// 악어 이빨 게임
	//GameNode* _mg = new Report_Vertical_Shooting;												// 종 스크롤 슈팅 게임
	//GameNode* _mg = new Report_Horizontal_Shooting;											// 횡 스크롤 슈팅 게임
	//GameNode* _mg = new Report_Mole_Image;													// 두더지 게임 (이미지)
	//GameNode* _mg = new Report_Analog_Clock;													// 아날로그 시계
	//GameNode* _mg = new Report_Shell_Fire;													// 포탄 발사 (벽 충돌, 공 끼리 충돌)
	//GameNode* _mg = new Report_Bullet_Gravity;												// 총알 중력 구현
	//GameNode* _mg = new Report_Slice_Game;													// 이미지 슬라이스 게임
	//GameNode* _mg = new Report_Mini_Map;														// 미니맵 만들기
	//GameNode* _mg = new Report_Worm_Game;														// 지렁이 게임
	//GameNode* _mg = new Report_Attack_Combo;													// 제로 공격 콤보 (프레임 이미지)
	//GameNode* _mg = new Report_Motion_Animation;												// 모션 애니메이션 출력
	//GameNode* _mg = new Report_Wall_Catch;														// 캐릭터 벽잡기 (미니맵)

	
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
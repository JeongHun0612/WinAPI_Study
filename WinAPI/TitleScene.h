#pragma once
#include "GameNode.h"

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


enum REPORT_INDEX : int
{
	CARD_MATCH,

	REPORT_END
};

enum EXAMPLE_INDEX : int
{
	EXAMPLE_MOLE, EXAMPLE_BULLET, EXAMPLE_MATH,
	EXAMPLE_IMAGE, EXAMPLE_CLIPING, EXAMPLE_FRAME_IMAGE,

	EXAMPLE_END
};

class TitleScene : public GameNode
{
public:
	struct Button
	{
		RECT rc;
		char name[128];
	};
private:
	Button _reportBtn[REPORT_END];
	Button _exampleBtn[EXAMPLE_END];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};


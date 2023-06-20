#pragma once
#include "Report_MainGame.h"

#define PLAYER_SPEED	5

#define	KEY_W		0x57
#define	KEY_A		0x41
#define	KEY_S		0x53
#define	KEY_D		0x44

struct tagPlayer
{
	RECT rc;
	bool die;
};

struct tagBullet
{
	RECT rc;
	bool fire;
};

class Report_Horizontal_Shooting : public Report_MainGame
{
private:
	tagPlayer _Player1;
	tagPlayer _Player2;
	
	vector<RECT> _vPlayerBullet1;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_Horizontal_Shooting() {}
	~Report_Horizontal_Shooting() {}
};


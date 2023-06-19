#pragma once
#include "GameNode.h"


#define MAX_GAMETYPE	6

enum GAMETYPE
{
	CARDMATCHGAME,
	MOLEGAME,
	CLAYSHOOTING,
	AVOIDGAME,
	BULLETSHOOTING,
	CROCODILETEETH,
	GAMETYPENULL
};

class Report_MainGame : public GameNode
{
private:
	GameNode* _mg;
	GAMETYPE _EGameType;

	RECT _gameTypeBtn[MAX_GAMETYPE];
	TCHAR* _gameName[MAX_GAMETYPE];

	int _selectGame;
	bool _bIsInGame;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_MainGame() {}
	~Report_MainGame() {}
};
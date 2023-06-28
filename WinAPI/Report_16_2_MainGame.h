#pragma once
#include "GameNode.h"

#define MAX_ROW		25
#define MAX_COL		40

struct tagPlayer
{
	POINT pos;
	POINT mapPos;
};

struct tagCamera
{
	POINT pos;
	POINT mapPos;

	int width;
	int height;
};

struct tagMiniMap
{
	GImage* imgae;

	int x, y;
	int width;
	int height;
};

struct tagTile
{
	int x, y;
	int index;
};

class Report_16_2_MainGame : public GameNode
{
private:
	GImage* _bgImage;

	tagTile _tileMap[MAX_ROW][MAX_COL];
	tagPlayer _player;
	tagCamera _camera;
	tagMiniMap _miniMap;

	bool isShowTile;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);
};


#pragma once
#include "GameNode.h"

#define RND_IMG_CNT		5

struct Tile
{
	GImage* img;
	int x, y;
	RECT rc;
};

class Report_TileMap : public GameNode
{
private:
	GImage* _dragImg;

	vector<Tile> _vTiles;
	vector<Tile>::iterator _viTiles;

	string _strTileCnt;

	int _rndTileNum[RND_IMG_CNT];

	float _diffX;
	float _diffY;

	bool _isDrag;
	bool _isTextBox;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setRandomNum(int* rndNumArray, int count, int range);
	void setTile(vector<Tile>& vTiles, int tileCnt);

	Report_TileMap() {}
	~Report_TileMap() {}
};


#pragma once
#include "GameNode.h"

struct Tile
{
	int x, y;
	RECT rc;
};

class Report_TileMap : public GameNode
{
private:
	GImage* _image;

	vector<Tile> _vTiles;
	vector<Tile>::iterator _viTiles;

	int _rndTileNum[2];

	int _sizeX;
	int _sizeY;

	int _tileCount;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_TileMap() {}
	~Report_TileMap() {}
};


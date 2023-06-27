#pragma once
#include "GameNode.h"

#define BG_SIZE_X 1100
#define BG_SIZE_Y 700

struct tagPlayer
{
	int x, y;
	RECT rc;
	RECT miniRC;
};

struct tagCamera
{
	int x, y;
	int width;
	int height;
	RECT rc;
	RECT miniRC;
};

struct tagMiniMap
{
	GImage* imgae;

	int x, y;
	int width;
	int height;
};

class Report_16_2_MainGame : public GameNode
{
private:
	GImage* _bgImage;
	RECT _bgRC;

	tagPlayer _player;
	tagCamera _camera;
	tagMiniMap _miniMap;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);
};


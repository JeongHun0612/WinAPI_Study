#pragma once
#include "GameNode.h"

struct tagPlayer
{
	RECT rc;
	POINT centerPos;
};

struct tagCamera
{
	RECT rc;
	POINT pos;
	int width;
	int height;
};

class Report_16_2_MainGame : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _miniMapImage;

	RECT _miniMap;

	tagPlayer _player;
	tagCamera _camera;


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);
};


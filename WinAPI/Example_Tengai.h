#pragma once
#include "GameNode.h"
#include "Animation.h"

struct LoopImage
{
	GImage* img;
	RECT rc;
	float x, y;
	float offsetX;
	float offsetY;
};

class Example_Tengai : public GameNode
{
private:
	GImage* _attackImg;
	Animation* _attackAnim;

	GImage* _testImg;
	float _frameCnt;


	LoopImage _bgImg[3];

	int _offsetX;
	int _offsetY;

	float _bgSpeed1;
	float _bgSpeed2;
	float _bgSpeed3;
	float _bgSpeed4;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Example_Tengai() {}
	~Example_Tengai() {}
};


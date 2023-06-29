#pragma once
#include "GameNode.h"

class Example_Cliping : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plImage;
	RECT _rc;

	int _countA, _countB;
	int _alphaA, _alphaB;
	int _alphaNum;

	bool _isAlphaIncrease;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Example_Cliping() {}
	~Example_Cliping() {}
};


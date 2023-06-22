#pragma once
#include "GameNode.h"

class Example_Image : public GameNode
{
private:
	GImage* _bgImage;
	GImage* _plImage;
	RECT _rc;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Example_Image() {}
	~Example_Image() {}
};


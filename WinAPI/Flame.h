#pragma once
#include "GameNode.h"

// 모듈화 - 교체가 가능한 컴포넌트(부품)

#define FLAME_COUNT	4.0f


// 추상
class Flame : public GameNode
{
private:
	GImage* _image;
	RECT _rc;

	float* _x;
	float* _y;
	float _flameTick;

public:
	HRESULT init(const char* imageName, float* x, float* y);
	void release(void);
	void update(void);
	void render(void);

	Flame() {}
	~Flame() {}
};
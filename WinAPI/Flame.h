#pragma once
#include "GameNode.h"

// 모듈화 - 교체가 가능한 컴포넌트(부품)
// ㄴ 내일

class Flame : public GameNode
{
private:
	GImage* _image;
	RECT* _rc;

	int _index;
	int _count;

public:
	HRESULT init(RECT* rc);
	void release(void);
	void update(void);
	void render(void);

	Flame() {}
	~Flame() {}
};
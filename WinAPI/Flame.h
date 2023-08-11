#pragma once
#include "GameNode.h"

// ���ȭ - ��ü�� ������ ������Ʈ(��ǰ)

#define FLAME_COUNT	4.0f


// �߻�
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
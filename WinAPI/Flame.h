#pragma once
#include "GameNode.h"

// ���ȭ - ��ü�� ������ ������Ʈ(��ǰ)
// �� ����

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
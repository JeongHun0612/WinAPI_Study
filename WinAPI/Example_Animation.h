#pragma once
#include "GameNode.h"
#include "Animation.h"

class Example_Animation : public GameNode
{
private:
	GImage* _image;
	Animation* _animationA;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Example_Animation() {}
	~Example_Animation() {}
};


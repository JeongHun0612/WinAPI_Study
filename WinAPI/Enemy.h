#pragma once
#include "GameNode.h"

// Enemy (�θ�) : ���� �� Ŭ������ ������� �Ϲ� ����, ���� ���� ���� �� �ִ�.
class Enemy : public GameNode
{
protected:
	GImage* _image;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;

	float _x, _y;
	float _speed;
	float _angle;
	float _worldTimeCount;
	float _rndTimeCount;

public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position, float speed);

	void release(void);
	void update(void);
	void render(void);

	void move(void);
	void draw(void);
	void animation(void);

	Enemy(void);
	~Enemy(void) {}
};
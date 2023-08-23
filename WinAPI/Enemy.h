#pragma once
#include "GameNode.h"
#include "Bullets.h"

// Enemy (�θ�) : ���� �� Ŭ������ ������� �Ϲ� ����, ���� ���� ���� �� �ִ�.
class Enemy : public GameNode
{
private:
	HBRUSH _hBrush;
	HBRUSH _hOldBrush;

protected:
	GImage* _image;
	Missile* _missile;

	RECT _rc;

	int _maxHP;
	int _curHP;
	int _currentFrameX;
	int _currentFrameY;

	float _x, _y;
	float _speed;
	float _angle;

	float _worldTimeCount;
	float _rndTimeCount;

	float _rndFirecount;
	float _bulletFireCount;

public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position, float speed, float angle = 0.0f);

	void release(void);
	void update(void);
	void render(void);

	virtual void move(void);
	void draw(void);
	void animation(void);

	bool bulletCountFire(void);

	float getX(void) { return _x; }
	float getY(void) { return _y; }

	RECT getRC(void) { return _rc; }

	int getCurHP() { return _curHP; }
	void setCurHP(int curHP) { _curHP = curHP; }

	Enemy(void);
	~Enemy(void) {}
};
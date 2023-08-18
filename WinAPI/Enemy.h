#pragma once
#include "GameNode.h"

// Enemy (부모) : 적은 이 클래스를 기반으로 일반 몬스터, 보스 등을 만들 수 있다.
class Enemy : public GameNode
{
private:
	HBRUSH _hBrush;
	HBRUSH _hOldBrush;

protected:
	GImage* _image;
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

public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position, float speed, float angle = 0.0f);

	void release(void);
	void update(void);
	void render(void);

	virtual void move(void);
	void draw(void);
	void animation(void);

	RECT getRC(void) { return _rc; }

	int getCurHP() { return _curHP; }
	void setCurHP(int curHP) { _curHP = curHP; }

	Enemy(void);
	~Enemy(void) {}
};
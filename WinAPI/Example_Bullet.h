#pragma once
#include "GameNode.h"

#define BULLET_MAX		10
#define PLAYER_SPEED	5

// 80개의 적개체를 STL을 사용해야하는지?
// 적개체가 가지고있는 속성을 생각 -> 단일 이미지면 X, 애니메이션이 많이 들어가면 사용을 고려
#define	ENEMY_MAX		80

struct tagBullet
{
	RECT rc;
	bool fire;
};

struct tagEnemy
{
	RECT rc;
	int speed;
	bool die;
};

class Example_Bullet : public GameNode
{
private:
	HBRUSH brush;

	tagBullet _bullet[BULLET_MAX];
	tagEnemy _enemy[ENEMY_MAX];

	RECT _playerRC;
	RECT _hpBar;
	int _hp;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void fireBullet(void);

	Example_Bullet() {}
	~Example_Bullet() {}
};


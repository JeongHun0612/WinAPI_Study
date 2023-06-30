#pragma once
#include "GameNode.h"

#define BULLET_MAX		10
#define PLAYER_SPEED	5

// 80���� ����ü�� STL�� ����ؾ��ϴ���?
// ����ü�� �������ִ� �Ӽ��� ���� -> ���� �̹����� X, �ִϸ��̼��� ���� ���� ����� ���
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


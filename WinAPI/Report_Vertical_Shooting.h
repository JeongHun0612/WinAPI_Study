#pragma once
#include "Report_MainGame.h"

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

class Report_Vertical_Shooting : public Report_MainGame
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
	void render(HDC hdc);


	void fireBullet(void);

	Report_Vertical_Shooting() {}
	~Report_Vertical_Shooting() {}
};


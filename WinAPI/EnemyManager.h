#pragma once
#include "GameNode.h"
#include "Enemy.h"
#include "Bullets.h"
#include "Animation.h"

enum class MOVE_PATTERN
{
	CIRCLA,
	CURVE,
	CRUSH
};

class Rocket;

// cpp / h 차이 (참조 / 복사 / 디컴파일)
// cpp는 참조를 하고 넘어간다.
// h는 복사를 하고 넘어간다.
class EnemyManager : public GameNode
{
private:
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

	vEnemy _vMinion;
	viEnemy _viMinion;

	Bullet* _bullet;
	Rocket* _rocket;

	GImage* _dieEffectImg;
	Animation* _dieAnim;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(const char* imageName, int count, float speed, MOVE_PATTERN type);
	void removeMinion(int arrNum);

	void minionBulletFire(void);
	void collision(void);

	vector<Enemy*> getMinions(void) { return _vMinion; }
	Bullet* getBullet(void) { return _bullet; }
	void setRocketMemoryAddress(Rocket* rocket) { _rocket = rocket; }
	

	EnemyManager() {}
	~EnemyManager() {}
};
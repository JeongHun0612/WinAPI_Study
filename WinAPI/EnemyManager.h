#pragma once
#include "GameNode.h"
#include "Enemy.h"
#include "Rocket.h"

enum class MOVE_PATTERN
{
	CIRCLA,
	CURVE,
	CRUSH
};

// cpp / h 차이 (참조 / 복사 / 디컴파일)
// cpp는 참조를 하고 넘어간다.
// h는 복사를 하고 넘어간다.
class EnemyManager : public GameNode
{
private:
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	Rocket* _rocket;

public:
	HRESULT init(void);
	HRESULT init(Rocket* rocket);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(const char* imageName, int count, float speed, MOVE_PATTERN type);

	EnemyManager() {}
	~EnemyManager() {}
};
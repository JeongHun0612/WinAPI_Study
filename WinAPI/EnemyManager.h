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

// cpp / h ���� (���� / ���� / ��������)
// cpp�� ������ �ϰ� �Ѿ��.
// h�� ���縦 �ϰ� �Ѿ��.
class EnemyManager : public GameNode
{
private:
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

private:
	GImage* effectImg;

	vEnemy _vMinion;
	viEnemy _viMinion;

	vector<RECT> _effectPos;

	Rocket* _rocket;

public:
	HRESULT init(void);
	HRESULT init(Rocket* rocket);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(const char* imageName, int count, float speed, MOVE_PATTERN type);
	void removeMinion(int arrNum);
	void dieAnimation(void);

	vector<Enemy*> getMinions(void) { return _vMinion; }

	EnemyManager() {}
	~EnemyManager() {}
};
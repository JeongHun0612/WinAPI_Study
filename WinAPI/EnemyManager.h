#pragma once
#include "GameNode.h"
#include "Enemy.h"

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
	vEnemy _vMinion;
	viEnemy _viMinion;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(const char* imageName, int count, float speed, MOVE_PATTERN type);

	EnemyManager() {}
	~EnemyManager() {}
};
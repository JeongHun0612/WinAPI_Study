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
	struct Animation
	{
		GImage* img;
		float x, y;
		float timeCount;
	};

	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	vector<Animation> _vAnim;
	vector<Animation>::iterator _viAnim;

public:
	HRESULT init(void);
	HRESULT init(Rocket* rocket);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(const char* imageName, int count, float speed, MOVE_PATTERN type);
	void removeMinion(int arrNum);

	vector<Enemy*> getMinions(void) { return _vMinion; }

	EnemyManager() {}
	~EnemyManager() {}
};
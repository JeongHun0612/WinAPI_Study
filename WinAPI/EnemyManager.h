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
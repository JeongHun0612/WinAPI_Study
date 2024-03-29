#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"
#include "ProgressBar.h"

#define ROCKET_SPEED 3.0f;

#pragma region 스마트 포인터
/*
▶ 스마트 포인터

- auto_ptr을 대체하기 위해 나온 문법 (C++ 11에서 삭제)
ㄴ 메모리 릭을 방지하고 안정성 확보를 위해 사용한다. -> 스마트 포인터

- 포인터처럼 동작하는 클래스 템플릿
ㄴ 사용이 끝난 메모리를 자동으로 해제한다.

- 사용하기전에는 <memory> 헤더가 필요하고 기본적으로 원시 포인터가 실제 메모리를 가르키게 하고 
  기본 포인터를 스마트 포인터에 대입하는 형식으로 많이 사용한다.

- new (동적 할당)
ㄴ 항상 스마트 포인터를 사용할때 짝꿍처럼 등장하니 왠만한 메모리는 묶어서 속도를 챙겨야 한다.

▷ 종류

1. unique_ptr
ㄴ 유일 객체 (객체에 대한 소유권을 유일하게)


2. shared_ptr
ㄴ 일반적으로 여러 객체에서 하나의 객체를 사용하고 싶을 때 적용한다.
ㄴ 참조 횟수를 기반으로 동작하며 이 포인터는 객체간 소유권을 분할할때 사용하면 좋다.


3. weak_ptr
ㄴ 단독 실행 불가
ㄴ shared_ptr이 소유한 객체 대한 접근을 허용할때 필요하다.
ㄴ 순환 참조를 제거할 때 사용된다.
*/
#pragma endregion

enum class WEAPON_TYPE
{
	MISSILE,
	BEAM
};

class EnemyManager;

// enable_shared_from_this : 객체의 생성 및 소멸에 의한 참조 문제를 해결한다.
// ㄴ 각각의 객체에게 소유권을 부여한다.
class Rocket : public GameNode /*, public std::enable_shared_from_this<Rocket> */
{
private:
	GImage* _image;
	Flame* _flame;

	// 총알
	Missile* _missile;
	Beam* _beam;
	WEAPON_TYPE _weaponType;

	ProgressBar* _hpBar;
	EnemyManager* _em;


	RECT _rc;
	float _x, _y;
	float _currentHP;
	float _maxHP;

	bool _isBeamLaunch;
	
	//GImage* objectData;
	//vector<std::shared_ptr<Rocket>> spRocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void collision(void);
	void setEnemyManagerMemoryAddress(EnemyManager* em) { _em = em; }

	void removeMissile(int arrNum);

	Missile* getMisslie(void) { return _missile; }
	Beam* getBeam(void) { return _beam; }

	POINT getPosition(void) { return PointMake((int)_x, (int)_y); }
	RECT getRect(void) { return _rc; }

	inline void hitDamage(float damage)
	{
		if (_currentHP <= 0)
		{
			_currentHP = 0;
			return;
		}
		else
		{
			_currentHP -= damage;
		}
	}

	Rocket() {}
	~Rocket() {}

	//std::shared_ptr<Rocket> get_shared_ptr()
	//{
	//	return shared_from_this();
	//}

	//Rocket() { objectData = new GImage[10]; }
	//~Rocket() { delete[] objectData; }
};


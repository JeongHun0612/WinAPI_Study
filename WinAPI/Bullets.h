#pragma once
#include "GameNode.h"

#define FRAME_COUNT	10.0f

// 기능 -> 묶었다.
struct tagBullet
{
	GImage* img;
	GImage* effectImg;

	RECT rc;

	int radius;
	int count;

	float x, y;
	float fireX, fireY;
	float angle;
	float speed;

	bool fire;
	bool explosion;
};

enum class BULLET_TYPE
{
	NORMAL_BULLET,
	SHOT,
	MINI_ROCKET,
	BEAM,

	BULLET_END
};

// 객체로 정의한다.
// ㄴ 배열처럼 미리 장전을 해두고 발사

class Bullets : public GameNode
{
protected:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _vBulletIter;

	float _range;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	Bullets() {}
	~Bullets() {}
};

// 발사가 될때마다 만들고 삭제
class Missile : public GameNode
{
protected:
	typedef vector<tagBullet>::iterator iterBullet;

	vector<tagBullet> _vBullet;
	iterBullet _vBulletIter;

	BULLET_TYPE _bulletType;

	string _name;

	int _bulletMax;
	

	float _range;

public:
	virtual HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	virtual void fire(float x, float y);
	virtual void move(void);
	virtual void draw(void);

	bool collisionCheck(RECT rc);
	void removeBullet(int arrNum);

	vector<tagBullet> getBullet(void) { return _vBullet; }

	string getName(void) { return _name; }
	BULLET_TYPE getBulletType(void) { return _bulletType; }

	Missile() {}
	~Missile() {}
};
#pragma once
#include "GameNode.h"

#define FRAME_COUNT	10.0f

// ��� -> ������.
struct tagBullet
{
	GImage* img;
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

// ���� �Ѿ� (�򶧸��� ����� ����)
class Bullet : public GameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;

	int _bulletMax;
	float _range;

public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle, float speed);
	void move(void);
	void draw(void);

	void removeBullet(int arrNum);

	vector<tagBullet> getBullet() { return _vBullet; }

	Bullet(void) {}
	virtual ~Bullet() {}
};

// �߻簡 �ɶ����� ����� ����
class Missile : public GameNode
{
private:
	typedef vector<tagBullet>::iterator iterBullet;

	vector<tagBullet> _vBullet;
	iterBullet _viBullet;

	int _bulletMax;
	float _range;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void move(void);
	void draw(void);

	void removeBullet(int arrNum);

	vector<tagBullet> getBullet() { return _vBullet; }

	Missile() {}
	~Missile() {}
};

class Beam : public GameNode
{
private:
	typedef vector<tagBullet>::iterator iterBullet;

	vector<tagBullet> _vBullet;
	iterBullet _viBullet;

	int _bulletMax;

	float _range;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void move(void);
	void draw(void);

	vector<tagBullet> getBullet() { return _vBullet; }

	Beam() {}
	~Beam() {}
};
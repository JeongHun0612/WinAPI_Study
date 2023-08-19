#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"

#define ROCKET_SPEED 3.0f;

#pragma region ����Ʈ ������
/*
�� ����Ʈ ������

- auto_ptr�� ��ü�ϱ� ���� ���� ���� (C++ 11���� ����)
�� �޸� ���� �����ϰ� ������ Ȯ���� ���� ����Ѵ�. -> ����Ʈ ������

- ������ó�� �����ϴ� Ŭ���� ���ø�
�� ����� ���� �޸𸮸� �ڵ����� �����Ѵ�.

- ����ϱ������� <memory> ����� �ʿ��ϰ� �⺻������ ���� �����Ͱ� ���� �޸𸮸� ����Ű�� �ϰ� 
  �⺻ �����͸� ����Ʈ �����Ϳ� �����ϴ� �������� ���� ����Ѵ�.

- new (���� �Ҵ�)
�� �׻� ����Ʈ �����͸� ����Ҷ� ¦��ó�� �����ϴ� �ظ��� �޸𸮴� ��� �ӵ��� ì�ܾ� �Ѵ�.

�� ����

1. unique_ptr
�� ���� ��ü (��ü�� ���� �������� �����ϰ�)


2. shared_ptr
�� �Ϲ������� ���� ��ü���� �ϳ��� ��ü�� ����ϰ� ���� �� �����Ѵ�.
�� ���� Ƚ���� ������� �����ϸ� �� �����ʹ� ��ü�� �������� �����Ҷ� ����ϸ� ����.


3. weak_ptr
�� �ܵ� ���� �Ұ�
�� shared_ptr�� ������ ��ü ���� ������ ����Ҷ� �ʿ��ϴ�.
�� ��ȯ ������ ������ �� ���ȴ�.
*/
#pragma endregion

enum class WEAPON_TYPE
{
	MISSILE,
	BEAM
};


// enable_shared_from_this : ��ü�� ���� �� �Ҹ꿡 ���� ���� ������ �ذ��Ѵ�.
// �� ������ ��ü���� �������� �ο��Ѵ�.
class Rocket : public GameNode /*, public std::enable_shared_from_this<Rocket> */
{
private:
	GImage* _image;
	Flame* _flame;

	// �Ѿ�
	Missile* _missile;
	Beam* _beam;

	WEAPON_TYPE _weaponType;

	RECT _rc;
	float _x, _y;

	bool _isBeamLaunch;
	
	//GImage* objectData;
	//vector<std::shared_ptr<Rocket>> spRocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void removeMissile(int arrNum);

	Missile* getMisslie() { return _missile; }
	Beam* getBeam() { return _beam; }

	RECT getRect() { return _rc; }

	Rocket() {}
	~Rocket() {}

	//std::shared_ptr<Rocket> get_shared_ptr()
	//{
	//	return shared_from_this();
	//}

	//Rocket() { objectData = new GImage[10]; }
	//~Rocket() { delete[] objectData; }
};


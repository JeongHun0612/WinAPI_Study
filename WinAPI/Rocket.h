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

// enable_shared_from_this : ��ü�� ���� �� �Ҹ꿡 ���� ���� ������ �ذ��Ѵ�.
// �� ������ ��ü���� �������� �ο��Ѵ�.
class Rocket : public GameNode, public std::enable_shared_from_this<Rocket>
{
private:
	GImage* _image;
	Flame* _flame;

	// �̻��� 1
	//Missile _missile;

	// �̻��� 2
	MissileM1 _missile;

	RECT _rc;
	float _x, _y;
	
	//GImage* objectData;
	//vector<std::shared_ptr<Rocket>> spRocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	std::shared_ptr<Rocket> get_shared_ptr()
	{
		return shared_from_this();
	}

	Rocket() {}
	~Rocket() {}

	//Rocket() { objectData = new GImage[10]; }
	//~Rocket() { delete[] objectData; }
};


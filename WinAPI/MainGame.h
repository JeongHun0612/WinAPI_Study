#pragma once
#include "GameNode.h"
#include "Example_Mole.h" 

// 0. ����� ���� Ŭ����
// 1. �ֻ��� ������ Ŭ����
// 2. �븮�� (���� �°� ����ϴ� Ŭ����)

// ��ü���� ���α׷��� -> ������ ����� ȿ������ ����а� ���� ü��

/*
1. Ŭ���� ����
 �� ��� �ʿ俩�� / Ŭ���� ���� / STL �ʿ俩��

2. ü�� (���� / Ŭ���� / ����ü) -> Ȯ�强�� ��������

3. ��üȭ
 �� PCH / �Լ� -> ���� ����
*/

//enum class CURRENT_RECT : UINT8  ( ���� Ŭ������ ���������� ��ȣ���� �����ϱ� ���� enum class �� ���)
enum CURRENT_RECT
{
	CURRENTRECT_A, CURRENTRECT_B,
	CURRENTRECT_C, CURRENTRECT_D,
	CURRENTRECT_E, CURRENTRECT_F,
	CURRENTRECT_G, CURRENTRECT_H,
	CURRENTRECT_NULL
};

class MainGame : public GameNode
{
private:
	Example_Mole* _mole;

	CURRENT_RECT _currentRect;

	RECT _rc[8];
	int _index;				// �δ��� �ε��� (8��)
	int _count;				// Ÿ�̸ӿ� ī��Ʈ
	int _time;				// �����ð� ����
	int _score;				// ����

	bool _bIsSelected;		// ������ �ƴ���
	bool _bIsOnceCheck;		// �ѹ��� ���ȴ���

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainGame() {}
	~MainGame() {}
};
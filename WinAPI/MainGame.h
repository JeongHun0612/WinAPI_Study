#pragma once
#include "GameNode.h"
#include "Example_Mole.h" 

// 0. 상속을 받은 클래스
// 1. 최상위 관리자 클래스
// 2. 대리자 (오류 맞고 사망하는 클래스)

// 객체지향 프로그래밍 -> 설계의 기반한 효율적인 방법론과 관리 체계

/*
1. 클래스 분할
 ㄴ 상속 필요여부 / 클래스 갯수 / STL 필요여부

2. 체계 (열거 / 클래스 / 구조체) -> 확장성과 유지보수

3. 구체화
 ㄴ PCH / 함수 -> 로직 구현
*/

//enum class CURRENT_RECT : UINT8  ( 하위 클래스로 나누었으면 모호함을 제거하기 위해 enum class 를 사용)
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
	int _index;				// 두더지 인덱스 (8개)
	int _count;				// 타이머용 카운트
	int _time;				// 랜덤시간 변수
	int _score;				// 점수

	bool _bIsSelected;		// 선택이 됐는지
	bool _bIsOnceCheck;		// 한번만 눌렸는지

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	MainGame() {}
	~MainGame() {}
};
#include "Stdafx.h"
#include "Example_Math.h"

#pragma region 삼각함수
/*
▶ 삼각함수란?

- 수학에서의 삼각함수는 직각 삼각형의 각을 변들의 길이 비로 나타내는 함수이다. -> 직각 삼각형 일때만 성립이 된다.

- 게임 개발을 하는 관점에서는 주로 각도를 이용할때 삼각함수가 필요하다.
	ㄴ EX : 발사체의 각도 / 캐릭터의 대각선 이동 / 스킬의 범위 설정 등(부채꼴)
	ㄴ 더 나아가면 파동 규칙을 통해 가능한 선에서 일정한 루틴을 만들거나 힘 / 물리 연산도 가능하다.

▷ 삼각함수하면 기억할 3가지

- 빗변 : l		->		대변(높이) : h		->		밑변 : b

1. 사인 (sin)
ㄴ 사인은 빗변(제일 긴)과 높이(대변)의 비율을 구해주는 함수
ㄴ sin Θ = 대변 / 빗변 -> h / l


2. 코사인 (cos)
ㄴ 빗변과 밑변의 비율을 계산해 주는 함수
ㄴ cos Θ = 밑변 / 빗변 = b / l


3. 탄젠트 (tan)
ㄴ 직각 삼각형에서 어떠한 각도를 넣었을때 밑변과 대변의 비율을 구해준다.
ㄴ tan(45도) = 1
ㄴ tan Θ = 대변 / 밑변 = h / b


▶ 프로그래밍에서의 삼각함수

- API에서는 윈도우 좌표계를 사용한다.

- 윈도우 좌표계는 데카르트 좌표계와는 달리 y축이 아래로 내려갈수록 증가하기 때문에
  y좌표를 구할때 별다른 처리를 하지 않았다면 sin 앞에 '-' 기호를 붙여야 한다.

ㆍ 기억해야 할 개념.

- PI
ㄴ 원주(원의 둘레)와 지름(원의 중심을 관통해서 한쪽 끝에서 반대쪽 끝까지 가로지르는 선)의 길이의 비로 나타낸다.


- 호도법
ㄴ 각도를 나타내는 표현 방법중에 하나 -> 호의 길이로 각도를 표기하는 표기법
ㄴ PI를 사용해 180도 각도를 표시하는 것 -> 이를 호도법이라고 한다.
ㄴ 호도법을 사용해야 하는 이유는 컴퓨터는 각도를 인식할 때 도를 사용할 수 없다.
ㄴ 반지름의 길이와 같은 호에 대한 중심각을 1호도 (라디안) 라고 한다.


- 라디안
ㄴ 호도법을 사용할 때 사용하는 단위
ㄴ 반지름과 호의 길이가 같은 값을 1 라디안이라고 정의한다.
ㄴ 1 라디안 = 57.3도


- 도
ㄴ 일반적으로 사용하는 각의 단위 (각도)
ㄴ 도수법 / 각도 표기라고 불린다.
ㄴ 한바퀴를 360도로 정의한다.


- 60분법
ㄴ 원의 둘레를 360등분하여 각의 크기를 나타내는 방법
ㄴ PI (원주율) : 3.14
ㄴ 원의 둘레 : 2 * PI * 반지름		(2πr)
ㄴ 원의 넓이 : 반지름 * 반지름 * PI	(πr²)


★ PI의 라디안 값은 -> 180도

- 그렇기 때문에 공식이 성립할 수 있다.

- Degree
	ㄴ	  180도		=		PI 라디안
	ㄴ		1도		=		PI / 180 라디안
	ㄴ		x도		=		x * PI / 180 라디안

- Radian
	ㄴ PI 라디안		=		180도
	ㄴ  1 라디안		=		180 / PI 도
	ㄴ	x 라디안		=		x * 180 / PI 도

※ 부채꼴 모양에서는 반지름, 호, 중심각 중에 2가지만 알 수 있으면 다른 1가지도 구할 수  있다.


▷ 기본 공식

1. 두점 사이의 거리
ㄴ 두점을 안다. (Start / End) -> 서로의 거리를 안다. -> 목표 지점에서 시작점을 뺀다.
	ㄴ End - Start = 두 점 사이의 거리 -> 뺀 만큼의 차

ㄴ 위에 공식으로 각 점 (X, Y) 사이의 델타량을 구한다.
	ㄴ DeltaX, DeltaY

2. 대각선 (빗변)의 거리
ㄴ Dinstance (빗변) = sqrt(DeltaX * DeltaX + DeltaY * DeltaY)
	ㄴ ◈ sqrt() : x의 제곱근을 구하기 위한 함수

3. 각을 구한다. (이것도 기본적으로 공식을 활용하자)

- float angle = acos (DeltaX / Dinstance);
	ㄴ 삼각 함수 : 각도를 넣어서 각도 계산
	ㄴ 역삼각 함수 : 삼각 함수의 결과 값을 통해 각도를 계산한다.
		ㄴ 일반적으로 삼각함수 앞에 arc / a로 표기

- 각도에 대한 변이량을 구한다.
	ㄴ float DeltaX = cos (라디안) * Distance(이동량);
	ㄴ float DeltaY = -sin (라디안) * Distance(이동량);

4. x축 좌표 구하기
ㄴ x = cos(각도 * PI / 180) * 속도;

5. y축 좌표 구하기
ㄴ y = -sin(각도 * PI / 180) * 속도;
*/

#pragma endregion

HRESULT Example_Math::init(void)
{
	_radian = 3.141592653f;
	_degree = 180;

	for (int i = 0; i <= 5; ++i)
	{
		_star[i].x = cosf((i * 72 - 90) * PI / 180.0f) * 200 + WINSIZE_X / 2;
		_star[i].y = sinf((i * 72 - 90) * PI / 180.0f) * 200 + WINSIZE_Y / 2;

		/*
		오망성을 그리기 위한 포인트 5개
		ㄴ 72 / <- 360 / 5

		-90 -> 초기 각도

		디그리를 -> 라디안으로

		200 -> 중심에서의 거리

		WINSIZE_X / Y -> 중점
		*/
	}

	return S_OK;
}

void Example_Math::release(void)
{
}

void Example_Math::update(void)
{
	GetLocalTime(&_st);
	_st.wSecond;
}

void Example_Math::render(void)
{
	char strRadian[128];
	char strDegree[128];
	char strSecond[128];

	sprintf_s(strSecond, "%d 초", _st.wSecond);
	TextOut(getMemDC(), WINSIZE_X / 2, 100, strSecond, strlen(strSecond));

	// radian에서 degree로
	// ㄴ 1 Radian = 180 / PI Degree
	sprintf_s(strRadian, "%.2f 라디안 값은 %.2f 디그리 값과 같다", _radian, _radian * (180.0f / M_PI));
	TextOut(getMemDC(), WINSIZE_X / 2 - 100, WINSIZE_Y / 2 - 100, strRadian, strlen(strRadian));

	// degree에서 radian으로
	// ㄴ 1 Degree = PI / 180 Radian
	sprintf_s(strDegree, "%.2f 디그리 값은 %.2f 라디안 값과 같다.", _degree, _degree * (PI / 180.0f));
	TextOut(getMemDC(), WINSIZE_X / 2 - 100, WINSIZE_Y / 2, strDegree, strlen(strDegree));

	// Create : 펜 스타일, 길이, 색상
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	HPEN oldPen;
	oldPen = (HPEN)SelectObject(getMemDC(), pen);

	LineMake(getMemDC(), WINSIZE_X / 2 - 100, WINSIZE_Y / 2 + 100, WINSIZE_X / 2 + 200, WINSIZE_Y / 2 + 100);

	for (int i = 0; i < 5; i++)
	{
		EllipseMakeCenter(getMemDC(), _star[i].x, _star[i].y, 10, 10);
	}

	SelectObject(getMemDC(), oldPen);
	DeleteObject(pen);
}
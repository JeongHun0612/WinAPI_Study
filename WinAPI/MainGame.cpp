#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	_currentRect = CURRENTRECT_NULL;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rc[i * 4 + j] = RectMakeCenter(100 + j * 200, 200 + i * 200, 100, 100);
		}
	}

	_index = 0;
	_count = 0;
	_score = 0;
	_time = RND->getFromIntTo(30, 60);

	_bIsSelected = false;
	_bIsOnceCheck = false;

	_mole = new Example_Mole;
	_mole->init();

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();

	_mole->release();
	SAFE_DELETE(_mole);
}

void MainGame::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		// PtInRect() : 렉트 안에 POINT(x, y)가 있는지 검사하여 포인트가 사각형 안에 있으면 true값을 반환하는 API 함수
		if (PtInRect(&_rc[_index], _ptMouse) && !_bIsOnceCheck)
		{
			_score += 100;
			_bIsOnceCheck = true;
		}
	}

	if (!_bIsSelected)
	{
		_count++;

		if (_count % _time == 0)
		{
			_count = 0;
			_index = RND->getInt(8);
			_currentRect = (CURRENT_RECT)_index;
			_bIsSelected = true;
		}
	}
	else
	{
		_count++;

		if (_count % _time == 0)
		{
			_bIsOnceCheck = false;
			_bIsSelected = false;
			_currentRect = CURRENTRECT_NULL;
			_time = RND->getFromIntTo(30, 60);
			_index = 100;
		}
	}

	_mole->update();
}

void MainGame::render(HDC hdc)
{
	for (int i = 0; i < 8; i++)
	{
		Rectangle(hdc, _rc[i].left, _rc[i].top, _rc[i].right, _rc[i].bottom);
	}

	char strScore[128];

	wsprintf(strScore, "Score : %d", _score);
	TextOut(hdc, 50, 100, strScore, strlen(strScore));

	if (_bIsSelected)
	{
		int r = RND->getInt(256);
		int g = RND->getInt(256);
		int b = RND->getInt(256);

		HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
		FillRect(hdc, &_rc[_index], brush);
		DeleteObject(brush); // 데이터 누수 방지
	}

	_mole->render(hdc);
}

/*
- 주말 과제 제출

ㄴ 언리얼 1기_얼굴 그리기_송정훈
ㄴ 내일 오전 9시
ㄴ 오늘 과제 포함해서

과제 1. 똥 피하기

- 시작 버튼을 누르면서 게임 시작

- 게임이 시작되고 플레이어가 죽을때까지 버틴 시간을 화면을 출력한다.

- 필수 : 재시작 + 다시하기

- 플레이어는 사람 모양으로 좌우 모양이 다르게 구현

과제 2. 총알 발사

- 하단에서 좌우로 움직일 수 있는 플레이어가 존재

- 스페이스 바를 누르면 플레이어가 총알을 발사한다.

과제 3. 악어이빨 게임

- 악어이빨은 최소 8개 이상

- 악어이빨에 물렸는지 아닌지에 대해서 확인이 가능해야 한다.

- 필수 : 악어이빨이 닫히는 애니메이션 구현

*/

#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init();

	// 플레이어 초기화
	_playerRC = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2 + 200, 40, 40);
	_hpBar = RectMake(45, 10, 120, 20);
	_hp = 3;

	// 적개체 초기화
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		_enemy[i].rc = RectMakeCenter(
			RND->getFromIntTo(20, WINSIZE_X - 20),
			-(RND->getFromIntTo(80, WINSIZE_Y * 2)),
			20, 20);
		_enemy[i].speed = RND->getFromIntTo(2, 8);
		_enemy[i].die = false;
	}

	return S_OK;
}

void MainGame::release(void)
{
	GameNode::release();
}

void MainGame::update(void)
{
	GameNode::update();

	// 플레이어 조작
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && WINSIZE_X > _playerRC.right)
	{
		_playerRC.left += PLAYER_SPEED;
		_playerRC.right += PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && 0 < _playerRC.left)
	{
		_playerRC.left -= PLAYER_SPEED;
		_playerRC.right -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && 0 < _playerRC.top)
	{
		_playerRC.top -= PLAYER_SPEED;
		_playerRC.bottom -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && WINSIZE_Y > _playerRC.bottom)
	{
		_playerRC.top += PLAYER_SPEED;
		_playerRC.bottom += PLAYER_SPEED;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		fireBullet();
	}

	// 총알 이동
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!_bullet[i].fire) continue;
		_bullet[i].rc.top -= 14;
		_bullet[i].rc.bottom -= 14;

		if (_bullet[i].rc.bottom < 0) _bullet[i].fire = false;

		for (int j = 0; j < ENEMY_MAX; j++)
		{
			// 총알과 적의 충돌 처리
			RECT rt;
			if (IntersectRect(&rt, &_bullet[i].rc, &_enemy[j].rc))
			{
				_bullet[i].fire = false;
				_enemy[j].die = true;
				_enemy[j].rc = { 0, 0, 0, 0 };
				break;
			}
		}
	}

	// 적개체 이동
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (_enemy[i].die) continue;

		_enemy[i].rc.top += _enemy[i].speed;
		_enemy[i].rc.bottom += _enemy[i].speed;

		// 적 개체 위치 재할당
		if (_enemy[i].rc.top > WINSIZE_Y)
		{
			_enemy[i].rc = RectMakeCenter(
				RND->getFromIntTo(20, WINSIZE_X - 20),
				-(RND->getFromIntTo(80, WINSIZE_Y * 2)),
				20, 20);
		}

		// 플레이어와 적의 충돌처리
		RECT rt;
		if (IntersectRect(&rt, &_enemy[i].rc, &_playerRC))
		{
			_hp--;
			_hpBar.right -= 40;

			_enemy[i].die = true;
			_enemy[i].rc = { 0, 0, 0, 0 };
			break;
		}
	}
}

void MainGame::render(HDC hdc)
{
	// HP바 그리기
	TextOut(hdc, 10, 10, "HP : ", strlen("HP : "));

	switch (_hp)
	{
	case 1:
		brush = CreateSolidBrush(RGB(255, 0, 0));
		break;
	case 2:
		brush = CreateSolidBrush(RGB(255, 255, 0));
		break;
	case 3:
		brush = CreateSolidBrush(RGB(0, 255, 0));
		break;
	}

	FillRect(hdc, &_hpBar, brush);
	DeleteObject(brush);

	// 플레이어 그리기
	DrawRectMake(hdc, _playerRC);

	// 적개체 그리기
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (_enemy[i].die) continue;
		Rectangle(hdc, _enemy[i].rc.left, _enemy[i].rc.top, _enemy[i].rc.right, _enemy[i].rc.bottom);
	}

	// 총알 그리기
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!_bullet[i].fire) continue;
		Ellipse(hdc, _bullet[i].rc.left, _bullet[i].rc.top, _bullet[i].rc.right, _bullet[i].rc.bottom);
	}
}

void MainGame::fireBullet(void)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (_bullet[i].fire) continue;

		_bullet[i].fire = true;
		_bullet[i].rc = RectMakeCenter
		(
			_playerRC.left + (_playerRC.right - _playerRC.left) / 2,
			_playerRC.top + (_playerRC.bottom - _playerRC.top) / 2 - 24,
			10, 10
		);

		break;
	}
}

/*
과제 1. 종스크롤 슈팅 게임

- 플레이어 체력바 설정
ㄴ 적과 충돌하면 체력이 감소되고 체력바는 3단계로 처리
ㄴ 빨 / 주 / 초

- 플레이어가 발사한 총알로 적을 제거

과제 2. 1 VS 1 횡스크롤 슈팅 게임

- 왼쪽에 1P / 오른쪽에 2P

- 체력 바는 대전게임처럼 중앙을 기준으로 좌우 배치
ㄴ 체력 바 상태에 따라 녹 / 노 / 빨

- 공격 당하면 당한쪽은 당연히 체력이 감소해야 한다.

※ 필수 :
스킬 2개 + 2개 = 4개
아이템을 2종 구현해 온다.

*/
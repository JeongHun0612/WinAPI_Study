#include "Stdafx.h"
#include "Example_Bullet.h"

HRESULT Example_Bullet::init(void)
{
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

void Example_Bullet::release(void)
{
}

void Example_Bullet::update(void)
{
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
			/*
			◈ IntersectRect() : 교집합을 구하는 함수 (RECT 간에)
			- 첫번째 인자는 두 사각형 A, B가 충돌됐을때 생기는 사각형
				ㄴ 이 부분의 크키가 존재한다면 충돌이 된것이고 아니라면 충돌이 안된것

			- 2번 인자의 렉트와 3번 인자의 렉트가 겹치는 영역이 생기면 1번 렉트에 저장을 한다.

			- 충돌을 감지하면 충돌한 인자의 포인터 전달
				ㄴ 충돌이 없으면 0 / 충돌이 발생한 상황이라면 0이 아니다.
			*/

			RECT rt;
			// if문을 사용해서 반환값이 true일 경우에 코드를 작성하면 된다.
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

void Example_Bullet::render(void)
{
	// HP바 그리기
	TextOut(getMemDC(), 10, 10, "HP : ", strlen("HP : "));

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

	FillRect(getMemDC(), &_hpBar, brush);
	DeleteObject(brush);

	// 플레이어 그리기
	DrawRectMake(getMemDC(), _playerRC);

	// 적개체 그리기
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (_enemy[i].die) continue;
		Rectangle(getMemDC(), _enemy[i].rc.left, _enemy[i].rc.top, _enemy[i].rc.right, _enemy[i].rc.bottom);
	}

	// 총알 그리기
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!_bullet[i].fire) continue;
		Ellipse(getMemDC(), _bullet[i].rc.left, _bullet[i].rc.top, _bullet[i].rc.right, _bullet[i].rc.bottom);
	}
}

void Example_Bullet::fireBullet(void)
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
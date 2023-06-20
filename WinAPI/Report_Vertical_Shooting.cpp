#include "Stdafx.h"
#include "Report_Vertical_Shooting.h"

/*
���� 1. ����ũ�� ���� ����

- �÷��̾� ü�¹� ����
�� ���� �浹�ϸ� ü���� ���ҵǰ� ü�¹ٴ� 3�ܰ�� ó��
�� �� / �� / ��

- �÷��̾ �߻��� �Ѿ˷� ���� ����
*/

HRESULT Report_Vertical_Shooting::init(void)
{
	// �÷��̾� �ʱ�ȭ
	_playerRC = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2 + 200, 40, 40);
	_hpBar = RectMake(45, 10, 120, 20);
	_hp = 3;

	// ����ü �ʱ�ȭ
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

void Report_Vertical_Shooting::release(void)
{

}

void Report_Vertical_Shooting::update(void)
{
	// �÷��̾� ����
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

	// �Ѿ� �̵�
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!_bullet[i].fire) continue;
		_bullet[i].rc.top -= 14;
		_bullet[i].rc.bottom -= 14;

		if (_bullet[i].rc.bottom < 0) _bullet[i].fire = false;

		for (int j = 0; j < ENEMY_MAX; j++)
		{
			// �Ѿ˰� ���� �浹 ó��
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

	// ����ü �̵�
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (_enemy[i].die) continue;

		_enemy[i].rc.top += _enemy[i].speed;
		_enemy[i].rc.bottom += _enemy[i].speed;

		// �� ��ü ��ġ ���Ҵ�
		if (_enemy[i].rc.top > WINSIZE_Y)
		{
			_enemy[i].rc = RectMakeCenter(
				RND->getFromIntTo(20, WINSIZE_X - 20),
				-(RND->getFromIntTo(80, WINSIZE_Y * 2)),
				20, 20);
		}

		// �÷��̾�� ���� �浹ó��
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

	if (_hp == 0)
	{

	}
}

void Report_Vertical_Shooting::render(HDC hdc)
{
	// HP�� �׸���
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

	// �÷��̾� �׸���
	DrawRectMake(hdc, _playerRC);

	// ����ü �׸���
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (_enemy[i].die) continue;
		Rectangle(hdc, _enemy[i].rc.left, _enemy[i].rc.top, _enemy[i].rc.right, _enemy[i].rc.bottom);
	}

	// �Ѿ� �׸���
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (!_bullet[i].fire) continue;
		Ellipse(hdc, _bullet[i].rc.left, _bullet[i].rc.top, _bullet[i].rc.right, _bullet[i].rc.bottom);
	}
}

void Report_Vertical_Shooting::fireBullet(void)
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

bool Report_Vertical_Shooting::isGameOver(void)
{
	if (_hp == 0)
	{
		return true;
	}

	return false;
}

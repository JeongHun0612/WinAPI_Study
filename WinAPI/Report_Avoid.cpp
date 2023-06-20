#include "Stdafx.h"
#include "Report_Avoid.h"

/*
���� 1. �� ���ϱ�

- ���� ��ư�� �����鼭 ���� ����

- ������ ���۵ǰ� �÷��̾ ���������� ��ƾ �ð��� ȭ���� ����Ѵ�.

- �ʼ� : ����� + �ٽ��ϱ�

- �÷��̾�� ��� ������� �¿� ����� �ٸ��� ����
*/

HRESULT Report_Avoid::init(void)
{
	_Player = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y - 25, 20, 50);
	_RestartBtn = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, 100, 50);

	_createTime = 50;
	_gameTime = 0;

	_bisDead = false;

	return S_OK;
}

void Report_Avoid::release(void)
{

}

void Report_Avoid::update(void)
{
	if (!_bisDead)
	{
		_count++;

		// CreateDDong
		if (_count % _createTime == 0)
		{
			_DDong.rc = RectMakeCenter(RND->getInt(800), 0, 10, 20);
			_DDong._speed = RND->getFromIntTo(2, 8);
			_vDDong.push_back(_DDong);
		}

		// MoveDDong
		for (_iter = _vDDong.begin(); _iter != _vDDong.end(); ++_iter)
		{
			_iter->rc.top += _iter->_speed;
			_iter->rc.bottom += _iter->_speed;

			if (_iter->rc.top > 800)
			{
				_iter->rc = RectMakeCenter(RND->getInt(800), 0, 10, 20);
			}
		}

		// PlayerMove
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_Player.left -= 5;
			_Player.right -= 5;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_Player.left += 5;
			_Player.right += 5;
		}

		// GameOver
		for (_iter = _vDDong.begin(); _iter != _vDDong.end(); ++_iter)
		{
			RECT rt;
			if (IntersectRect(&rt, &_Player, &_iter->rc))
			{
				_gameTime = _count / 100;
				_bisDead = true;
			}
		}
	}
	else
	{
		// Restart
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_RestartBtn, _ptMouse))
			{
				_vDDong.clear();
				_count = 0;

				setIsInGame(false);
				//_bisDead = false;
			}
		}
	}
}

void Report_Avoid::render(HDC hdc)
{
	if (!_bisDead)
	{
		wsprintf(strTime, "Current Time : %d", _count / 100);
		TextOut(hdc, 0, 0, strTime, strlen(strTime));

		for (_iter = _vDDong.begin(); _iter != _vDDong.end(); _iter++)
		{
			DrawRectMake(hdc, _iter->rc);
		}

		DrawRectMake(hdc, _Player);
	}
	else
	{
		SetTextAlign(hdc, TA_CENTER);

		wsprintf(strTime, "Game Time : %d", _gameTime);
		TextOut(hdc, WINSIZE_X / 2 , WINSIZE_Y / 2 - 50, strTime, strlen(strTime));

		DrawRectMake(hdc, _RestartBtn);
		TextOut(hdc, WINSIZE_X / 2, WINSIZE_Y / 2 - 5, "ReStart", strlen("ReStart"));
	}
}
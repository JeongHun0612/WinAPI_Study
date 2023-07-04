#include "Stdafx.h"
#include "Report_Black_Hole.h"

/*
���� 1. ��Ʈ������ PPT �ۼ�

- ��ǥ���� ���� ����

- �������ϰ� + ����ϰ�


���� 2. ��Ȧ

- �������� �����Ǵ� ������Ʈ ��ü

- �׸��� �ֺ� ������Ʈ�� ���Ƶ��̴� ��Ȧ�� �����.
�� ��Ȧ�� ������ ���ؼ� ������ �� �ִ�.

- ������Ʈ�� �����Ǵ� ��ġ�� �˱����� ǥ�ø� �Ѵ�.
�� EX) �� / �̹��� / ũ��

- �ʼ� : STL -> vector / list

- �ּ� ������Ʈ ������ 1000��

- ���ﰢ�Լ�
*/

HRESULT Report_Black_Hole::init(void)
{
	_blackHole.cx = WINSIZE_X / 2.0f;
	_blackHole.cy = WINSIZE_Y / 2.0f;
	_blackHole.radius = 80.0f;
	_blackHole.speed = 5.0f;

	for (int i = 0; i < MAX_OBJECT; i++)
	{
		Object obj;
		obj.cx = RND->getInt(WINSIZE_X);
		obj.cy = RND->getInt(WINSIZE_Y);
		obj.radius = 10.0f;
		obj.speed = 3.0f;
		obj.directionRadian = 0.0f;
		obj.isCenter = false;

		_vObject.push_back(obj);
	}

	return S_OK;
}

void Report_Black_Hole::release(void)
{
	auto iter = _vObject.begin();

	for (; iter != _vObject.end();)
	{
		iter = _vObject.erase(iter);
		++iter;
	}

	_vObject.clear();
}

void Report_Black_Hole::update(void)
{
	// ������Ʈ ����
	if (_vObject.size() != MAX_OBJECT)
	{
		Object obj;
		obj.cx = RND->getInt(WINSIZE_X);
		obj.cy = RND->getInt(WINSIZE_Y);
		obj.radius = 10.0f;
		obj.speed = 3.0f;
		obj.directionRadian = 0.0f;
		obj.isCenter = false;

		_vObject.push_back(obj);
	}

	// ��Ȧ Ű �Է�
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_blackHole.cx -= _blackHole.speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_blackHole.cx += _blackHole.speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_blackHole.cy -= _blackHole.speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_blackHole.cy += _blackHole.speed;
	}

	for (auto iter = _vObject.begin(); iter != _vObject.end();)
	{
		// ���� radius���� ���̱� (���� �� ��ġ�� Ȯ���ϱ� ����)
		if (iter->radius > 5.0f)
		{
			iter->radius -= 0.5f;
		}

		if (!iter->isCenter)
		{
			// ��Ȧ�� �ٶ󺸴� ������ ����
			iter->directionRadian = atan2(_blackHole.cy - iter->cy, _blackHole.cx - iter->cx);
		}

		// ������Ʈ ��ǥ �̵�
		iter->cx += cosf(iter->directionRadian) * iter->speed;
		iter->cy += sinf(iter->directionRadian) * iter->speed;

		// �������� ���� ��
		if (abs(iter->cx - _blackHole.cx) < 2 && abs(iter->cy - _blackHole.cy) < 2)
		{
			iter->isCenter = true;
			iter->directionRadian = RND->getFloat(2.0f * 3.141592f);
		}

		// ������ ���������� ��
		if (iter->cx < -10 || iter->cx > WINSIZE_X + 10 || iter->cy < -10 || iter->cy > WINSIZE_Y + 10)
		{
			iter = _vObject.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void Report_Black_Hole::render(void)
{
	EllipseMakeCenter(getMemDC(), _blackHole.cx, _blackHole.cy, _blackHole.radius);

	for (auto iter = _vObject.begin(); iter != _vObject.end(); ++iter)
	{
		EllipseMakeCenter(getMemDC(), iter->cx, iter->cy, iter->radius);
	}
}

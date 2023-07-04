#include "Stdafx.h"
#include "Report_Black_Hole.h"

/*
과제 1. 포트폴리오 PPT 작성

- 발표일은 아직 미정

- 디테일하게 + 깔끔하게


과제 2. 블랙홀

- 무작위로 생성되는 오브젝트 객체

- 그리고 주변 오브젝트를 빨아들이는 블랙홀을 만든다.
ㄴ 블랙홀은 조작을 통해서 움직일 수 있다.

- 오브젝트가 생성되는 위치를 알기위해 표시를 한다.
ㄴ EX) 색 / 이미지 / 크기

- 필수 : STL -> vector / list

- 최소 오브젝트 갯수는 1000개

- 역삼각함수
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
	// 오브젝트 생성
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

	// 블랙홀 키 입력
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
		// 생성 radius에서 줄이기 (생성 된 위치를 확인하기 위해)
		if (iter->radius > 5.0f)
		{
			iter->radius -= 0.5f;
		}

		if (!iter->isCenter)
		{
			// 블랙홀을 바라보는 방향의 각도
			iter->directionRadian = atan2(_blackHole.cy - iter->cy, _blackHole.cx - iter->cx);
		}

		// 오브젝트 좌표 이동
		iter->cx += cosf(iter->directionRadian) * iter->speed;
		iter->cy += sinf(iter->directionRadian) * iter->speed;

		// 중점으로 왔을 시
		if (abs(iter->cx - _blackHole.cx) < 2 && abs(iter->cy - _blackHole.cy) < 2)
		{
			iter->isCenter = true;
			iter->directionRadian = RND->getFloat(2.0f * 3.141592f);
		}

		// 밖으로 빠져나갔을 때
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

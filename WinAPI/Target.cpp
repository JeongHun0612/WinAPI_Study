#include "Stdafx.h"
#include "Target.h"

Target::Target()
{
}

Target::Target(int posX, int posY, int moveX, float speed)
{
	_nPosX = posX;
	_nPosY = posY;
	_nWidth = 100;
	_nHeight = 40;

	_nMoveX = moveX;
	_nMoveY = -1;
	_fSpeed = speed;

	_bIsClick = false;
}


Target::~Target()
{
}

void Target::move()
{
	_nPosX += _nMoveX * 10;
	_nPosY += _nMoveY * _fSpeed;
	_fSpeed -= 0.2f;
}

bool Target::isPointInRect()
{
	if ((_ptMouse.x > _nPosX - _nWidth / 2 && _ptMouse.x < _nPosX + _nWidth / 2) || (_ptMouse.x > _nPosX + _nWidth / 2 && _ptMouse.x < _nPosX - _nWidth / 2))
	{
		if ((_ptMouse.y > _nPosY - _nHeight / 2 && _ptMouse.y < _nPosY + _nHeight) || (_ptMouse.y < _nPosY - _nHeight && _ptMouse.y > _nPosY + _nHeight))
		{
			return true;
		}
	}

	return false;
}


void Target::drawTarget(HDC hdc)
{
	RectangleMakeCenter(hdc, _nPosX, _nPosY, _nWidth, _nHeight);
}


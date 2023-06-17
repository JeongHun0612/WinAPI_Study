#include "Stdafx.h"
#include "Mole.h"

Mole::Mole()
{
}

Mole::Mole(int posX, int posY)
{
	_nPosX = posX;
	_nPosY = posY;
	_nWidth = 100;
	_nHeight = 150;

	_bState = false;

	_collider = { _nPosX - _nWidth / 2, _nPosY - _nHeight / 2, _nPosX + _nWidth / 2, _nPosY + _nHeight / 2 };

	_tLifeCycle = clock();
}


Mole::~Mole()
{
}

void Mole::drawMole(HDC hdc)
{
	if (!_bState) return;

	RectangleMakeCenter(hdc, _nPosX, _nPosY, _nWidth, _nHeight);
	EllipseMakeCenter(hdc, _nPosX - 25, _nPosY - 40, 10, 10);
	EllipseMakeCenter(hdc, _nPosX + 25, _nPosY - 40, 10, 10);

	EllipseMakeCenter(hdc, _nPosX - 10, _nPosY - 5, 25, 25);
	EllipseMakeCenter(hdc, _nPosX + 10, _nPosY - 5, 25, 25);
	EllipseMakeCenter(hdc, _nPosX, _nPosY - 15, 15, 15);
}

bool Mole::isPointInRect()
{
	if ((_ptMouse.x > _collider.left && _ptMouse.x < _collider.right) || (_ptMouse.x > _collider.right && _ptMouse.x < _collider.left))
	{
		if ((_ptMouse.y > _collider.top && _ptMouse.y < _collider.bottom) || (_ptMouse.y < _collider.top && _ptMouse.y > _collider.bottom))
		{
			return true;
		}
	}

	return false;
}


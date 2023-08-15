#include "Stdafx.h"
#include "Crush_Minion.h"

Crush_Minion::Crush_Minion() {
	//! Do Nothing
}

Crush_Minion::~Crush_Minion() {
	//! Do Nothing
}

void Crush_Minion::move()
{
	if (_y <= 0)
	{
		_y += _speed;
	}
	else
	{
		if (_y <= WINSIZE_Y_HALF && _x >= WINSIZE_X_HALF)
		{
			_x += cosf(getAngle(_x, _y, WINSIZE_X, WINSIZE_Y_HALF)) * _speed;
			_y += -sinf(getAngle(_x, _y, WINSIZE_X, WINSIZE_Y_HALF)) * _speed;
		}
		else if (_y > WINSIZE_Y_HALF && _x >= WINSIZE_X_HALF)
		{
			_x += cosf(getAngle(_x, _y, WINSIZE_X_HALF, WINSIZE_Y)) * _speed;
			_y += -sinf(getAngle(_x, _y, WINSIZE_X_HALF, WINSIZE_Y)) * _speed;
		}
		else if (_y > WINSIZE_Y_HALF && _x < WINSIZE_X_HALF)
		{
			_x += cosf(getAngle(_x, _y, 0.0f, WINSIZE_Y_HALF)) * _speed;
			_y += -sinf(getAngle(_x, _y, 0.0f, WINSIZE_Y_HALF)) * _speed;
		}
		else
		{
			_x += cosf(getAngle(_x, _y, WINSIZE_X_HALF, 0.0f)) * _speed;
			_y += -sinf(getAngle(_x, _y, WINSIZE_X_HALF, 0.0f)) * _speed;
		}
	}
}

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
		_x += cosf(DEGREE_RADIAN(_angle)) * _speed;
		_y += sinf(DEGREE_RADIAN(_angle)) * _speed;

		if (_x <= 0.0f)
		{
			_x = 0.0f;
			_angle = (180.0f - _angle);
		}

		if (_x >= WINSIZE_X)
		{
			_x = (float)WINSIZE_X;
			_angle = (180.0f - _angle);
		}

		if (_y <= 0.0f)
		{
			_y = 0.0f;
			_angle = (360.0f - _angle);
		}

		if (_y >= WINSIZE_Y)
		{
			_y = (float)WINSIZE_Y;
			_angle = (360.0f - _angle);
		}
	}
}

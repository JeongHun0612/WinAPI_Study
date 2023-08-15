#include "Stdafx.h"
#include "Curve_Minion.h"

Curve_Minion::Curve_Minion() {
	//! Do Nothing
}

Curve_Minion::~Curve_Minion() {
	//! Do Nothing
}

void Curve_Minion::move()
{
	if (_x <= 0.0f)
	{
		_speed = 3.0f;
		_angle = 0.0f;
	}

	if (_x >= WINSIZE_X)
	{
		_speed = -3.0f;
		_angle = 0.0f;
	}

	_x += _speed;

	if (_x >= 0 && _x <= WINSIZE_X)
	{
		_y += sinf(DEGREE_RADIAN(_angle)) * _speed;
		_angle += 3.0f;
	}
}

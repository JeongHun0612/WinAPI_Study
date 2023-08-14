#include "Stdafx.h"
#include "Circle_Minion.h"

Circle_Minion::Circle_Minion() {
	//! Do Nothing
}

Circle_Minion::~Circle_Minion() {
	//! Do Nothing
}

void Circle_Minion::move()
{
	if (_y <= 200)
	{
		_y += _speed;
	}
	else
	{
		_x += cosf(DEGREE_RADIAN(_angle)) * _speed * 2.0f;
		_y += sinf(DEGREE_RADIAN(_angle)) * _speed * 2.0f;

		_angle += _speed / 2.0f;
	}
}

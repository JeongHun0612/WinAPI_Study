#include "Stdafx.h"
#include "Report_3D_Matrix.h"

HRESULT Report_3D_Matrix::init(void)
{

	return S_OK;
}

void Report_3D_Matrix::release(void)
{
}

void Report_3D_Matrix::update(void)
{
}

void Report_3D_Matrix::render(void)
{
	RectangleMakeCenter(getMemDC(), WINSIZE_X / 2, WINSIZE_Y / 2, 100, 100);
}

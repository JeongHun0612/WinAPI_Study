#include "Stdafx.h"
#include "Report_Crocodile.h"

/*
���� 3. �Ǿ��̻� ����

- �Ǿ��̻��� �ּ� 8�� �̻�

- �Ǿ��̻��� ���ȴ��� �ƴ����� ���ؼ� Ȯ���� �����ؾ� �Ѵ�.

- �ʼ� : �Ǿ��̻��� ������ �ִϸ��̼� ����
*/

HRESULT Report_Crocodile::init(void)
{
	return S_OK;
}

void Report_Crocodile::release(void)
{
}

void Report_Crocodile::update(void)
{
}

void Report_Crocodile::render(HDC hdc)
{
	TextOut(hdc, WINSIZE_X / 2, WINSIZE_Y / 2, "�Ǿ� ����", strlen("�Ǿ� ����"));
}

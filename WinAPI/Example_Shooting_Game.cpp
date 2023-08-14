#include "Stdafx.h"
#include "Example_Shooting_Game.h"

/*
[08 / 13]

����1. ���Ͽ� Flame �̹��� �߰�

- Flame �̹����� ���������� ������ ��Ų��.

�� Flame Ŭ�������� ���Ͽ� ���� ������ ������ �ȵǸ� MainGame ���� Flame�� ���� ������ �� �ʿ䰡 ����.

���� 2. ���� �̻��� �߻�

- �̿ϼ� �Լ��� �ϼ��ϰ� ������ �̻����� �߻��Ѵ�.

- �翬�� �̻��� �̹����� ���������� ���


[08 / 14]

����1. �����̴� �� ���� �߰�

- �������� ���� �ٸ��� �ؿ´�.
�� ������ �� 3������ ����� OK

����2. ���� ���� ���� �߰�

- F1 : �Ϲ� �̻���

- F2 : ��ź

- F3 : �̴� ���� ����

- F4 : ����

- F5 : ���� �̻���

- F6 : ������

- F7 : ��Ȧ
�� ������ �޴� ���� �ƴ� ������ ����
�� ��Ȧ�� ������ ����� ���ϼ��� ��ų�� ������ ƨ�� ������ ������ ��������.

*/

HRESULT Example_Shooting_Game::init(void)
{
	IMAGEMANAGER->addImage("���� ��", "Resources/Images/ShootingGame/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_rocket = new Rocket;

	_rocket->init();

	_em = new EnemyManager;
	_em->init();

	return S_OK;
}

void Example_Shooting_Game::release(void)
{
	_rocket->release();
	SAFE_DELETE(_rocket);

	_em->release();
	SAFE_DELETE(_em);
}

void Example_Shooting_Game::update(void)
{
	_rocket->update();
	_em->update();
}

void Example_Shooting_Game::render(void)
{
	IMAGEMANAGER->findImage("���� ��")->render(getMemDC());

	_rocket->render();
	_em->render();
}

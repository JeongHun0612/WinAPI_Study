#include "Stdafx.h"
#include "Example_Shooting_Game.h"

/*
����1. ���Ͽ� Flame �̹��� �߰�

- Flame �̹����� ���������� ������ ��Ų��.

�� Flame Ŭ�������� ���Ͽ� ���� ������ ������ �ȵǸ� MainGame ���� Flame�� ���� ������ �� �ʿ䰡 ����.

���� 2. ���� �̻��� �߻�

- �̿ϼ� �Լ��� �ϼ��ϰ� ������ �̻����� �߻��Ѵ�.

- �翬�� �̻��� �̹����� ���������� ���
*/

HRESULT Example_Shooting_Game::init(void)
{
	IMAGEMANAGER->addImage("���� ��", "Resources/Images/ShootingGame/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_rocket = new Rocket;

	_rocket->init();

	return S_OK;
}

void Example_Shooting_Game::release(void)
{
	_rocket->release();
}

void Example_Shooting_Game::update(void)
{
	_rocket->update();
}

void Example_Shooting_Game::render(void)
{
	IMAGEMANAGER->findImage("���� ��")->render(getMemDC());

	_rocket->render();
}

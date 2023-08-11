#include "Stdafx.h"
#include "Example_Shooting_Game.h"

/*

[08/10]
����1. ���Ͽ� Flame �̹��� �߰�

- Flame �̹����� ���������� ������ ��Ų��.

�� Flame Ŭ�������� ���Ͽ� ���� ������ ������ �ȵǸ� MainGame ���� Flame�� ���� ������ �� �ʿ䰡 ����.

[08/11]
���� 1. ���� �̻��� �߻�

- �̿ϼ� �Լ��� �ϼ��ϰ� ������ �̻����� �߻��Ѵ�.

- �翬�� �̻��� �̹����� ���������� ���

���� 2. �� ��Ʈ�������� ���� ���� ���� �ӹ�

- ���� �ĺ��� 3�� (2��)

���� 3. Ÿ�ϸ� �����

- ����ڰ� �Է��� ���ڷ� Ÿ�ϸ��� �׸���. (�ִ� ������ : 100)
�� EX : 20�� �Է��ϸ� 20 X 20 �������� Ÿ���� ȭ�鿡 �׷�����.

- Ÿ�ϸʾȿ��� ������ ��ġ�� �̹��� 2���� ����.

- �̹����� �Ź� Ÿ�ϸ��� ���� �׷��ٶ����� ��ġ�� �ٲ��� �ϰ� �׷��� �̹����� ���콺�� Ŭ���� �� ������ ��ġ ���� ������ �� �־�� �Ѵ�.

�ʼ� : STL ����
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

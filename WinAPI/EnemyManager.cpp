#include "Stdafx.h"
#include "EnemyManager.h"
#include "Minion.h"

HRESULT EnemyManager::init(void)
{
	IMAGEMANAGER->addFrameImage("���ĸ�", "Resources/Images/ShootingGame/JellyFish.bmp",
		0.0f, 0.0f, 1140, 47, 19, 1, true, RGB(255, 0, 255));

	setMinion();

	return S_OK;
}

void EnemyManager::release(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->release();
		SAFE_DELETE(*_viMinion);
	}
}

void EnemyManager::update(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}
}

void EnemyManager::render(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
}

void EnemyManager::setMinion(void)
{
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		Enemy* jellyFish;
	//		jellyFish = new Minion;
	//		jellyFish->init("���ĸ�", PointMake(250 + j * 200, 100 + i * 100), 3.0f);
	//		_vMinion.push_back(jellyFish);
	//	}
	//}

	for (int i = 0; i < 30; i++)
	{
		Enemy* jellyFish;
		jellyFish = new Minion;
		jellyFish->init("���ĸ�", PointMake(WINSIZE_X_HALF, (i * -50)), 3.0f);

		_vMinion.push_back(jellyFish);
	}
}
#include "Stdafx.h"
#include "EnemyManager.h"
#include "Circle_Minion.h"
#include "Curve_Minion.h"
#include "Crush_Minion.h"

HRESULT EnemyManager::init(void)
{
	return S_OK;
}

HRESULT EnemyManager::init(Rocket* rocket)
{
	IMAGEMANAGER->addFrameImage("해파리", "Resources/Images/ShootingGame/JellyFish.bmp",
		0.0f, 0.0f, 1140, 47, 19, 1, true, RGB(255, 0, 255));

	effectImg = IMAGEMANAGER->addFrameImage("사망이펙트", "Resources/Images/ShootingGame/effect_explosion.bmp",
		0.0f, 0.0f, 1152, 144, 8, 1, true, RGB(255, 0, 255));

	setMinion("해파리", 25, 3.0f, MOVE_PATTERN::CIRCLA);
	setMinion("해파리", 25, 3.0f, MOVE_PATTERN::CURVE);
	setMinion("해파리", 20, 5.0f, MOVE_PATTERN::CRUSH);

	_rocket = rocket;

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

		//if (_rocket->getMisslie()->collisionCheck((*_viMinion)->getRC()))
		//{
		//	(*_viMinion)->setCurHP((*_viMinion)->getCurHP() - 1);

		//	if ((*_viMinion)->getCurHP() <= 0)
		//	{
		//		_viMinion = _vMinion.erase(_viMinion);
		//	}
		//	else ++_viMinion;
		//}
		//else ++_viMinion;
	}

	dieAnimation();
}

void EnemyManager::render(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}
}

void EnemyManager::setMinion(const char* imageName, int count, float speed, MOVE_PATTERN type)
{
	for (int i = 0; i < count; i++)
	{
		Enemy* jellyFish;

		switch (type)
		{
		case MOVE_PATTERN::CIRCLA:
			jellyFish = new Circle_Minion;
			jellyFish->init(imageName, PointMake(WINSIZE_X_HALF, (i * -50)), speed);
			break;
		case MOVE_PATTERN::CURVE:
			jellyFish = new Curve_Minion;
			jellyFish->init(imageName, PointMake((i * -50), WINSIZE_Y_HALF), speed);
			break;
		case MOVE_PATTERN::CRUSH:
			jellyFish = new Crush_Minion;
			jellyFish->init(imageName, PointMake(WINSIZE_X_HALF, (i * -50)), speed, 30.0f);
			break;
		}

		_vMinion.push_back(jellyFish);
	}
}

void EnemyManager::removeMinion(int arrNum)
{
	_effectPos.push_back(_vMinion[arrNum]->getRC());

	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void EnemyManager::dieAnimation(void)
{
	for (int i = 0; i < _effectPos.size(); i++)
	{
		effectImg->frameRender(getMemDC(), _effectPos[i].left, _effectPos[i].top, effectImg->getFrameX(), effectImg->getFrameY());
	}
}

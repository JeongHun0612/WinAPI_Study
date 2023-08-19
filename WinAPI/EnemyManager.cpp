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
	IMAGEMANAGER->addFrameImage("해파리", "Resources/Images/ShootingGame/JellyFish.bmp", 1140, 47, 19, 1, true, RGB(255, 0, 255));

	setMinion("해파리", 25, 3.0f, MOVE_PATTERN::CIRCLA);
	setMinion("해파리", 25, 3.0f, MOVE_PATTERN::CURVE);
	setMinion("해파리", 20, 5.0f, MOVE_PATTERN::CRUSH);

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

	for (_viAnim = _vAnim.begin(); _viAnim != _vAnim.end();)
	{
		_viAnim->timeCount += TIMEMANAGER->getElapsedTime();

		if (_viAnim->timeCount >= 0.1f)
		{
			_viAnim->img->setFrameX(_viAnim->img->getFrameX() + 1);

			_viAnim->timeCount = 0.0f;
		}

		if (_viAnim->img->getFrameX() == _viAnim->img->getMaxFrameX())
		{
			_viAnim = _vAnim.erase(_viAnim);
		}
		else ++_viAnim++;
	}
}

void EnemyManager::render(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	for (_viAnim = _vAnim.begin(); _viAnim != _vAnim.end(); ++_viAnim)
	{
		_viAnim->img->frameRender(getMemDC(), _viAnim->x, _viAnim->y, _viAnim->img->getFrameX(), _viAnim->img->getFrameY());
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
	Animation dieAnim;
	ZeroMemory(&dieAnim, sizeof(Animation));
	dieAnim.img = new GImage;
	dieAnim.img->init("Resources/Images/ShootingGame/effect_die.bmp", 1064, 46, 14, 1, true, RGB(255, 0, 255));
	dieAnim.x = _vMinion[arrNum]->getX() - dieAnim.img->getFrameWidth() / 2;
	dieAnim.y = _vMinion[arrNum]->getY() - dieAnim.img->getFrameHeight() / 2;
	dieAnim.timeCount = 0.0f;
	_vAnim.push_back(dieAnim);

	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}
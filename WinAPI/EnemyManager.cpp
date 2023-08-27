#include "Stdafx.h"
#include "EnemyManager.h"
#include "Rocket.h"
#include "Circle_Minion.h"
#include "Curve_Minion.h"
#include "Crush_Minion.h"

HRESULT EnemyManager::init(void)
{
	IMAGEMANAGER->addFrameImage("���ĸ�", "Resources/Images/ShootingGame/JellyFish.bmp", 1140, 47, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�� �̻���", "Resources/Images/ShootingGame/Bullet.bmp", 14, 14, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������Ʈ", "Resources/Images/ShootingGame/effect_die.bmp", 532, 23, true, RGB(255, 0, 255));

	setMinion("���ĸ�", 25, 3.0f, MOVE_PATTERN::CIRCLA);
	setMinion("���ĸ�", 25, 3.0f, MOVE_PATTERN::CURVE);
	setMinion("���ĸ�", 20, 5.0f, MOVE_PATTERN::CRUSH);

	_bullet = new Bullet;
	_bullet->init("�� �̻���", 5, 500);

	_dieEffectImg = IMAGEMANAGER->findImage("�������Ʈ");
	_dieAnim = new Animation;
	_dieAnim->init(_dieEffectImg->getWidth(), _dieEffectImg->getHeight(), 38, 23);

	return S_OK;
}

void EnemyManager::release(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->release();
		SAFE_DELETE(*_viMinion);
	}

	_bullet->release();
	SAFE_DELETE(_bullet);
}

void EnemyManager::update(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	minionBulletFire();
	_bullet->update();
	collision();

	_dieAnim->frameUpdate(TIMEMANAGER->getElapsedTime());
}

void EnemyManager::render(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
	_dieEffectImg->aniRender(getMemDC(), _vMinion[arrNum]->getX(), _vMinion[arrNum]->getY(), _dieAnim);
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
	//Animation dieAnim;
	//ZeroMemory(&dieAnim, sizeof(Animation));
	//dieAnim.img = new GImage;
	//dieAnim.img->init("Resources/Images/ShootingGame/effect_die.bmp", 1064, 46, 14, 1, true, RGB(255, 0, 255));
	//dieAnim.x = _vMinion[arrNum]->getX() - dieAnim.img->getFrameWidth() / 2;
	//dieAnim.y = _vMinion[arrNum]->getY() - dieAnim.img->getFrameHeight() / 2;
	//dieAnim.timeCount = 0.0f;
	//_vAnim.push_back(dieAnim);

	_dieAnim->AniStart();

	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void EnemyManager::minionBulletFire(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRC();

			_bullet->fire(
				rc.left + (rc.right - rc.left) / 2,
				rc.bottom + (rc.top - rc.bottom) / 2 + 30,
				getAngle(rc.left + (rc.right - rc.left) / 2, rc.bottom + (rc.top - rc.bottom) / 2 + 30, _rocket->getPosition().x, _rocket->getPosition().y),
				RND->getFromFloatTo(2.0f, 4.0f));
		}
	}
}

void EnemyManager::collision(void)
{
	for (int i = 0; i < _bullet->getBullet().size(); i++)
	{
		RECT rc;

		if (IntersectRect(&rc, &_bullet->getBullet()[i].rc, &_rocket->getRect()))
		{
			_bullet->removeBullet(i);
			_rocket->hitDamage(1.0f);
		}
	}
}

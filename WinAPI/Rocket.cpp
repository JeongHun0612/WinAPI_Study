#include "Stdafx.h"
#include "Rocket.h"
#include "EnemyManager.h"

// 설계와의 싸움
HRESULT Rocket::init()
{
	// 객체의 의한 매니저할당
	_image = IMAGEMANAGER->addImage("로켓", "Resources/Images/ShootingGame/Rocket.bmp", 52, 64, true, RGB(255, 0, 255));

	_x = WINSIZE_X_HALF;
	_y = WINSIZE_Y_HALF;

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

	_flame = new Flame;
	_flame->init("Flame.bmp", & _x, &_y);

	// 미사일 셋팅
	_missile = new Missile;
	_missile->init(30, 600.0f);

	_beam = new Beam;
	_beam->init(1, 0.0f);
	_isBeamLaunch = false;

	_weaponType = WEAPON_TYPE::MISSILE;

	_maxHP = 10;
	_currentHP = 10;

	_hpBar = new ProgressBar;
	_hpBar->init(_x, _y, 52, 4);


	//std::shared_ptr<Rocket> PlayerA = std::make_shared<Rocket>();
	//std::shared_ptr<Rocket> PlayerB = PlayerA->get_shared_ptr();

	//PlayerA.use_count();

	// 좀 더 효율적인 방법
	//spRocket.push_back(std::shared_ptr<Rocket>(new Rocket));

	return S_OK;
}

void Rocket::release(void)
{
	_flame->release();
	SAFE_DELETE(_flame);

	_missile->release();
	SAFE_DELETE(_missile);

	_beam->release();
	SAFE_DELETE(_beam);

	_hpBar->release();
	SAFE_DELETE(_hpBar);
}

void Rocket::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('1')) hitDamage(1.0f);
	if (KEYMANAGER->isOnceKeyDown('2')) hitDamage(-1.0f);

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left > 0 && !_isBeamLaunch)
	{
		_x -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X && !_isBeamLaunch)
	{
		_x += ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top > 0)
	{
		_y -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom < WINSIZE_Y)
	{
		_y += ROCKET_SPEED;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_weaponType = WEAPON_TYPE::MISSILE;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F6))
	{
		_weaponType = WEAPON_TYPE::BEAM;
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		switch (_weaponType)
		{
		case WEAPON_TYPE::MISSILE:
			_missile->fire(_x, _y - 60);
			break;
		case WEAPON_TYPE::BEAM:
			_beam->fire(_x, _y - 60);
			_isBeamLaunch = true;
			break;
		}
	}

	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());

	_flame->update();

	_missile->update();
	_beam->update();

<<<<<<< HEAD
	collision();

	_hpBar->setX(_x - (_rc.right - _rc.left) / 2);
=======
	//_hpBar->setX(_x - (_rc.right - _rc.left) / 2);
	//_hpBar->setY(_y - 10 - (_rc.bottom - _rc.top) / 2);

	_hpBar->setX(_x);
>>>>>>> 405db0e9a214c8055030d8d6c895a9cf654badb3
	_hpBar->setY(_y - 10 - (_rc.bottom - _rc.top) / 2);

	_hpBar->update();
	_hpBar->setGauge(_currentHP, _maxHP);
}

void Rocket::render(void)
{
	_image->render(getMemDC(), _rc.left, _rc.top);
	_flame->render();

	_missile->render();
	_beam->render();

	_hpBar->render();
}

void Rocket::collision(void)
{
	// 미사일 충돌
	for (int i = 0; i < _missile->getBullet().size(); i++)
	{
		for (int j = 0; j < _em->getMinions().size(); j++)
		{
			RECT rc;

			if (IntersectRect(&rc, &_missile->getBullet()[i].rc, &CollisionAreaResizing(_em->getMinions()[j]->getRC(), 40, 30)))
			{
				_missile->removeBullet(i);

				_em->getMinions()[j]->setCurHP(_em->getMinions()[j]->getCurHP() - 1);

				if (_em->getMinions()[j]->getCurHP() == 0)
				{
					_em->removeMinion(j);
				}

				break;
			}
		}
	}

	// 빔 충돌
	for (int i = 0; i < _beam->getBullet().size(); i++)
	{
		for (int j = 0; j < _em->getMinions().size(); j++)
		{
			RECT rc;

			if (IntersectRect(&rc, &_beam->getBullet()[i].rc, &CollisionAreaResizing(_em->getMinions()[j]->getRC(), 40, 30)))
			{
				_em->getMinions()[j]->setCurHP(_em->getMinions()[j]->getCurHP() - 1);

				if (_em->getMinions()[j]->getCurHP() == 0)
				{
					_em->removeMinion(j);
				}
				break;
			}
		}
	}
}

void Rocket::removeMissile(int arrNum)
{
	_missile->removeBullet(arrNum);
}

#include "Stdafx.h"
#include "Example_Shooting_Game.h"

void Example_Shooting_Game::collision(void)
{
	switch (_rocket->getMisslie()->getBulletType())
	{
	case BULLET_TYPE::NORMAL_BULLET:
		for (int i = 0; i < _rocket->getMisslie()->getBullet().size(); i++)
		{
			for (int j = 0; j < _em->getMinions().size(); j++)
			{
				RECT rc;

				if (IntersectRect(&rc, &_rocket->getMisslie()->getBullet()[i].rc, &CollisionAreaResizing(_em->getMinions()[j]->getRC(), 40, 30)))
				{
					_rocket->removeMissile(i);

					_em->getMinions()[j]->setCurHP(_em->getMinions()[j]->getCurHP() - 1);

					if (_em->getMinions()[j]->getCurHP() == 0)
					{
						_em->removeMinion(j);
					}
					break;
				}
			}
		}
		break;
	default:
		for (int i = 0; i < _rocket->getMisslie()->getBullet().size(); i++)
		{
			for (int j = 0; j < _em->getMinions().size(); j++)
			{
				RECT rc;

				if (IntersectRect(&rc, &_rocket->getMisslie()->getBullet()[i].rc, &CollisionAreaResizing(_em->getMinions()[j]->getRC(), 40, 30)))
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
		break;
	}
}

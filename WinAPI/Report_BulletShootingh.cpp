#include "Stdafx.h"
#include "Report_BulletShooting.h"

/*
���� 2. �Ѿ� �߻�

- �ϴܿ��� �¿�� ������ �� �ִ� �÷��̾ ����

- �����̽� �ٸ� ������ �÷��̾ �Ѿ��� �߻��Ѵ�.
*/

HRESULT Report_BulletShooting::init(void)
{
    _posX = WINSIZE_X / 2;

    return S_OK;
}

void Report_BulletShooting::release(void)
{
}

void Report_BulletShooting::update(void)
{
    if (KEYMANAGER->isStayKeyDown(VK_LEFT))
    {
        _posX -= 5;
    }
    if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
    {
        _posX += 5;
    }
    if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
    {
        RECT bullet = RectMakeCenter(_posX, WINSIZE_Y - 100, 10, 20);
        _vBullet.push_back(bullet);
    }

    for (int i = 0; i < _vBullet.size(); i++)
    {
        _vBullet[i].top -= 5;
        _vBullet[i].bottom -= 5;

        if (_vBullet[i].bottom < 0)
        {
            _vBullet.erase(_vBullet.begin() + i);
        }
    }
}

void Report_BulletShooting::render(void)
{
    RectangleMakeCenter(getMemDC(), _posX, WINSIZE_Y - 50, 50, 100);

    for (auto viNum = _vBullet.begin(); viNum != _vBullet.end(); viNum++)
    {
        DrawRectMake(getMemDC(), *viNum);
    }
}

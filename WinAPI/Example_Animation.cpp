#include "Stdafx.h"
#include "Example_Animation.h"

/*
���� 1. SVN or Git ����

- SVN or Git ������ �͵��ؼ� X�� ����� �ǵ��� �������� ��ȭ�� ������.

- �۾� �̷� ĸó�ؼ� ���� ����

���� 2. �ִϸ��̼� Ŭ������ ���� �Լ� �ϼ�

- �̿ϼ� �Լ� �ϼ� ��Ű��

�� setPlayFrame()
�� setPlayFrame()
�� setFPS()

���� 3. ���� ��Ʈ������ ���� �۾� (�ڵ� X -> �̹���)
*/

HRESULT Example_Animation::init(void)
{
    _image = IMAGEMANAGER->addImage("�ڳ���", "Resources/Images/Object/Elephant.bmp", 660, 268, true, RGB(255, 0, 255));

    _animationA = new Animation;
    _animationA->init(_image->getWidth(), _image->getHeight(), 110, 67);
    _animationA->setDefPlayFrame(false, true);
    _animationA->setFPS(0.2);

    return S_OK;
}

void Example_Animation::release(void)
{
    _animationA->release();
    SAFE_DELETE(_animationA);
}

void Example_Animation::update(void)
{
    if (KEYMANAGER->isOnceKeyDown('B'))
    {
        _animationA->AniStart();
    }

    _animationA->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);
}

void Example_Animation::render(void)
{
    _image->aniRender(getMemDC(), WINSIZE_X_HALF - 50, WINSIZE_Y_HALF, _animationA);
}

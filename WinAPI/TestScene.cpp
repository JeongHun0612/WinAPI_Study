#include "Stdafx.h"
#include "TestScene.h"

HRESULT TestScene::init(void)
{
    return S_OK;
}

void TestScene::release(void)
{
}

void TestScene::update(void)
{
}

void TestScene::render(void)
{
    RectangleMake(getMemDC(), WINSIZE_X_HALF, WINSIZE_Y_HALF, 100, 100);
}

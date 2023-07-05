#include "Stdafx.h"
#include "StartScene.h"

HRESULT StartScene::init(void)
{
	IMAGEMANAGER->addImage("����ȭ��", "Resources/Images/Background/StartBG.bmp", WINSIZE_X, WINSIZE_Y);

	IMAGEMANAGER->addImage("�ؽ�Ʈ ����", "Resources/Images/Background/StartText.bmp", 1000, 100, true, RGB(255, 0, 255));


	return S_OK;
}

void StartScene::release(void)
{
}

void StartScene::update(void)
{
	_alpha -= 3.0f;
	if (_alpha <= 0) _alpha = 255;

	_bgAlpha += 0.5f;
	if (_bgAlpha >= 255) _bgAlpha = 0;
}

void StartScene::render(void)
{
	IMAGEMANAGER->render("����ȭ��", getMemDC());

	IMAGEMANAGER->alphaRender("����ȭ��", getMemDC(), 0, 0, _bgAlpha);

	if (_bgAlpha >= 160)
	{
		IMAGEMANAGER->alphaRender("�ؽ�Ʈ ����", getMemDC(), 130, WINSIZE_Y / 2 + 200, _alpha);
	}
}
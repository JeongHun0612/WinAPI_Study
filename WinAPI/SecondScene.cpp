#include "Stdafx.h"
#include "SecondScene.h"

HRESULT SecondScene::init(void)
{
	return E_NOTIMPL;
}

void SecondScene::release(void)
{
}

void SecondScene::update(void)
{
}

void SecondScene::render(void)
{

	// SetBkMode() : �ؽ�Ʈ ����� �����ϰ� ���ش�.
	SetBkMode(getMemDC(), TRANSPARENT);

	// ���� �ؽ�Ʈ
	char str[128];
	wsprintf(str, "����");
	TextOut(getMemDC(), 230, 350, str, strlen(str));

	// ���ο� ���
	HFONT font;
	HFONT oldFont;

	/*
	font = CreateFont
	(
		����ũ��, ������, ��ü ����, ���� ����, ���� ����,
		���� (T/F), ���� (T/F), ��Ҽ�(T/F),
		���� ����, ��� ��Ȯ��, Ŭ�� ��Ȯ��, ����� ��, �ڰ�, ��Ʈ
	);
	*/

	font = CreateFont
	(
		70, 0, 0, 0, 600,
		0, 0, 1,
		HANGEUL_CHARSET, 0, 0, 0, 0, TEXT("�޸鱼��")
	);

	oldFont = (HFONT)SelectObject(getMemDC(), font);

	wsprintf(str, "���ο� ��Ʈ");
	TextOut(getMemDC(), 100, 400, str, strlen(str));
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);
}

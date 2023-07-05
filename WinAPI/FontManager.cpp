#include "Stdafx.h"
#include "FontManager.h"

HRESULT FontManager::init()
{
	return S_OK;
}

void FontManager::release()
{
	// ! Do Nothing
}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fonsSize, int fontWidth, char* printString, int length, COLORREF color)
{
	// SetBkMode() : �ؽ�Ʈ ���� ���� �����ϰ� �����.
	SetBkMode(hdc, TRANSPARENT);

	//HFONT font = CreateFont
	//(
	//	fonsSize,				// ����ũ��
	//	0,						// ������
	//	0,						// ��ü ����
	//	0,						// ���� ����
	//	fontWidth,				// ���� ����
	//	0,						// ���� (T / F)
	//	0,						// ���� (T / F)
	//	0,						// ��Ҽ� (T / F)
	//	HANGEUL_CHARSET,		// ���� ����
	//	0,						// ��� ��Ȯ��
	//	0,						// Ŭ�� ��Ȯ��
	//	0,						// ����� ��
	//	0,						// �ڰ�
	//	TEXT(fontName)			// ��Ʈ
	//);

	// ���ο� ���
	auto font = CreateFont
	(
		fonsSize,				// ����ũ��
		0,						// ������
		0,						// ��ü ����
		0,						// ���� ����
		fontWidth,				// ���� ����
		0,						// ���� (T / F)
		0,						// ���� (T / F)
		0,						// ��Ҽ� (T / F)
		HANGEUL_CHARSET,		// ���� ����
		0,						// ��� ��Ȯ��
		0,						// Ŭ�� ��Ȯ��
		0,						// ����� ��
		0,						// �ڰ�
		TEXT(fontName)			// ��Ʈ
	);

	auto oldFont = (HFONT)SelectObject(hdc, font);

	// ��Ʈ ���� ����
	SetTextColor(hdc, color);

	// �ؽ�Ʈ ���
	const int stringLength = strlen(printString);
	TextOut(hdc, destX, destY, printString, stringLength);

	// �⺻ ��Ʈ�� ����
	SelectObject(hdc, oldFont);
	SetTextColor(hdc, RGB(0, 0, 0));
	DeleteObject(font);
}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fonsSize, int fontWidth, LPCWSTR printString, int length, COLORREF color)
{
	// SetBkMode() : �ؽ�Ʈ ���� ���� �����ϰ� �����.
	SetBkMode(hdc, TRANSPARENT);

	// ���ο� ���
	auto font = CreateFont
	(
		fonsSize,				// ����ũ��
		0,						// ������
		0,						// ��ü ����
		0,						// ���� ����
		fontWidth,				// ���� ����
		0,						// ���� (T / F)
		0,						// ���� (T / F)
		0,						// ��Ҽ� (T / F)
		HANGEUL_CHARSET,		// ���� ����
		0,						// ��� ��Ȯ��
		0,						// Ŭ�� ��Ȯ��
		0,						// ����� ��
		0,						// �ڰ�
		TEXT(fontName)			// ��Ʈ
	);

	auto oldFont = (HFONT)SelectObject(hdc, font);

	// ��Ʈ ���� ����
	SetTextColor(hdc, color);

	// �ؽ�Ʈ ���
	wchar_t charBuffer[256];
	ZeroMemory(charBuffer, sizeof(charBuffer));


	TextOutW(hdc, destX, destY, printString, length);

	// �⺻ ��Ʈ�� ����
	SelectObject(hdc, oldFont);
	SetTextColor(hdc, RGB(0, 0, 0));
	DeleteObject(font);




}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fonsSize, int fontWidth, LPCWSTR* printStringArr, int length, COLORREF color)
{
	int arraySize = sizeof(printStringArr) / sizeof(*printStringArr);

	int lineCount = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if (i == 0)
		{
	/*		if ()
			{

			}
			else
			{
				break;
			}*/
		}
		else
		{

		}
	}
}

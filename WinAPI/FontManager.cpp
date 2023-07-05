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
	// SetBkMode() : 텍스트 버퍼 등을 투명하게 만든다.
	SetBkMode(hdc, TRANSPARENT);

	//HFONT font = CreateFont
	//(
	//	fonsSize,				// 문자크기
	//	0,						// 문자폭
	//	0,						// 전체 기울기
	//	0,						// 문자 방향
	//	fontWidth,				// 문자 굵기
	//	0,						// 기울기 (T / F)
	//	0,						// 밑줄 (T / F)
	//	0,						// 취소선 (T / F)
	//	HANGEUL_CHARSET,		// 문자 세팅
	//	0,						// 출력 정확도
	//	0,						// 클릭 정확도
	//	0,						// 출력의 질
	//	0,						// 자간
	//	TEXT(fontName)			// 폰트
	//);

	// 새로운 방식
	auto font = CreateFont
	(
		fonsSize,				// 문자크기
		0,						// 문자폭
		0,						// 전체 기울기
		0,						// 문자 방향
		fontWidth,				// 문자 굵기
		0,						// 기울기 (T / F)
		0,						// 밑줄 (T / F)
		0,						// 취소선 (T / F)
		HANGEUL_CHARSET,		// 문자 세팅
		0,						// 출력 정확도
		0,						// 클릭 정확도
		0,						// 출력의 질
		0,						// 자간
		TEXT(fontName)			// 폰트
	);

	auto oldFont = (HFONT)SelectObject(hdc, font);

	// 폰트 색깔 변경
	SetTextColor(hdc, color);

	// 텍스트 출력
	const int stringLength = strlen(printString);
	TextOut(hdc, destX, destY, printString, stringLength);

	// 기본 폰트로 리셋
	SelectObject(hdc, oldFont);
	SetTextColor(hdc, RGB(0, 0, 0));
	DeleteObject(font);
}

void FontManager::drawText(HDC hdc, int destX, int destY, char* fontName, int fonsSize, int fontWidth, LPCWSTR printString, int length, COLORREF color)
{
	// SetBkMode() : 텍스트 버퍼 등을 투명하게 만든다.
	SetBkMode(hdc, TRANSPARENT);

	// 새로운 방식
	auto font = CreateFont
	(
		fonsSize,				// 문자크기
		0,						// 문자폭
		0,						// 전체 기울기
		0,						// 문자 방향
		fontWidth,				// 문자 굵기
		0,						// 기울기 (T / F)
		0,						// 밑줄 (T / F)
		0,						// 취소선 (T / F)
		HANGEUL_CHARSET,		// 문자 세팅
		0,						// 출력 정확도
		0,						// 클릭 정확도
		0,						// 출력의 질
		0,						// 자간
		TEXT(fontName)			// 폰트
	);

	auto oldFont = (HFONT)SelectObject(hdc, font);

	// 폰트 색깔 변경
	SetTextColor(hdc, color);

	// 텍스트 출력
	wchar_t charBuffer[256];
	ZeroMemory(charBuffer, sizeof(charBuffer));


	TextOutW(hdc, destX, destY, printString, length);

	// 기본 폰트로 리셋
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

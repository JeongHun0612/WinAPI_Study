#pragma once

// 4005��� ��� �����ϰڴ�.
#pragma warning(disable : 4005)
// 4005 : DXGI �� �׷��� �������̽����� ��ũ�� �����Ͽ� ��µǴ� ���
//#include "targetver.h" 

/*
�� Stdafx

- MS�� ����� ��Ʃ����� �̿��Ͽ� ������Ʈ�� ����� �����Ǵ� Ŭ�����̴�.
	�� �� ģ���� �ǹ��ϴ� �ٴ� ǥ�� ���ø����̼� �����ӿ�ũ�� Ʋ

- MS���� �����ڵ��� �ɷ� ����� ���� ������ PCH ����
	�� ���� ���̴� �������� ������� �̸� ������ �صξ� ���� �ٽ� ���������� �ʰ� ����ϰ� �ȴ�.

- ���߿� �ʱ� ���� �ܰ迡���� �ʿ伺�� ���������� ��� ������ ũ�Ⱑ Ŀ���ų� ���� ���� ������ Ȱ�뵵 �� ȿ���� �޻���Ѵ�.
*/

// SDKDDKVER.h�� ���α׷����� ������ OS Ȥ�� ���̺귯���� ���� Windows ������� �ڵ尡 ���Ե� �Լ� / ��� ���� �����ϴµ� ��� �Ѵ�.
#include <SDKDDKVER.h>


// ���� ������ �ʴ� ������ Windows ������� ����
// �� GDI+�� ����Ϸ��� ������Ͽ��� �����;� �Ѵ�.
//#include <ole2.h>
#define WIN32_LEAN_AND_MEAN

// ! ���̺귯�� �߰� ============================================================================================================
#pragma comment (lib, "msimg32.lib")

//! Windows ��� ���� ============================================================================================================
#include <Windows.h>

//! C ��Ÿ�� ��� ���� ============================================================================================================
// stdlib : C����� ǥ�� ���̺귯�� �Լ��� ��� ����
#include <stdlib.h>

// C�𿡼� �޸� �Ҵ��Ҷ� ��G�Ѵ�.
#include <malloc.h>

// �޸� ���� ��� ���� 
// �� memset / memcpy�� ����ϴ� ������� (������ Windows.h �����ϸ� ���ٰ���)
#include <memory.h>
#include <time.h>

/*
�� ���ڿ� ��

- �����쿡�� ����� ���ڿ� ��� ����(����) �� (TextOut, DrawText, wsprintf ���)
 �� �⺻������ �����ڵ���

MBCS (��Ƽ ����Ʈ ĳ���� ��)

- ������ ����ϴ� ��Ƽ����Ʈ ������ ���ڿ��� ���Ѵ�.
- ��Ƽ����Ʈ �ڵ�� ���� ���� �ƽ�Ű �ڵ忡 ���ԵǴ� ���ڴ� 1����Ʈ�� ǥ���ǰ� ���Ե��� �ʴ� ���ڴ� 2����Ʈ�� ó���Ѵ�.


WBCS (���̵� ����Ʈ ĳ���� ��)

- ��� ���ڸ� 2����Ʈ�� ó���ϸ� �����ڵ� ����̴�.


�� �����ڵ�� ��Ƽ����Ʈ�� ���

- VS������ ���߽� � ���ڼ�(��Ƽ ����Ʈ, �����ڵ�)�� ������� ������ ����� �Ѵ�.

- �����ڵ��� ��쿡�� ���ڿ��� ����ǥ�� ���ΰ� �� �տ� L�� �ٿ��� (L"")�̶�� ǥ���ؾ� �Ѵ�.

- ��Ƽ����Ʈ ���� ��쿡�� �׳� ""�� ����ϸ� �ȴ�.

- �����ڵ�� ���ߵ� ���α׷��� ��Ƽ����Ʈ�� �̽��Ϸ��� �̵� ���ڿ��� ǥ�� ����� �ٽ� ������� �ϱ� ������ �ſ� �����ϴ�.
	�� �׷��� _T ��ũ�θ� ����ؾ� �Ѵ�.

- ���ڿ��� ����ǥ�� ���ΰ� �����ڵ忡�� ����� "L"��� "_T"�� ����ϸ� ��ũ�ΰ� �˾Ƽ� ���� ȯ�濡 �°� ġȯ�� �ش�.
*/
#include <tchar.h>

// stdio : ǥ�� ����� ��� ����
#include <stdio.h>


//! C++ ��Ÿ�� ��� ���� ============================================================================================================
#include <iostream>

/*
- C++11���� �߰��� �ð� ���� ���̺귯�� (STL)
�� ���� C ��Ÿ�ӿ��� �����ϴ� time �Լ����� �پ��ϰ� Ȯ��� ����� �����Ѵ�.
�� ���� : ���е��� ����. (���� �и� �� ��������)
	�� time �Լ��� �� ������ ���� ������ �����ϱ� ������ ���е��� ������ �� �ۿ� ����.
�� OS�� ���������� ������ �Ѵ�.
*/
#include <chrono>

#include <random>
#include <vector>
#include <map>

/*
unordered_map : Hash �ڷᱸ��
�� �Ϲ��� ��Ȳ���� map���� �˻��ӵ��� �� ������.
�� �˻� �ӵ��� ���� ������ �ߺ��� �����͸� ������� �ʱ� �����̴�.
	��, ���� �����Ͱ� ���� �� (key), �ؽ� �浹�� �߻��� ������ ����� ������ ���� ���ϰ� �߻��Ѵ�.
*/
#include <unordered_map>

// cassert : C++ ���α׷����� ��� -> �� ����
#include <cassert>

// bool�ٴٸ� ������ �� �ִ�.
// bitset : ��Ʈ ������ �� �� ���� ������ �ִ� �Լ��� �����ϴ� STL
// �� reset(), set(), flip(), all(), any(), size() ���..
#include <bitset>

using namespace std;

using std::vector;
using std::map;
using std::unordered_map;
using std::bitset;

/*
// ! D2D/D3D ��� ���� ============================================================================================================
#include <D2D1.h>
#include <d2d1helper.h>
#include <d3dx9.h>
#include <D3DX11.h>
#include <d3d11shader.h>
#include <dinput.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

ID2D1Factory*				_ID2DFactory = nullptr;
ID2D1HwndRenderTarget*		_ID2DRenderTarget = nullptr;
*/

// # ����� ���� ��� ���� #
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"


// # �̱��� #
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()

// # ��ũ�� # (������ â �ʱ�ȭ)
#define WINNAME				(LPTSTR)(TEXT("WindowsAPI"))
#define WINSTART_X			400
#define WINSTART_Y			100
#define WINSIZE_X			1280
#define WINSIZE_Y			800

// WS_CAPTION : Ÿ��Ʋ�ٸ� ������ ���� �ɼ�
// WS_SYSMENU : ���� ǥ���ٿ� ��Ʈ�� �޴� ���� â
#define WINSTYLE			WS_CAPTION | WS_SYSMENU

// # ��ũ�� �Լ� # (Ŭ�������� �����Ҵ�� �κ� ����)
// ��ũ�� �Լ��� 2�� �̻� �������� \�� ����ϸ� �ȴ�.
#define SAFE_DELETE(p)			{if(p) {delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

// # ���� ���� # (������ ����)
// extern Ű����� �ٸ� ��� / cpp���� ������ �����ؼ� ���� ���� ����Ѵ�.
// �� ��ü�� �����ϱ� ���� ����ϸ� �� ����.
// �⺻������ ���� ������ Ű���带 �����ص� �⺻������ externȭ �Ǵ� ��찡 ����.
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
// X ��ǥ�� Y ��ǥ�� ����� ��ǥ�� ������ �� ����� �Ѵ�.
extern POINT			_ptMouse;
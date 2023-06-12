#pragma once

// 4005라는 경고를 무시하겠다.
#pragma warning(disable : 4005)
// 4005 : DXGI 등 그래픽 인터페이스에서 매크로 관련하여 출력되는 경고
//#include "targetver.h" 

/*
▶ Stdafx

- MS의 비쥬얼 스튜디오를 이용하여 프로젝트를 만들면 생성되는 클래스이다.
	ㄴ 이 친구가 의미하는 바는 표준 어플리케이션 프레임워크의 틀

- MS에서 개발자들의 능률 향상을 위해 만들어둔 PCH 파일
	ㄴ 자주 쓰이는 여러가지 헤더들은 미리 컴파일 해두어 이후 다시 컴파일하지 않고 사용하게 된다.

- 개발에 초기 구축 단계에서는 필요성을 못느끼지만 헤더 파일의 크기가 커지거나 양이 많아 질수록 활용도 및 효율이 급상승한다.
*/

// SDKDDKVER.h는 프로그램에서 지원할 OS 혹은 라이브러리에 따라 Windows 헤더에서 코드가 포함될 함수 / 상수 등을 제어하는데 사용 한다.
#include <SDKDDKVER.h>


// 거의 사용되지 않는 내용은 Windows 헤더에서 제외
// ㄴ GDI+를 사용하려면 헤더파일에서 꺼내와야 한다.
//#include <ole2.h>
#define WIN32_LEAN_AND_MEAN

//! Windows 헤더 파일 ============================================================================================================
#include <Windows.h>

//! C 런타임 헤더 파일 ============================================================================================================
// stdlib : C언어의 표준 라이브러리 함수의 헤더 파일
#include <stdlib.h>

// C언에서 메모리 할당할때 사욯한다.
#include <malloc.h>

// 메모리 관련 헤더 파일 
// ㄴ memset / memcpy를 사용하는 헤더파일 (지금은 Windows.h 정의하면 접근가능)
#include <memory.h>

/*
▶ 문자열 셋

- 윈도우에서 사용할 문자열 출력 파일(문자) 셋 (TextOut, DrawText, wsprintf 등등)
 ㄴ 기본적으로 유니코드기반

MBCS (멀티 바이트 캐릭터 셋)

- 기존에 사용하던 멀티바이트 형태의 문자열을 뜻한다.
- 멀티바이트 코드는 영어 같은 아스키 코드에 포함되는 문자는 1바이트로 표현되고 포함되지 않는 문자는 2바이트로 처리한다.


WBCS (와이드 바이트 캐릭터 셋)

- 모든 문자를 2바이트로 처리하며 유니코드 기반이다.
*/
#include <tchar.h>

// stdio : 표준 입출력 헤더 파일
#include <stdio.h>


//! C++ 런타임 헤더 파일 ============================================================================================================
#include <iostream>

/*
- C++11에서 추가된 시간 관련 라이브러리 (STL)
ㄴ 기존 C 런타임에서 제공하는 time 함수보다 다양하고 확장된 기능을 지원한다.
ㄴ 장점 : 정밀도가 높다. (나노 밀리 초 단위까지)
	ㄴ time 함수는 초 단위의 값만 측정이 가능하기 때문에 정밀도가 떨어질 수 밖에 없다.
ㄴ OS와 독립적으로 동작을 한다.
*/
#include <chrono>

#include <random>
#include <vector>
#include <map>

/*
unordered_map : Hash 자료구조
ㄴ 일반적 상황에서 map보다 검색속도가 더 빠르다.
ㄴ 검색 속도가 빠른 이유는 중복된 데이터를 허용하지 않기 때문이다.
	단, 유사 데이터가 많을 시 (key), 해쉬 충돌이 발생할 여지가 생기기 때문에 성능 저하가 발생한다.
*/
#include <unordered_map>

// cassert : C++ 프로그래머의 희망 -> 잘 쓰면
#include <cassert>

/*
// ! D2D/D3D 헤더 파일 ============================================================================================================
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

#include "CommonMacroFunction.h"
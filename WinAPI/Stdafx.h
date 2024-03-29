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

// 디버깅 콘솔창
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// ! 라이브러리 추가 ============================================================================================================
#pragma comment (lib, "msimg32.lib")
//#pragma comment(lib, "gdiplus")
#pragma comment(lib, "./lib/FMOD/fmodex64_vc.lib")
#pragma comment(lib, "./JsonCpp/lib_json/json_vc71_libmtd.lib")

//! Windows 헤더 파일 ============================================================================================================
#include <Windows.h>

// ! 외부 헤더 파일 ===============================================================================================================
#include "./inc/FMOD/fmod.hpp"
#include "JsonCpp/include/json/json.h"

//! C 런타임 헤더 파일 ============================================================================================================
// stdlib : C언어의 표준 라이브러리 함수의 헤더 파일
#include <stdlib.h>

// C언에서 메모리 할당할때 사욯한다.
#include <malloc.h>

// 메모리 관련 헤더 파일 
// ㄴ memset / memcpy를 사용하는 헤더파일 (지금은 Windows.h 정의하면 접근가능)
#include <memory.h>
#include <time.h>

/*
▶ 문자열 셋

- 윈도우에서 사용할 문자열 출력 파일(문자) 셋 (TextOut, DrawText, wsprintf 등등)
 ㄴ 기본적으로 유니코드기반

MBCS (멀티 바이트 캐릭터 셋)

- 기존에 사용하던 멀티바이트 형태의 문자열을 뜻한다.
- 멀티바이트 코드는 영어 같은 아스키 코드에 포함되는 문자는 1바이트로 표현되고 포함되지 않는 문자는 2바이트로 처리한다.


WBCS (와이드 바이트 캐릭터 셋)

- 모든 문자를 2바이트로 처리하며 유니코드 기반이다.


▶ 유니코드와 멀티바이트의 사용

- VS에서는 개발시 어떤 문자셋(멀티 바이트, 유니코드)을 사용할지 지정을 해줘야 한다.

- 유니코드인 경우에는 문자열을 따옴표로 감싸고 그 앞에 L을 붙여서 (L"")이라고 표기해야 한다.

- 멀티바이트 같은 경우에는 그냥 ""만 사용하면 된다.

- 유니코드로 개발된 프로그램을 멀티바이트로 이식하려면 이들 문자열의 표현 방식을 다시 고쳐줘야 하기 때문에 매우 불편하다.
	ㄴ 그래서 _T 매크로를 사용해야 한다.

- 문자열을 따옴표로 감싸고 유니코드에서 사용한 "L"대신 "_T"를 사용하면 매크로가 알아서 개발 환경에 맞게 치환해 준다.
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
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <memory>

// 람다 친구들
#include <algorithm>

// 함수 포인터를 변수처럼 주고 받을 수 있다.
// ㄴ bind : 특정 인자에 대해서만 함수를 실행시키고 싶을 때 / 특정 인자와 특정 함수를 묶어 버릴 때
// ㄴ 함수 포인터 -> 이벤트 -> 트리거 -> 델리게이트 -> 액션 트리거 / 관찰자 패턴
#include <functional>
#include <fstream>

/*
unordered_map : Hash 자료구조
ㄴ 일반적 상황에서 map보다 검색속도가 더 빠르다.
ㄴ 검색 속도가 빠른 이유는 중복된 데이터를 허용하지 않기 때문이다.
	단, 유사 데이터가 많을 시 (key), 해쉬 충돌이 발생할 여지가 생기기 때문에 성능 저하가 발생한다.
*/
#include <unordered_map>

// cassert : C++ 프로그래머의 희망 -> 잘 쓰면
#include <cassert>

// bool바다를 억제할 수 있다.
// bitset : 비트 연산을 좀 더 쉽게 관리해 주는 함수를 지원하는 STL
// ㄴ reset(), set(), flip(), all(), any(), size() 등등..
#include <bitset>

using namespace std;

using std::vector;
using std::map;
using std::unordered_map;
using std::bitset;
using std::queue;
using std::deque;

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

// # 사용자 정의 헤더 파일 #
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TempSoundManager.h"
#include "INIData.h"
#include "JsonSaveLoader.h"
#include "Utils.h"
#include "EventManager.h"

using namespace MY_UTIL;

// # 싱글톤 #
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define FONTMANAGER	FontManager::getSingleton()
#define TIMEMANAGER TimeManager::getSingleton()
#define SCENEMANAGER SceneManager::getSingleton()
#define SOUNDMANAGER SoundManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()
#define INIDATAMANAGER INIData::getSingleton()
#define JSONDATAMANAGER JsonSaveLoader::getSingleton()
#define EVENTMANAGER EventManager::getSingleton()

// ! 타이틀
#define WINNAME				(LPTSTR)(TEXT("WindowsAPI"))

// ! 전체 화면
//#define FULLSCREEN

#ifdef FULLSCREEN
#define WINSTART_X		0
#define WINSTART_Y		0
//GetSystemMetrics() : 인자로 전달되는 시스템 설정 정보를 반환
// ㄴ SM_CXSCREEN + SM_CYSCREEN = 현재 화면 해상도 X / Y 축 반환
#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)  
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE

#else
// # 매크로 # (윈도우 창 초기화)
#define WINSTART_X			400
#define WINSTART_Y			100
#define WINSIZE_X			1280
#define WINSIZE_Y			800
#define WINSIZE_X_HALF		WINSIZE_X / 2
#define WINSIZE_Y_HALF		WINSIZE_Y / 2

// WS_CAPTION : 타이틀바를 가지기 위한 옵션
// WS_SYSMENU : 제목 표시줄에 컨트롤 메뉴 상자 창
#define WINSTYLE			WS_CAPTION | WS_SYSMENU
#endif


// # 매크로 함수 # (클래스에서 동적할당된 부분 해제)
// 매크로 함수가 2줄 이상 내려갈때 \를 사용하면 된다.
#define SAFE_DELETE(p)			{if(p) {delete(p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}
#define SAFE_RELEASE_SCENE(p)	{if(p) {(p)->release(); (p) = nullptr;}}


// # 전역 변수 # (데이터 영역)
// extern 키워드는 다른 헤더 / cpp에서 변수를 공유해서 쓰기 위해 사용한다.
// ㄴ 객체를 공유하기 위해 사용하면 더 좋다.
// 기본적으로 전역 변수는 키워드를 생략해도 기본적으로 extern화 되는 경우가 많다.
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
// X 좌표와 Y 좌표를 평면의 좌표에 정의할 때 사용을 한다.
extern POINT			_ptMouse;
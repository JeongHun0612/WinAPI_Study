#pragma once
#include "SingletonBase.h"

#pragma region (FMOD + 트릭스터 + 베터리 엔진)
/*
▶ FMOD

- 사운드 엔진 라이브러리
ㄴ 사운드 관련 엔진이기 때문에 일반적으로 사용되는 대부분의 음원 확장자는 
	전부 지원한다고 보면 될것이고 추가로 다양한 플랫폼까지 지원을 한다.

ㆍ 사용 이유?
ㄴ WinAPI / DirectX 같은 경우에도 자체 사운드 라이브러리를 가지고 있지만 가공이 필요한 경우가 많아 불편하다.
	(또한 별도 스레드로 분리되면서 이전 보다 활용빈도가 더 좋아졌다.)


▷ 상용 엔진

- 언리얼 + 유니티에서는 라이센스 계약으로 기본 내장
ㄴ 그렇기 때문에 무료인 경우가 많고 출시를 목표로 할때만 라이센스를 필요로 한다.

- 언리얼 엔진은 기본적으로 너무 무겁기 때문에 라이센스를 통한 내장(기본 플래그쉽)만 되어 있다. -> 플러그인 추가
ㄴ EX: .bank


- 유니티 내장 사운드는 기본적으로 FMOD를 사용하지만 대신 모든 기능에 대한 것은 아니다.
ㄴ 그렇기 때문에 추가 기능을 사용하기 위해서는 추가 에셋을 설치해야 한다.
ㄴ EX: .bank


- 이외의 대부분의 플랫폼에서는 사용하기 위한 선행 처리가 필요하다.
ㄴ 헤더, 클래스, 이름 공간, 라이브러리 링크 -> 파일..?


※ FMOD를 이용한 대표적인 게임들
ㄴ 던파, 와우, 바이오 쇼크 시리즈, 디제이 맥스 리스팩트 V 등등 많이 있다.


▷ FMOD 구성

- 크게 3가지로 나뉜다.
ㄴ 라이브러리 + 프로그램

1. FMOD Ex
ㄴ StudioAPI / Core API
ㄴ Low Level 사운드 엔진 (주로 네이티브 언언에서 채용되는 API)
ㄴ API 형태로 되어 있기 때문에 다른 라이브러리 대비 가볍고 빠르다. (장점)
ㄴ 하지만 코딩을 못하면 전혀 쓸 수가 없다. (단점)
ㄴ 주로 일반적인 음악 포맷을 사용한다면 선택이 되고 또한 디자이너가 없을때도 선택이 되는 경우가 많다. (wav, mp3, mid)

==============================================

2. FMOD 이벤트 시스템
ㄴ Ex의 상위 레이어 -> 디자이너가 작업한 사운드 컨텐츠를 재생하는 Data 기반 Driven API
ㄴ 디자이너의 능력에 따른 결과물에 따라 불필요한 코드가 대부분 사라지고 이는 곧 성능 향상으로 이어진다.

ㄴ 특히 디자이너에 의한 사운드 파트에서 튜닝이 가능해 지기 때문에 
	프로그래머가 전혀 사운드 관련해서 전혀 신경을 쓰지 않아도 된다. (개발 속도 ↑)


3. FMOD 디자이너
ㄴ 사운드 이벤트를 만들어 내는 툴
ㄴ 기획 + 설계 + 방향성 단계에서 FMOD가 채택이 되면 사운드 디자이너가 주로 사용할꺼다.
	ㄴ 우리가 사용할 툴
ㄴ 상용 엔진을 사용하던 아니면 디자이너가 툴을 사용하던 기본적으로 트랜지션 설계를 할 예정이기 때문에 프로그래머로서는 더욱 편리한 면이 있다.

※ 위에 내용들은 디자이너와 협업 / 우리에게 시킬 여지가 다분하니 충분히 숙지를 해야 한다.


※ FMOD 포함해서 외부 기능은 대부분 라이브러를 통해 해당 플랫폼과 커스텀 되기 때문에 
	외부 라이브러를 사용하기 위해서는 라이브러리에 대한 이해가 필요하다.

- 라이브러리 종류 (동적 라이브러리, 정적 라이브러리)
ㄴ 정적 라이브러리는 프로젝트에 내부적으로 심어져있다. 
ㄴ 장점) 찾을 필요가 없어서 빠르다. 
ㄴ 단점) 내부적으로 심어놨기 때문에 메모리를 사용한다.

ㄴ 동적 라이브러리는 필요할때마다 가져와서 사용한다. (Ex. .dll 파일)
ㄴ 장점) 필요할때만 가져오기 때문에 메모리를 필요에 의해서만 사용한다.
ㄴ 단점) 복잡한 형태를 띄고 있으면 찾는데 오래 걸린다.

ㄴ 이 라이브러리에 해당하는 기능을 통해 연산을 할 것이냐 안 할것이냐에 따라 동적 / 정적 상태
ㄴ 연산을 하면 정적 O 
ㄴ 동적 라이브러리를 찾는데도 오래걸리는데 연산까지하면 더 오래걸린다.

*/

#pragma endregion

// 사운드 갯수
constexpr auto soundBuffer = 10;

// 여분의 채널 갯수 (버퍼)
constexpr auto extraSoundChannel = 5;

// 총 사운드 갯수
constexpr auto totalSoundChannel = soundBuffer + extraSoundChannel;

using namespace FMOD;

class SoundManager : public SingletonBase<SoundManager>
{
private:
	// FMOD는 캡슐화가 되어 있기 때문에 FMOD의 객체에 직접적으로 접근해서 데이터를 오염시키면 안된다.
	// *를 하나만 사용하면 FMOD 라이브러리에 직접 접근
	// FMOD가 라이브러리를 인터페이스화 시켜놨고 **로 접근이 가능

	typedef map<string, Sound**> arrSounds;
	typedef map<string, Sound**>::iterator arrSoundsIter;

	typedef map<string, Channel**> arrChannels;
	typedef map<string, Channel**>::iterator arrChannelsIter;

	// System : 코어 API
	System* _system;
	Sound** _sound;
	Channel** _channel;
	
	arrSounds _mTotalSounds;

public:
	HRESULT init(void);
	void release(void);
	void update(void);

	void addSound(string keyName, string soundName, bool background, bool loop);

	void play(string keyName, float volume);
	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);

	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);

	SoundManager();
	~SoundManager() {}
};


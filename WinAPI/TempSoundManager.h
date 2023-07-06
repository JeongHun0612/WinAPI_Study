#pragma once
#include "SingletonBase.h"

// 윈도우 내장 라이브러리 (재생)
// 시간 / 사운드 -> PlayeSound()
#include <mmsystem.h>

// 장치관리자에 접근하기 위한 컨트롤 인터페이스
// mciSendString()이라는 함수를 사용하기 위해 사용
#include <mciapi.h>

#pragma comment(lib, "Winmm.lib")

class TempSoundManager : public SingletonBase <TempSoundManager>
{
private:

public:
	HRESULT init();

	// 사운드 파일 추가 (MP3, WAV)
	void addMp3FileWithKey(string key, string fileName);
	void addWaveFileWithKey(string key, string fileName);

	// 효과음
	void playEffectSSoundWave(char* fileName);

	// 재생
	void playSoundWithKey(string key);

	// 정지
	void stopMp3WithKey(string key);


	TempSoundManager() {}
	~TempSoundManager() {}
};


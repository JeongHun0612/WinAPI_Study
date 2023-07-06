#pragma once
#include "SingletonBase.h"

// ������ ���� ���̺귯�� (���)
// �ð� / ���� -> PlayeSound()
#include <mmsystem.h>

// ��ġ�����ڿ� �����ϱ� ���� ��Ʈ�� �������̽�
// mciSendString()�̶�� �Լ��� ����ϱ� ���� ���
#include <mciapi.h>

#pragma comment(lib, "Winmm.lib")

class TempSoundManager : public SingletonBase <TempSoundManager>
{
private:

public:
	HRESULT init();

	// ���� ���� �߰� (MP3, WAV)
	void addMp3FileWithKey(string key, string fileName);
	void addWaveFileWithKey(string key, string fileName);

	// ȿ����
	void playEffectSSoundWave(char* fileName);

	// ���
	void playSoundWithKey(string key);

	// ����
	void stopMp3WithKey(string key);


	TempSoundManager() {}
	~TempSoundManager() {}
};


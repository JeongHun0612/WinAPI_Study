#include "Stdafx.h"
#include "Example_TempSound.h"

HRESULT Example_TempSound::init(void)
{
    TEMPSOUNDMANAGER->addMp3FileWithKey("lobby", "Resources/Sounds/sound_lobby.mp3");

    return S_OK;
}

void Example_TempSound::update(void)
{
    if(KEYMANAGER->isOnceKeyDown('P'))
    {
        TEMPSOUNDMANAGER->playSoundWithKey("lobby");
        cout << "lobby Sound 재생" << endl;
    }
    if (KEYMANAGER->isOnceKeyDown('A'))
    {
        TEMPSOUNDMANAGER->playEffectSSoundWave("Resources/Sounds/attack.mp3");
        cout << "attack Sound 재생" << endl;
    }
}

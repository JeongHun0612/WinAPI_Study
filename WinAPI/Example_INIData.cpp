#include "Stdafx.h"
#include "Example_INIData.h"

HRESULT Example_INIData::init(void)
{
    INIDATAMANAGER->addData("옵션", "밝기", "50");
    INIDATAMANAGER->addData("옵션", "해상도", "100");
    INIDATAMANAGER->addData("옵션", "배경음량", "100");
    INIDATAMANAGER->addData("옵션", "효과음음량", "100");
    INIDATAMANAGER->addData("옵션", "FPS", "60");

    INIDATAMANAGER->iniSave("100팀");

    return S_OK;
}

void Example_INIData::release(void)
{
}

void Example_INIData::update(void)
{
    if (KEYMANAGER->isOnceKeyDown('0'))
    {
        int test = INIDATAMANAGER->loadDataInteger("100팀", "용석", "무서움");
    }
}

void Example_INIData::render(void)
{
}

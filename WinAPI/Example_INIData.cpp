#include "Stdafx.h"
#include "Example_INIData.h"

HRESULT Example_INIData::init(void)
{
    INIDATAMANAGER->addData("¿É¼Ç", "¹à±â", "¹à±â");
    INIDATAMANAGER->addData("¿É¼Ç", "ÇØ»óµµ", "100");
    INIDATAMANAGER->addData("¿É¼Ç", "¹è°æÀ½·®", "100");
    INIDATAMANAGER->addData("¿É¼Ç", "È¿°úÀ½À½·®", "100");
    INIDATAMANAGER->addData("¿É¼Ç", "FPS", "60");

    INIDATAMANAGER->iniSave("100ÆÀ");

    return S_OK;
}

void Example_INIData::release(void)
{
}

void Example_INIData::update(void)
{
    if (KEYMANAGER->isOnceKeyDown('0'))
    {
        int testInt = INIDATAMANAGER->loadDataInteger("100ÆÀ", "¿É¼Ç", "¹à±â");
        string testString = INIDATAMANAGER->loadDataString("100ÆÀ", "¿É¼Ç", "¹à±â");

        cout << testInt << endl;
        cout << testString << endl;
    }
}

void Example_INIData::render(void)
{
}

#include "Stdafx.h"
#include "Example_INIData.h"

HRESULT Example_INIData::init(void)
{
    INIDATAMANAGER->addData("�ɼ�", "���", "���");
    INIDATAMANAGER->addData("�ɼ�", "�ػ�", "100");
    INIDATAMANAGER->addData("�ɼ�", "�������", "100");
    INIDATAMANAGER->addData("�ɼ�", "ȿ��������", "100");
    INIDATAMANAGER->addData("�ɼ�", "FPS", "60");

    INIDATAMANAGER->iniSave("100��");

    return S_OK;
}

void Example_INIData::release(void)
{
}

void Example_INIData::update(void)
{
    if (KEYMANAGER->isOnceKeyDown('0'))
    {
        int testInt = INIDATAMANAGER->loadDataInteger("100��", "�ɼ�", "���");
        string testString = INIDATAMANAGER->loadDataString("100��", "�ɼ�", "���");

        cout << testInt << endl;
        cout << testString << endl;
    }
}

void Example_INIData::render(void)
{
}

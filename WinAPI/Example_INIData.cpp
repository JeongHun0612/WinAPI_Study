#include "Stdafx.h"
#include "Example_INIData.h"

HRESULT Example_INIData::init(void)
{
    INIDATAMANAGER->addData("�ɼ�", "���", "50");
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
        int test = INIDATAMANAGER->loadDataInteger("100��", "�뼮", "������");
    }
}

void Example_INIData::render(void)
{
}

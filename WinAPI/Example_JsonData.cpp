#include "Stdafx.h"
#include "Example_JsonData.h"

HRESULT Example_JsonData::init(void)
{
	_questSample = new QuestSample;
	_questSample->init();

	return S_OK;
}

void Example_JsonData::release(void)
{
	// !Do Nothing
}

void Example_JsonData::update(void)
{
	// !Do Nothing
}

void Example_JsonData::render(void)
{
	questPopUp();
}

void Example_JsonData::questPopUp()
{
	char str[256];
	queue<Quest*>* temp = _questSample->getQuest();
	Quest* node = temp->front();

	sprintf_s(str, "%s", node->getName().c_str());
	TextOut(getMemDC(), 200, 150, str, strlen(str));

	sprintf_s(str, "개요 : %s", node->getDescription().c_str());
	TextOut(getMemDC(), 200, 200, str, strlen(str));

	sprintf_s(str, "몬스터 이름 : %s", node->getMonstreName().c_str());
	TextOut(getMemDC(), 200, 250, str, strlen(str));

	sprintf_s(str, "처치해야 할 몬스터 : %d", node->getMoster());
	TextOut(getMemDC(), 200, 300, str, strlen(str));

	sprintf_s(str, "퀘스트 스테이지 : %s", node->getQuestStage().c_str());
	TextOut(getMemDC(), 200, 350, str, strlen(str));

	sprintf_s(str, "퀘스트 체크 : %s", node->getQuestCheck().c_str());
	TextOut(getMemDC(), 200, 400, str, strlen(str));

	sprintf_s(str, "보상 경험치 : %d", node->getExp());
	TextOut(getMemDC(), 200, 450, str, strlen(str));

	sprintf_s(str, "보상 아이템 : %s", node->getItem().c_str());
	TextOut(getMemDC(), 200, 500, str, strlen(str));

	sprintf_s(str, "보상 골드 : %d Gold", node->getGold());
	TextOut(getMemDC(), 200, 550, str, strlen(str));
}

void Example_JsonData::currentQuest()
{
}

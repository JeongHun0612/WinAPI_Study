#include "Stdafx.h"
#include "Quest.h"

void Quest::init(string name, int gold, int exp, int monster, string description, string item, string questCheck, string monsterName, string questStage)
{
	_name = name;
	_gold = gold;
	_exp = exp;
	_monster = monster;
	_description = description;
	_item = item;
	_questCheck = questCheck;
	_monstreName = monsterName;
	_questStage = questStage;
}
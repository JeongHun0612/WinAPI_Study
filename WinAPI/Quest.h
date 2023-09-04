#pragma once

enum QUEST_TYPE
{
	QUEST_STATE_1
};

struct MyStruct
{
	// 1. 구조체

};

class Quest
{
protected:
	int _exp;
	int _gold;
	int _monster;
	
	string _name;
	string _description;
	string _item;
	string _questCheck;
	string _monstreName;
	string _questStage;

	QUEST_TYPE _questType;

public:
	void init(string name, int gold, int exp, int monster, string description, string item, string questCheck, string monsterName, string questStage);

	// 2. 참조 형태
	int getGold() { return this->_gold; }
	int getExp() { return this->_exp; }
	int getMoster() { return this->_monster; }

	string getName() { return this->_name; }
	string getItem() { return this->_item; }
	string getDescription() { return this->_description; }
	string getQuestCheck() { return this->_questCheck; }
	string getMonstreName() { return this->_monstreName; }
	string getQuestStage() { return this->_questStage; }
};


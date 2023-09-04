#pragma once
#include "Quest.h"

#pragma region ť
/*
�� ť (Queue)

- ť�� ����Ʈ�� �������� ���ð� �ٸ��� FIFO �ڷᱸ��

- ������ �Ͼ�� ���� ��(back), ������ �Ͼ�� ���� ��(front)�̶�� �Ѵ�.

�� ����Ʈ ť / CPU �����ٸ� / ���� (������) / BFS / DFS � ���� ä��ȴ�.


�� ť���� ���� ����ϴ� ��� �Լ�

- front() - ù��° ��� ����

- back() - ������ ��� ����

- push() - ������ ����

- size() - ũ�� ��ȯ

- empty() - ��Ұ� �������
*/
#pragma endregion

class QuestSample
{
private:
	queue<Quest*> _quest;

public:
	void init(void);

	void questSetup(Quest* pQuest = nullptr);

	queue<Quest*>* getQuest() { return &this->_quest; }

	QuestSample() {}
	~QuestSample() {}
};


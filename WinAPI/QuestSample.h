#pragma once
#include "Quest.h"

#pragma region 큐
/*
▶ 큐 (Queue)

- 큐는 리스트의 일종으로 스택과 다르게 FIFO 자료구조

- 삽입이 일어나는 쪽을 뒤(back), 삭제가 일어나는 쪽을 앞(front)이라고 한다.

※ 프린트 큐 / CPU 스케줄링 / 버퍼 (데이터) / BFS / DFS 등에 자주 채용된다.


▷ 큐에서 자주 사용하는 멤버 함수

- front() - 첫번째 요소 접근

- back() - 마지막 요소 접근

- push() - 데이터 삽입

- size() - 크기 반환

- empty() - 요소가 비었는지
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


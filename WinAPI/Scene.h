#pragma once

//class SceneManager;

class Scene
{
	// 정보은닉을 허무는 키워드
	// 사용하기전 정말 friend 키워드를 써야만 했는지 확실한 확신이 필요
	// 최하위 클래스가 최상위 클래스를 접근해서 데이터를 바꿨을 때 중간에 있는 클래스들에게 어떠한 일이 발생할지 모름
	// friend는 단방향이 기본
	// private도 접근이 가능함

	/*
	friend : 말 그대로 친구
	ㄴ 복잡한 상속 구조에서 또는 효율적인 구조를 설계할 때 많이 사용한다.
	*/

	//friend SceneManager;

private:
	// 인터페이스 클래스에서 스텍에 올라가는 함수를 선언하는 이러한 행위가 가능하다. (공존)
	void init(int a);

	virtual void init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void exit() = 0;

protected:

public:

	Scene();
	virtual ~Scene();
};
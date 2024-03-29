#pragma once
#include "SingletonBase.h"

// 객체지향 전환 -> 설계 방식 / 방법론

#define	KEY_MAX	256

class KeyManager : public SingletonBase <KeyManager>
{
private:
	//BOOL _keyUp[KEY_MAX];
	//BOOL _keyDown[KEY_MAX];

	bitset<KEY_MAX> _keyUp;
	bitset<KEY_MAX> _keyDown;

public:
	// 초기화
	HRESULT init(void);
	
	bool isOnceKeyDown(int key);	// 키가 한번만 눌렸는지
	bool isOnceKeyUp(int key);		// 한번 누르고 띄었는지
	bool isStayKeyDown(int key);	// 키가 계속 눌려 있는지
	bool isToggleKey(int key);		// 토글키
	bool isAnyKeyDown();			// 아무 키나 눌렀을 때

	bitset<KEY_MAX> getKeyUp(void) { return _keyUp; }
	bitset<KEY_MAX> getKeyDown(void) { return _keyDown; }

	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }
	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }

	KeyManager() {}
	~KeyManager() {}
};


#pragma once
#include "GameNode.h"

enum class BUTTON_STATE : int
{
	NORMAL,
	HOVER,
	PUSH,
	DISABLE
};

class Animation;

class Button : public GameNode
{
public:
	// 함수 포인터를 이용한 방식
	//typedef void(*ButtonCallBack)(void);
	typedef function<void(void)> ButtonCallBack;

private:
	ButtonCallBack _onClick;
	ButtonCallBack _onHover;

	BUTTON_STATE _state;

	GImage* _image;
	Animation* _anim;

	string _text;

	float _x, _y;

	int _frameX;
	int _frameY;

	RECT _rc;

public:
	// 이미지가 없는 버튼
	HRESULT init(string text, float x, float y, int width, int height,
		BUTTON_STATE state = BUTTON_STATE::NORMAL, ButtonCallBack onClick = nullptr, ButtonCallBack onHover = nullptr);

	// 이미지가 있는 버튼
	HRESULT init(string imageName, float x, float y,
		BUTTON_STATE state = BUTTON_STATE::NORMAL, ButtonCallBack onClick = nullptr, ButtonCallBack onHover = nullptr);

	// 이미지 애니메이션 버튼
	HRESULT init(string imageName, Animation* anim, float x, float y,
		BUTTON_STATE state = BUTTON_STATE::NORMAL, ButtonCallBack onClick = nullptr, ButtonCallBack onHover = nullptr);

	void release(void);
	void update(void);
	void render(void);


	// 마우스 클릭 이벤트 등록
	void setOnClick(ButtonCallBack callback) { _onClick = callback; }

	// 마우스 오버 이벤트 등록
	void setOnMouseOver(ButtonCallBack callback) { _onHover = callback; }


	// 콜백 함수
	void CALLBACK callBackFunc(ButtonCallBack);


	// ===============
	// 인라인 함수
	// ===============
	BUTTON_STATE getState(void) { return _state; }


	Button() : _onClick(nullptr), _onHover(nullptr), _anim(nullptr) {}
	~Button() {}
};
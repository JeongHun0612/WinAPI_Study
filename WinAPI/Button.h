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
	// �Լ� �����͸� �̿��� ���
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
	// �̹����� ���� ��ư
	HRESULT init(string text, float x, float y, int width, int height,
		BUTTON_STATE state = BUTTON_STATE::NORMAL, ButtonCallBack onClick = nullptr, ButtonCallBack onHover = nullptr);

	// �̹����� �ִ� ��ư
	HRESULT init(string imageName, float x, float y,
		BUTTON_STATE state = BUTTON_STATE::NORMAL, ButtonCallBack onClick = nullptr, ButtonCallBack onHover = nullptr);

	// �̹��� �ִϸ��̼� ��ư
	HRESULT init(string imageName, Animation* anim, float x, float y,
		BUTTON_STATE state = BUTTON_STATE::NORMAL, ButtonCallBack onClick = nullptr, ButtonCallBack onHover = nullptr);

	void release(void);
	void update(void);
	void render(void);


	// ���콺 Ŭ�� �̺�Ʈ ���
	void setOnClick(ButtonCallBack callback) { _onClick = callback; }

	// ���콺 ���� �̺�Ʈ ���
	void setOnMouseOver(ButtonCallBack callback) { _onHover = callback; }


	// �ݹ� �Լ�
	void CALLBACK callBackFunc(ButtonCallBack);


	// ===============
	// �ζ��� �Լ�
	// ===============
	BUTTON_STATE getState(void) { return _state; }


	Button() : _onClick(nullptr), _onHover(nullptr), _anim(nullptr) {}
	~Button() {}
};
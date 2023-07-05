#pragma once
#include "GameNode.h"

class MainGame : public GameNode
{
private:
	GameNode* _titleScene;
	GameNode* _gameScene;

	bool _isTitle;

	//StartScene* _start;
	//SecondScene* _second;
	//GameNode* _currentScene;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() : _titleScene(nullptr) {}
	~MainGame() {}
};
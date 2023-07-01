#pragma once
#include "GameNode.h"

class MainGame : public GameNode
{
private:
	GameNode* _titleScene;
	GameNode* _currentScene;

	bool _isTitle;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	MainGame() {}
	~MainGame() {}
};
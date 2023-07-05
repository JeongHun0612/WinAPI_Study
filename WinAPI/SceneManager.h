#pragma once
#include "SingletonBase.h"

class GameNode;

static GameNode* _currentScene = NULL;

class SceneManager : public SingletonBase<SceneManager>
{
private:
	typedef map<int, GameNode*>			 mapSceneList;
	typedef map<int, GameNode*>::iterator mapSceneIter;

private:
	mapSceneList _mSceneList;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	GameNode* addScene(int idxKey, GameNode* scene);
	GameNode* changeScene(int idxKey);

	SceneManager() {}
	~SceneManager() {}
};


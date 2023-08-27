#pragma once
#include "SingletonBase.h"

class GameNode;

static GameNode* _currentScene = NULL;

class SceneManager : public SingletonBase<SceneManager>
{
private:
	typedef map<int, GameNode*>			 mapSceneList;
	typedef map<int, GameNode*>::iterator mapSceneIter;

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

//#pragma once
//#include "SingletonBase.h"
//
//class GameNode;
//class Scene;
//
//class SceneManager : public SingletonBase<SceneManager>
//{
//	friend class SingletonBase<SceneManager>;
//
//private:
//
//public:
//
//	SceneManager() {}
//	~SceneManager() {}
//};
//
//#define SCENEMANAGER SceneManager::getSingleton()


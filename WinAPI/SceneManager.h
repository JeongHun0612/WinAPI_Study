#pragma once
#include "SingletonBase.h"

class GameNode;
//class Scene;

class SceneManager : public SingletonBase<SceneManager>
{
	//friend class SingletonBase<SceneManager>;
public:
	//typedef map<string, GameNode*> mapSceneList;
	//typedef map<string, GameNode*>::iterator mapSceneIter;

	typedef vector<pair<string, GameNode*>> vSceneList;
	typedef vector<pair<string, GameNode*>>::iterator vSceneIter;

private:
	static GameNode* _currentScene;
	static GameNode* _loadingScene;
	static GameNode* _readyScene;
	
	//mapSceneList _mSceneList;
	//mapSceneList _mLoadingSceneList;

	vSceneList _vSceneList;
	vSceneList _vLoadingSceneList;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	GameNode* addScene(string sceneName, GameNode* scene);
	GameNode* addLoadingScene(string loadingSceneName, GameNode* scene);

	HRESULT changeScene(string sceneName);
	bool findScene(string sceneName);

	vector<pair<string, GameNode*>> getSceneLiset(void) { return _vSceneList; }

	// LPVOID : void ∆˜¿Œ≈Õ
	friend DWORD CALLBACK loadingThread(LPVOID prc);

	SceneManager() {}
	~SceneManager() {}
};

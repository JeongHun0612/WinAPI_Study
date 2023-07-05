#include "Stdafx.h"
#include "SceneManager.h"
#include "GameNode.h"

HRESULT SceneManager::init()
{
	_currentScene = NULL;

	return S_OK;
}

void SceneManager::release()
{
	auto iter = _mSceneList.begin();

	for (; iter != _mSceneList.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mSceneList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	_mSceneList.clear();
}

void SceneManager::update()
{
	if (_currentScene)
	{
		_currentScene->update();
	}
}

void SceneManager::render()
{
	if (_currentScene)
	{
		_currentScene->render();
	}
}

GameNode* SceneManager::addScene(int idxKey, GameNode* scene)
{
	//if (FAILED(scene->init()))
	//{
	//	SAFE_DELETE(scene);
	//	return NULL;
	//}

	_mSceneList.insert(make_pair(idxKey, scene));

	return scene;
}

GameNode* SceneManager::changeScene(int idxKey)
{
	auto key = _mSceneList.find(idxKey);

	// 검색한 키를 찾지 못한 경우
	if (key == _mSceneList.end()) return NULL;

	// 검색한 씬의 초기화가 실패할 경우
	if (FAILED(key->second->init()))
	{
		SAFE_DELETE(key->second);
		return NULL;
	}

	// 변경하려는 씬이 현재 씬과 동일한 경우
	if (key->second == _currentScene) return NULL;

	// 현재 씬이 비어있지 않다면 release() 함수 실행
	if (_currentScene)
	{
		_currentScene->release();
	}

	// 씬 변경
	_currentScene = key->second;

	return _currentScene;
}

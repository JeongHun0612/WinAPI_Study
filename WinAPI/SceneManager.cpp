#include "Stdafx.h"
#include "SceneManager.h"
#include "GameNode.h"
//#include "Scene.h"

//GameNode* SceneManager::changeScene(int idxKey)
//{
//	auto key = _mSceneList.find(idxKey);
//
//	// 검색한 키를 찾지 못한 경우
//	if (key == _mSceneList.end()) return NULL;
//
//	// 검색한 씬의 초기화가 실패할 경우
//	if (FAILED(key->second->init()))
//	{
//		SAFE_DELETE(key->second);
//		return NULL;
//	}
//
//	// 변경하려는 씬이 현재 씬과 동일한 경우
//	if (key->second == _currentScene) return NULL;
//
//	// 현재 씬이 비어있지 않다면 release() 함수 실행
//	if (_currentScene)
//	{
//		_currentScene->release();
//	}
//
//	// 씬 변경
//	_currentScene = key->second;
//
//	return _currentScene;
//}

// 초기화'만' 진행 -> 호출 여부에 관계없이
GameNode* SceneManager::_currentScene = nullptr;
GameNode* SceneManager::_loadingScene = nullptr;
GameNode* SceneManager::_readyScene = nullptr;

DWORD CALLBACK loadingThread(LPVOID prc)
{
	// 교체될 씬의 함수 실행
	SceneManager::_readyScene->init();

	// 현재 씬을 교체될 씬으로 변경
	SceneManager::_currentScene = SceneManager::_readyScene;


	// 로딩 씬 해제
	SceneManager::_loadingScene->release();
	SceneManager::_loadingScene = nullptr;
	SceneManager::_readyScene = nullptr;

	return 0;
}

HRESULT SceneManager::init(void)
{
	_currentScene = nullptr;
	_loadingScene = nullptr;
	_readyScene = nullptr;

	return S_OK;
}

void SceneManager::release(void)
{
	// 보기에 좋고 간결하고 문제도 없어 보인다.
	// ㄴ C / C++ 언어에서는 싫어하는 형태
	// ㄴ 연산이 필요 없는 로직에서 사용
	//for each (auto scene in _vSceneList)
	//{
	//	SAFE_DELETE(scene.second);
	//}

	vSceneIter viSceneList = _vSceneList.begin();

	for (; viSceneList != _vSceneList.end();)
	{
		if (viSceneList->second != nullptr)
		{
			if (viSceneList->second == _currentScene)
			{
				viSceneList->second->release();
			}

			SAFE_DELETE(viSceneList->second);
			viSceneList = _vSceneList.erase(viSceneList);
		}

		else ++viSceneList;
	}

	_vSceneList.clear();

	// 조금 더 간결하게 표현한 방법 (범위 기반 for문)
	//for (auto scene : _vSceneList)
	//{
	//	if (scene.second != nullptr)
	//	{
	//		if (scene.second == _currentScene)
	//		{
	//			scene.second->release();
	//		}

	//		SAFE_DELETE(scene.second);
	//	}
	//}
	//_vSceneList.clear();
}

void SceneManager::update(void)
{
	if (_currentScene) _currentScene->update();
}

void SceneManager::render(void)
{
	if (_currentScene) _currentScene->render();
}

GameNode* SceneManager::addScene(string sceneName, GameNode* scene)
{
	if (!scene) return nullptr;

	_vSceneList.push_back(make_pair(sceneName, scene));

	return scene;
}

GameNode* SceneManager::addLoadingScene(string loadingSceneName, GameNode* scene)
{
	if (!scene) return nullptr;

	_vLoadingSceneList.push_back(make_pair(loadingSceneName, scene));

	return scene;
}

HRESULT SceneManager::changeScene(string sceneName)
{
	vSceneIter iter = _vSceneList.begin();

	for (; iter != _vSceneList.end(); ++iter)
	{
		if (iter->first == sceneName)
		{
			if (iter->second == nullptr) return E_FAIL;
			if (iter->second == _currentScene) return S_OK;

			if (SUCCEEDED(iter->second->init()))
			{
				_currentScene = iter->second;

				return S_OK;
			}
		}
	}
}

bool SceneManager::findScene(string sceneName)
{
	vSceneIter iter = _vSceneList.begin();

	for (; iter != _vSceneList.end(); ++iter)
	{
		if (iter->first == sceneName)
		{
			if (iter->second == _currentScene) return false;

			return true;
		}
	}

	return false;
}

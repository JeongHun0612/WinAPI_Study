#include "Stdafx.h"
#include "SceneManager.h"
#include "GameNode.h"
//#include "Scene.h"

//GameNode* SceneManager::changeScene(int idxKey)
//{
//	auto key = _mSceneList.find(idxKey);
//
//	// �˻��� Ű�� ã�� ���� ���
//	if (key == _mSceneList.end()) return NULL;
//
//	// �˻��� ���� �ʱ�ȭ�� ������ ���
//	if (FAILED(key->second->init()))
//	{
//		SAFE_DELETE(key->second);
//		return NULL;
//	}
//
//	// �����Ϸ��� ���� ���� ���� ������ ���
//	if (key->second == _currentScene) return NULL;
//
//	// ���� ���� ������� �ʴٸ� release() �Լ� ����
//	if (_currentScene)
//	{
//		_currentScene->release();
//	}
//
//	// �� ����
//	_currentScene = key->second;
//
//	return _currentScene;
//}

// �ʱ�ȭ'��' ���� -> ȣ�� ���ο� �������
GameNode* SceneManager::_currentScene = nullptr;
GameNode* SceneManager::_loadingScene = nullptr;
GameNode* SceneManager::_readyScene = nullptr;

DWORD CALLBACK loadingThread(LPVOID prc)
{
	// ��ü�� ���� �Լ� ����
	SceneManager::_readyScene->init();

	// ���� ���� ��ü�� ������ ����
	SceneManager::_currentScene = SceneManager::_readyScene;


	// �ε� �� ����
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
	// ���⿡ ���� �����ϰ� ������ ���� ���δ�.
	// �� C / C++ ������ �Ⱦ��ϴ� ����
	// �� ������ �ʿ� ���� �������� ���
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

	// ���� �� �����ϰ� ǥ���� ��� (���� ��� for��)
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

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

	// �˻��� Ű�� ã�� ���� ���
	if (key == _mSceneList.end()) return NULL;

	// �˻��� ���� �ʱ�ȭ�� ������ ���
	if (FAILED(key->second->init()))
	{
		SAFE_DELETE(key->second);
		return NULL;
	}

	// �����Ϸ��� ���� ���� ���� ������ ���
	if (key->second == _currentScene) return NULL;

	// ���� ���� ������� �ʴٸ� release() �Լ� ����
	if (_currentScene)
	{
		_currentScene->release();
	}

	// �� ����
	_currentScene = key->second;

	return _currentScene;
}

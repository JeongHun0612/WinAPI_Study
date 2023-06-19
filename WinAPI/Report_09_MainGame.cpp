#include "Stdafx.h"
#include "Report_09_MainGame.h"

HRESULT Report_09_MainGame::init(void)
{
	GameNode::init();

	return S_OK;
}

void Report_09_MainGame::release(void)
{
	GameNode::release();
}

void Report_09_MainGame::update(void)
{
	GameNode::update();

	_count++;
	_time++;

	if (_count % 50 == 0)
	{
		_count = 0;

		DDong _DDong;
		_DDong._posX = RND->getInt(600);
		_DDong._posY = 0;
		_list.push_back(_DDong);
	}

	//for (auto i = _list.begin(); i != _list.end(); ++i)
	//{
	//	if (i->_posY > 600)
	//	{
	//		_list.erase(_list.begin(), i);
	//	}
	//	else
	//	{
	//		i->_posY += 5;
	//	}
	//}

	for (_iter = _list.begin(); _iter != _list.end(); ++_iter)
	{
		_iter->_posY += 5;

		if (_iter->_posY > 800)
		{
			_list.erase(_iter);
			//_list.erase(_iter);
		}
	}
}

void Report_09_MainGame::render(HDC hdc)
{
	/*for (STData stData : ValueList)
	{
		printf("구조체 데이터 : %d, %s\n", stData.m_nValue, stData.m_oString.c_str());
	}

	for (auto oIterator = ValueList.begin(); oIterator != ValueList.end(); ++oIterator)
	{
		int nIndex = oIterator - ValueList.begin();

		printf("%d 번째 구조체 데이터 : %d, %s\n", nIndex + 1, oIterator->m_nValue, oIterator->m_oString.c_str());
	}

	for (auto _iter = _list.begin(); _iter != _list.end(); _iter++)
	{
	}*/

	for (_iter = _list.begin(); _iter != _list.end(); _iter++)
	{
		RectangleMake(hdc, _iter->_posX, _iter->_posY, _iter->_width, _iter->_height);
	}
}

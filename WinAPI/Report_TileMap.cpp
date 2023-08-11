#include "Stdafx.h"
#include "Report_TileMap.h"

/*
���� 1. �� ��Ʈ�������� ���� ���� ���� �ӹ�

- ���� �ĺ��� 3��(2��)

���� 2. Ÿ�ϸ� �����

- ����ڰ� �Է��� ���ڷ� Ÿ�ϸ��� �׸���. (�ִ� ������ : 100)
�� EX : 20�� �Է��ϸ� 20 X 20 �������� Ÿ���� ȭ�鿡 �׷�����.

- Ÿ�ϸʾȿ��� ������ ��ġ�� �̹��� 2���� ����.

- �̹����� �Ź� Ÿ�ϸ��� ���� �׷��ٶ����� ��ġ�� �ٲ��� �ϰ� �׷��� �̹����� ���콺�� Ŭ���� �� ������ ��ġ ���� ������ �� �־�� �Ѵ�.

�ʼ� : STL ����
*/

HRESULT Report_TileMap::init(void)
{
	_tileCount = 10;

	_sizeX = (WINSIZE_Y / _tileCount);
	_sizeY = (WINSIZE_Y / _tileCount);

	_image = IMAGEMANAGER->addImage("tileImage", "Resources/Images/Object/Mole.bmp", _sizeX, _sizeY);

	_rndTileNum[0] = RND->getInt(_tileCount * _tileCount);
	_rndTileNum[1] = RND->getInt(_tileCount * _tileCount);

	for (int i = 0; i < _tileCount; i++)
	{
		for (int j = 0; j < _tileCount; j++)
		{
			Tile tile;
			tile.y = i * _sizeY;
			tile.x = j * _sizeX;
			tile.rc = RectMake(tile.x, tile.y, _sizeX, _sizeY);

			_vTiles.push_back(tile);
		}
	}

	return S_OK;
}

void Report_TileMap::release(void)
{
	_vTiles.clear();
}

void Report_TileMap::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (_viTiles = _vTiles.begin(); _viTiles != _vTiles.end(); ++_viTiles)
		{
			if(PtInRect(&_viTiles->rc, _ptMouse))
			{
				printf("[%d, %d]\n", _viTiles->y, _viTiles->x);
			}
		}
	}
}

void Report_TileMap::render(void)
{
	for (int i = 0; i < _vTiles.size(); i++)
	{
		DrawRectMake(getMemDC(), _vTiles[i].rc);

		if (i == _rndTileNum[0] || i == _rndTileNum[1])
		{
			_image->render(getMemDC(), _vTiles[i].x, _vTiles[i].y);
		}
	}
}

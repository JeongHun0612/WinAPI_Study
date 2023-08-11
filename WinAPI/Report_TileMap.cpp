#include "Stdafx.h"
#include "Report_TileMap.h"

/*
과제 1. 팀 포트폴리오로 만들 게임 선정 임박

- 최종 후보군 3개(2개)

과제 2. 타일맵 만들기

- 사용자가 입력한 숫자로 타일맵을 그린다. (최대 사이즈 : 100)
ㄴ EX : 20을 입력하면 20 X 20 사이즈의 타일이 화면에 그려진다.

- 타일맵안에는 랜덤한 위치에 이미지 2장이 들어간다.

- 이미지는 매번 타일맵을 새로 그려줄때마다 위치가 바껴야 하고 그려진 이미지는 마우스로 클릭할 수 있으며 위치 또한 변경할 수 있어야 한다.

필수 : STL 벡터
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

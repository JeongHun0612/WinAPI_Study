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
	_isDrag = false;
	_isTextBox = true;

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
			if (PtInRect(&_viTiles->rc, _ptMouse) && _viTiles->img != nullptr)
			{
				_isDrag = true;
				_dragImg = _viTiles->img;
				_viTiles->img = nullptr;

				_diffX = _ptMouse.x - _viTiles->x;
				_diffY = _ptMouse.y - _viTiles->y;

				break;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && _isDrag)
	{
		_isDrag = false;

		for (_viTiles = _vTiles.begin(); _viTiles != _vTiles.end(); ++_viTiles)
		{
			if (PtInRect(&_viTiles->rc, _ptMouse))
			{
				_viTiles->img = _dragImg;
				_dragImg = nullptr;
				break;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_isTextBox = !_isTextBox;
		_strTileCnt = "";
	}


	// 키 입력
	if (KEYMANAGER->isAnyKeyDown() && _isTextBox)
	{
		for (int i = 0; i < KEYMANAGER->getKeyDown().size(); i++)
		{
			if (KEYMANAGER->getKeyDown().test(i))
			{
				// 숫자 입력
				if (i >= 48 && i <= 57)
				{
					_strTileCnt += i;
				}

				// 숫자 입력 (NUMPAD)
				if (i >= VK_NUMPAD0 && i <= VK_NUMPAD9)
				{
					_strTileCnt += i - 48;
				}

				// 숫자 지우기
				if (i == VK_BACK && !_strTileCnt.empty())
				{
					_strTileCnt.pop_back();
				}

				// 숫자 입력 완료
				if (i == VK_RETURN)
				{
					setTile(_vTiles, stoi(_strTileCnt));
					_isTextBox = false;
				}

				break;
			}
		}
	}
}

void Report_TileMap::render(void)
{
	if (_isTextBox)
	{
		RectangleMakeCenter(getMemDC(), WINSIZE_X_HALF, WINSIZE_Y_HALF, 100, 50);

		SetTextAlign(getMemDC(), TA_CENTER);

		TextOut(getMemDC(), WINSIZE_X_HALF, WINSIZE_Y_HALF - 50, "타일 갯수 입력", strlen("타일 갯수 입력"));
		TextOut(getMemDC(), WINSIZE_X_HALF, WINSIZE_Y_HALF - 10, _strTileCnt.c_str(), _strTileCnt.length());
	}
	else
	{
		for (int i = 0; i < _vTiles.size(); i++)
		{
			DrawRectMake(getMemDC(), _vTiles[i].rc);

			if (_vTiles[i].img != nullptr)
			{
				_vTiles[i].img->render(getMemDC(), _vTiles[i].x, _vTiles[i].y);
			}
		}

		if (_isDrag)
		{
			_dragImg->render(getMemDC(), _ptMouse.x - _diffX, _ptMouse.y - _diffY);
		}
	}
}

void Report_TileMap::setRandomNum(int* rndNumArray, int count, int range)
{
	for (int i = 0; i < count; i++)
	{
		rndNumArray[i] = RND->getInt(range);

		for (int j = 0; j < i; j++)
		{
			if (rndNumArray[i] == rndNumArray[j]) i--;
		}
	}
}

void Report_TileMap::setTile(vector<Tile>& vTiles, int tileCnt)
{
	// vecotr 초기화
	vTiles.clear();

	// tileSize 계산
	int tileSize = (WINSIZE_Y / tileCnt);

	// 랜덤 숫자 뽑기
	setRandomNum(_rndTileNum, RND_IMG_CNT, (tileCnt * tileCnt));

	// 타일 초기화
	for (int i = 0; i < tileCnt; i++)
	{
		for (int j = 0; j < tileCnt; j++)
		{
			Tile tile;
			ZeroMemory(&tile, sizeof(Tile));
			tile.y = i * tileSize;
			tile.x = j * tileSize;
			tile.rc = RectMake(tile.x, tile.y, tileSize, tileSize);

			vTiles.push_back(tile);
		}
	}

	 // 타일 이미지 초기화
	for (int i = 0; i < RND_IMG_CNT; i++)
	{
		vTiles[_rndTileNum[i]].img = new GImage;
		vTiles[_rndTileNum[i]].img->init("Resources/Images/Object/Mole.bmp", tileSize, tileSize);
	}
}

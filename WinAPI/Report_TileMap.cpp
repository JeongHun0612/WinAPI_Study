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


	// Ű �Է�
	if (KEYMANAGER->isAnyKeyDown() && _isTextBox)
	{
		for (int i = 0; i < KEYMANAGER->getKeyDown().size(); i++)
		{
			if (KEYMANAGER->getKeyDown().test(i))
			{
				// ���� �Է�
				if (i >= 48 && i <= 57)
				{
					_strTileCnt += i;
				}

				// ���� �Է� (NUMPAD)
				if (i >= VK_NUMPAD0 && i <= VK_NUMPAD9)
				{
					_strTileCnt += i - 48;
				}

				// ���� �����
				if (i == VK_BACK && !_strTileCnt.empty())
				{
					_strTileCnt.pop_back();
				}

				// ���� �Է� �Ϸ�
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

		TextOut(getMemDC(), WINSIZE_X_HALF, WINSIZE_Y_HALF - 50, "Ÿ�� ���� �Է�", strlen("Ÿ�� ���� �Է�"));
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
	// vecotr �ʱ�ȭ
	vTiles.clear();

	// tileSize ���
	int tileSize = (WINSIZE_Y / tileCnt);

	// ���� ���� �̱�
	setRandomNum(_rndTileNum, RND_IMG_CNT, (tileCnt * tileCnt));

	// Ÿ�� �ʱ�ȭ
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

	 // Ÿ�� �̹��� �ʱ�ȭ
	for (int i = 0; i < RND_IMG_CNT; i++)
	{
		vTiles[_rndTileNum[i]].img = new GImage;
		vTiles[_rndTileNum[i]].img->init("Resources/Images/Object/Mole.bmp", tileSize, tileSize);
	}
}

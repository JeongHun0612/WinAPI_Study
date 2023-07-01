#include "Stdafx.h"
#include "Report_Mole_Image.h"

/*
이미지 추가 과제 1. 두더지 게임

- 상황에 맞는 이미지 필수적으로 적용한다.

- 두더지가 없을 때 / 나왔을 때 / 때렸을 때 / 망치 (대기, 때렸을때)

※ 마우스 커서는 ShowCursor()를 이용한다.
*/

HRESULT Report_Mole_Image::init(void)
{
	GameNode::init();

	ShowCursor(false);

	_holeImage = new GImage;
	_holeImage->init("Resources/Images/Object/Hole.bmp", 200, 200, true, RGB(255, 0, 255));

	_moleImage = new GImage;
	_moleImage->init("Resources/Images/Object/Mole.bmp", 200, 200, true, RGB(255, 0, 255));

	_hammerImage = new GImage;
	_hammerImage->init("Resources/Images/Object/Hammer.bmp", 150, 150, true, RGB(255, 0, 255));

	for (int i = 0; i < MAX_MOLE; i++)
	{
		_rc[i] = RectMakeCenter(150 + (250 * (i % 3)), 150 + (250 * (i / 3)), 200, 200);
	}

	_index = 0;
	_count = 0;
	_score = 0;
	_time = RND->getFromIntTo(30, 60);

	_bIsSelected = false;
	_bIsOnceCheck = false;


	return S_OK;
}

void Report_Mole_Image::release(void)
{
	GameNode::release();

	ShowCursor(true);
	SAFE_DELETE(_holeImage);
	SAFE_DELETE(_moleImage);
}

void Report_Mole_Image::update(void)
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		// PtInRect() : 렉트 안에 POINT(x, y)가 있는지 검사하여 포인트가 사각형 안에 있으면 true값을 반환하는 API 함수
		if (PtInRect(&_rc[_index], _ptMouse) && !_bIsOnceCheck)
		{
			_score += 100;
			_bIsOnceCheck = true;
		}
	}

	if (!_bIsSelected)
	{
		_count++;

		if (_count % _time == 0)
		{
			_count = 0;
			_index = RND->getInt(8);
			_bIsSelected = true;
		}
	}
	else
	{
		_count++;

		if (_count % _time == 0)
		{
			_bIsOnceCheck = false;
			_bIsSelected = false;
			_time = RND->getFromIntTo(30, 60);
			_index = 100;
		}
	}
}

void Report_Mole_Image::render(void)
{
	char strScore[128];
	wsprintf(strScore, "Score : %d", _score);
	TextOut(getMemDC(), 10, 10, strScore, strlen(strScore));

	for (int i = 0; i < MAX_MOLE; i++)
	{
		_holeImage->render(getMemDC(), _rc[i].left, _rc[i].top);
	}

	_moleImage->render(getMemDC(), _rc[_index].left, _rc[_index].top);
	_hammerImage->render(getMemDC(), _ptMouse.x - 75, _ptMouse.y - 75);
}

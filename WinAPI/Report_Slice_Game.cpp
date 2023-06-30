#include "Stdafx.h"
#include "Report_Slice_Game.h"

/*
과제 1. 슬라이스 게임

- 치트 필수

- 화면 왼쪽에 원본 사진 출력 < - > 화면 오른쪽에는 9등분된 이미지 출력

- 9등분 된 이미지 제일 아래 오른쪽 칸이 시작 칸

- 퍼즐이 완성되면 알파블렌딩 효과로 이미지가 나타난다.
ㄴ 중앙에서 완성된 이미지를 보여주면 된다.
*/

HRESULT Report_Slice_Game::init(void)
{
	_puzzleImage = new GImage;
	_puzzleImage->init("Resources/Images/BackGround/puzzel_image1.bmp", 600, 600);

	_curPieceIdx = MAX_PIECE - 1;
	_isAnswer = false;

	_count = _alpha = 0;

	for (int i = 0; i < MAX_PIECE; i++)
	{
		_piece[i].rc = RectMake((i % 3) * 200, (i / 3) * 200, 200, 200);
		_piece[i].idx = i;
	}

	// 이미지 번호 셔플
	for (int i = 0; i < MAX_PIECE - 1; i++)
	{
		int temp;

		int dest = RND->getInt(MAX_PIECE - 1);
		int sour = RND->getInt(MAX_PIECE - 1);

		temp = _piece[dest].idx;
		_piece[dest].idx = _piece[sour].idx;
		_piece[sour].idx = temp;
	}

	return S_OK;
}

void Report_Slice_Game::release(void)
{
	SAFE_DELETE(_puzzleImage);
}

void Report_Slice_Game::update(void)
{
	// 키입력 처리
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && _curPieceIdx % 3 != 0)
	{
		swapPiece(_curPieceIdx, _curPieceIdx - 1);
		_curPieceIdx -= 1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && _curPieceIdx % 3 != 2)
	{
		swapPiece(_curPieceIdx, _curPieceIdx + 1);
		_curPieceIdx += 1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _curPieceIdx -3 >= 0)
	{
		swapPiece(_curPieceIdx, _curPieceIdx - 3);
		_curPieceIdx -= 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _curPieceIdx + 3 <= MAX_PIECE - 1)
	{
		swapPiece(_curPieceIdx, _curPieceIdx + 3);
		_curPieceIdx += 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		chit(_piece);
	}


	// 정답 검사
	if (!_isAnswer)
	{
		for (int i = 0; i < MAX_PIECE - 1; i++)
		{
			if (_piece[i].idx > _piece[i + 1].idx) break;

			if (i + 1 == MAX_PIECE - 1)
			{
				_isAnswer = true;
			}
		}
	}

	// 정답 이미지 알파 값 증가
	if (_isAnswer && _alpha < 255)
	{
		_count++;
		if (_count % 3 == 0)
		{
			_alpha += 3;

			if (_alpha > 255) _alpha = 255;
		}
	}
}

void Report_Slice_Game::render(void)
{
	char str[128];

	if (_isAnswer)
	{
		_puzzleImage->alphaRender(getMemDC(), WINSIZE_X / 2 - 300, WINSIZE_Y / 2 - 300, _alpha);
	}
	else
	{
		_puzzleImage->render(getMemDC(), 20, 100);

		for (int i = 0; i < MAX_PIECE; i++)
		{
			if (i == _curPieceIdx) continue;

			_puzzleImage->render(getMemDC(), 660 + _piece[i].rc.left, 100 + _piece[i].rc.top, (_piece[i].idx % 3) * 200, (_piece[i].idx / 3) * 200, 200, 200);

			sprintf_s(str, "%d", _piece[i].idx);
			TextOut(getMemDC(), 660 + _piece[i].rc.left, 100 + _piece[i].rc.top, str, strlen(str));
		}
	}
}

void Report_Slice_Game::swapPiece(int destIdx, int sourIdx)
{
	int temp = _piece[destIdx].idx;
	_piece[destIdx].idx = _piece[sourIdx].idx;
	_piece[sourIdx].idx = temp;
}

void Report_Slice_Game::chit(tagPiece* pieces)
{
	int temp;
	for (int i = MAX_PIECE - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (_piece[j].idx > _piece[j + 1].idx)
			{
				temp = _piece[j].idx;
				_piece[j].idx = _piece[j + 1].idx;
				_piece[j + 1].idx = temp;
			}
		}
	}

	_curPieceIdx = MAX_PIECE - 2;
	temp = _piece[_curPieceIdx].idx;
	_piece[_curPieceIdx].idx = _piece[_curPieceIdx + 1].idx;
	_piece[_curPieceIdx + 1].idx = temp;
}

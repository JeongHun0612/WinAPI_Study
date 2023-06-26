#pragma once
#include "GameNode.h"

#define MAX_PIECE		9

struct tagPiece
{
	RECT rc;
	int idx;
};

class Report_16_1_MainGame : public GameNode
{
private:
	GImage* _puzzleImage;
	tagPiece _piece[MAX_PIECE];

	int _curPieceIdx;
	bool _isAnswer;

	int _count, _alpha;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	void swapPiece(int destIdx, int sourIdx);
};


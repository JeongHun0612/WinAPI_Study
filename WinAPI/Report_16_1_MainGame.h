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

	int test[5] = { 5, 4, 3, 2 ,1 };

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	void swapPiece(int destIdx, int sourIdx);
	void chit(tagPiece* pieces);
};


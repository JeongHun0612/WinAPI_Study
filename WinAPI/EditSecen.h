#pragma once
#include "GameNode.h"

#define TILE_SIZE 64

class EditSecen : public GameNode
{
private:

public:
	HRESULT init(void);
	void relase(void);
	void update(void);
	void render(HDC hdc);

	EditSecen() {}
	~EditSecen() {}
};
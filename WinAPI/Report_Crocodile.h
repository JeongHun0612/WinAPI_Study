#pragma once
#include "GameNode.h"

class Report_Crocodile : public GameNode
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_Crocodile() {}
	~Report_Crocodile() {}
};


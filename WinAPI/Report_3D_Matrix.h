#pragma once
#include "GameNode.h"

class Report_3D_Matrix : public GameNode
{
private:

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_3D_Matrix() {}
	~Report_3D_Matrix() {}
};


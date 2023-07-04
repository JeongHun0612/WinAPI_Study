#pragma once
#include "GameNode.h"

#define MAX_OBJECT		1000

class Report_Black_Hole : public GameNode
{
public:
	struct Object
	{
		float cx, cy;
		float radius;
		float speed;
		float directionRadian;

		bool isCenter;
	};

private:
	Object _blackHole;
	vector<Object> _vObject;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_Black_Hole() {}
	~Report_Black_Hole() {}
};


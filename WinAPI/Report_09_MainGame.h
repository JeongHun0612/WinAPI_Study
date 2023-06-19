#pragma once
#include "GameNode.h"

struct DDong
{
	int _posX ,_posY;
	int _width = 20;
	int _height = 30;

	float _speed;
};

class Report_09_MainGame : public GameNode
{
private:
	list<DDong> _list;
	list<DDong>::iterator _iter = _list.begin();

	/*vector<DDong> _list;
	vector<DDong>::iterator _iter = _list.begin();*/

	DDong _DDong;

	//vector<DDong> _vDDong[5];

	int _count;
	int _time;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_09_MainGame() {}
	~Report_09_MainGame() {}
};


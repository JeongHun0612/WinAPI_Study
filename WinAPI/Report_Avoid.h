#pragma once
#include "GameNode.h"

struct DDong
{
	RECT rc;
	int _speed;
};

class Report_Avoid : public GameNode
{
private:
	DDong _DDong;
	RECT _Player;
	RECT _RestartBtn;

	vector<DDong> _vDDong;
	vector<DDong>::iterator _iter = _vDDong.begin();

	int _count;
	int _createTime;
	int _gameTime;

	bool _bisDead;
	char strTime[128];

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(HDC hdc);

	Report_Avoid() {}
	~Report_Avoid() {}
};
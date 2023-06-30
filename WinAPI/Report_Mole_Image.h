#pragma once
#include "GameNode.h"

#define MAX_MOLE		9

class Report_Mole_Image : public GameNode
{
private:
	GImage* _holeImage;
	GImage* _moleImage;
	GImage* _hammerImage;

	RECT _rc[MAX_MOLE];
	int _index;				
	int _count;				
	int _time;				
	int _score;				

	bool _bIsSelected;	
	bool _bIsOnceCheck;	


public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_Mole_Image() {}
	~Report_Mole_Image() {}
};


#pragma once

#define MAX_MOLE	9

class Mole
{
private:
	int _nPosX;
	int _nPosY;
	int _nWidth;
	int _nHeight;

	bool _bState;

	RECT _collider;
	clock_t _tLifeCycle;

public:
	Mole();
	Mole(int posX, int posY);
	~Mole();

	void drawMole(HDC hdc);
	bool isPointInRect();

	bool getState() { return _bState; }
	void setState(bool state) { _bState = state; }

	clock_t getLifeCycle() { return _tLifeCycle; }
};


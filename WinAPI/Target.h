#pragma once
class Target
{
private:
	int _nPosX;
	int _nPosY;
	int _nWidth;
	int _nHeight;

	int _nMoveX;
	int _nMoveY;
	float _fSpeed;

	bool _bIsClick;

public:
	Target();
	Target(int posX, int posY, int moveX, float speed);
	~Target();

	void move();
	bool isPointInRect();
	void drawTarget(HDC hdc);

	void setSpeed(float speed) { _fSpeed = speed; }
	void setMoveX(int moveX) { _nMoveX = moveX; }

	int getPosX() { return _nPosX; }
	int getPosY() { return _nPosY; }

	bool getClick() { return _bIsClick; }
	void setClick(bool isClick) { _bIsClick = isClick; }
};


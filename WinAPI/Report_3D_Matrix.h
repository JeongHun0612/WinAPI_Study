#pragma once
#include "GameNode.h"

struct Vec3
{
	float x;
	float y;
	float z;
};

struct Triangle
{
	Vec3 p[3];
};

struct Mesh
{
	vector<Triangle> tris;
};

class Report_3D_Matrix : public GameNode
{
private:
	Mesh _meshCube;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	Report_3D_Matrix() {}
	~Report_3D_Matrix() {}
};
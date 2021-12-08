#pragma once

#include <cstdio>

#define MAX_VTXS 256

class CAdjMatGraph
{
public:
	CAdjMatGraph();

public:
	bool IsFull();
	bool IsEmpty();

	void Reset();
	void InsertVertex(char name);
	void DeleteVertex(int v);
	
	void InsertEdge(int u, int v);
	void DeleteEdge(int u, int v);

	void Display();

public:
	char GetVertex(int i);
	int GetEdge(int i, int j);
	void SetEdge(int i, int j, int val);

protected:
	int mSize;
	char mVertices[MAX_VTXS];
	int mAdjMat[MAX_VTXS][MAX_VTXS];
};


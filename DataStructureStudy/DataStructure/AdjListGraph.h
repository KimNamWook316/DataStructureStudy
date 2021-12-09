#pragma once

#include "GraphNode.h"

#define MAX_VTS 256

class CAdjListGraph
{
public:
	CAdjListGraph();
	virtual ~CAdjListGraph();

public:
	bool IsFull() const;
	bool IsEmpty() const;

	void Reset();

	void InsertVertex(const char v);
	void DeleteVertex(const int i);

	void InsertEdge(const int u, const int v);
	void DeleteEdge(const int u, const int v);

	void Display();
public:
	char GetVetex(const int i)
	{
		return mVertices[i];
	}
protected:
	int mSize;
	char mVertices[MAX_VTS];
	CGraphNode* mAdjNode[MAX_VTS];
};


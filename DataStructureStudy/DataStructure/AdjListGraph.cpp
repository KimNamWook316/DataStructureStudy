#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <sstream>
#include "AdjListGraph.h"

CAdjListGraph::CAdjListGraph()	:
	mSize(0)
{
}

CAdjListGraph::~CAdjListGraph()
{
	Reset();
}

bool CAdjListGraph::IsFull() const
{
	return mSize >= MAX_VTS - 1;
}

bool CAdjListGraph::IsEmpty() const
{
	return mSize == 0;
}

void CAdjListGraph::Reset()
{
	for (int i = 0; i < mSize; ++i)
	{
		if (mAdjNode[i] != nullptr)
		{
			delete mAdjNode[i];
		}
	}
	mSize = 0;
}

void CAdjListGraph::InsertVertex(const char v)
{
	if (IsFull())
	{
		return;
	}

	mVertices[mSize] = v;
	mAdjNode[mSize] = nullptr;
	++mSize;
}

void CAdjListGraph::DeleteVertex(const int i)
{
}

void CAdjListGraph::InsertEdge(const int u, const int v)
{
	mAdjNode[u] = new CGraphNode(v, mAdjNode[u]);
	mAdjNode[v] = new CGraphNode(u, mAdjNode[v]);
}

void CAdjListGraph::DeleteEdge(const int u, const int v)
{
}

void CAdjListGraph::Display()
{
	std::cout << "size : " << mSize << std::endl;
	
	for (int i = 0; i < mSize; ++i)
	{
		std::cout << mVertices[i] << "    "; 
		for (CGraphNode* v = mAdjNode[i]; v != nullptr; v = v->GetLink())
		{
			std::cout << "  " << GetVetex(v->GetID());
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

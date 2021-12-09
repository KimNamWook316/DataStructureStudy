#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <sstream>
#include "AdjMatGraph.h"

CAdjMatGraph::CAdjMatGraph()
{
	Reset();
}

bool CAdjMatGraph::IsFull()
{
	return mSize >= MAX_VTXS - 1;
}

bool CAdjMatGraph::IsEmpty()
{
	return mSize == 0;
}

void CAdjMatGraph::Reset()
{
	mSize = 0;
	for (int i = 0; i < MAX_VTXS; ++i)
	{
		for (int j = 0; j < MAX_VTXS; ++j)
		{
			SetEdge(i, j, 0);
		}
	}
}

void CAdjMatGraph::InsertVertex(char name)
{
	if (IsFull())
	{
		return;
	}

	mVertices[mSize++] = name;
}

void CAdjMatGraph::DeleteVertex(int v)
{

}

void CAdjMatGraph::InsertEdge(int u, int v)
{
	SetEdge(u, v, 1);
	SetEdge(v, u, 1);
}

void CAdjMatGraph::DeleteEdge(int u, int v)
{
}

void CAdjMatGraph::Display()
{
	std::cout << "size : " << mSize << std::endl;

	for (int i = 0; i < mSize; ++i)
	{
		std::cout << GetVertex(i) << " ";
		for (int j = 0; j < mSize; ++j)
		{
			std::cout << GetEdge(i, j);
		}
		std::cout << std::endl;
	}
}

bool CAdjMatGraph::LoadFromFile(const char* fileName)
{
	std::ifstream ifs(fileName);

	if (ifs.fail())
	{
		assert(false);
		return false;
	}

	std::string buf;
	buf.reserve(64);
	std::getline(ifs, buf);

	int size = std::stoi(buf);

	char vertex;
	for (int i = 0; i < size; ++i)
	{
		std::getline(ifs, buf);
		InsertVertex(buf[0]);

		std::string sub = buf.substr(2, size * 2);

		sub.erase(std::remove(sub.begin(), sub.end(), ' '), sub.end());

		for (int j = 0; j < size; ++j)
		{
			if(sub[j] == '1')
			{
				InsertEdge(i, j);
			}
		}
	}

	ifs.close();
	return false;
}

char CAdjMatGraph::GetVertex(int i)
{
	return mVertices[i];
}

int CAdjMatGraph::GetEdge(int i, int j)
{
	return mAdjMat[i][j];
}

void CAdjMatGraph::SetEdge(int i, int j, int val)
{
	mAdjMat[i][j] = val;
}

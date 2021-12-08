#pragma once

#include "HeapNode.h"

#define MAX_ELEMENT 200

class CMinHeap
{
public:
	CMinHeap();
	~CMinHeap();

public:
	void Insert(const int key);
	CHeapNode Remove();
	CHeapNode GetTop();

public:
	bool IsEmpty();
	bool IsFull();
	
	void Display();

private:
	CHeapNode& getParent(const int i);
	CHeapNode& getLeft(const int i);
	CHeapNode& getRight(const int i);

private:
	CHeapNode mArrNode[MAX_ELEMENT];
	int mSize;
};



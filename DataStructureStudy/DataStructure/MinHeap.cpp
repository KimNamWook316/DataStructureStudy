#include <iostream>
#include "MinHeap.h"

CMinHeap::CMinHeap()	:
	mSize(0)
{
}

CMinHeap::~CMinHeap()
{
}

void CMinHeap::Insert(const int key)
{
	if (IsFull())
	{
		return;
	}

	int i = ++mSize;

	while (i != 1 && key < getParent(i).GetKey())
	{
		mArrNode[i] = getParent(i);
		i /= 2;
	}

	mArrNode[i] = key;
}

CHeapNode CMinHeap::Remove()
{
	if (IsEmpty())
	{
		return NULL;
	}

	CHeapNode item = mArrNode[1];
	CHeapNode last = mArrNode[mSize--];

	int parent = 1;
	int child = 2;
	
	while (child <= mSize)
	{
		if (child < mSize && getLeft(parent).GetKey() > getRight(parent).GetKey())
		{
			++child;
		}

		if (last.GetKey() >= mArrNode[child].GetKey())
		{
			break;
		}

		mArrNode[parent] = mArrNode[child];
		parent = child;
		child *= 2;
	}
	mArrNode[parent] = last;
	return item;
}

CHeapNode CMinHeap::GetTop()
{
	return NULL;
}

bool CMinHeap::IsEmpty()
{
	return mSize == 0;
}

bool CMinHeap::IsFull()
{
	return mSize == MAX_ELEMENT - 1;
}

void CMinHeap::Display()
{
	int level = 1;
	for (int i = 1; i <= mSize; ++i)
	{
		if (i == level)
		{
			level *= 2;
			std::cout << '\n';
		}
		mArrNode[i].Display();
	}
	std::cout << "\n" << "======================================================";
}

CHeapNode& CMinHeap::getParent(const int i)
{
	return mArrNode[i / 2];
}

CHeapNode& CMinHeap::getLeft(const int i)
{
	return mArrNode[i * 2];
}

CHeapNode& CMinHeap::getRight(const int i)
{
	return mArrNode[i * 2 + 1];
}
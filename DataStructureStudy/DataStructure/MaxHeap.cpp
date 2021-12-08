#include <iostream>
#include "MaxHeap.h"

CMaxHeap::CMaxHeap()	:
	mSize(0)
{
}

CMaxHeap::~CMaxHeap()
{
}

void CMaxHeap::Insert(const int key)
{
	if (IsFull())
	{
		return;
	}

	int i = ++mSize;

	while (i != 1 && key > getParent(i).GetKey())
	{
		mArrNode[i] = getParent(i);
		i /= 2;
	}

	mArrNode[i] = key;
}

CHeapNode CMaxHeap::Remove()
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
		if (child < mSize && getLeft(parent).GetKey() < getRight(parent).GetKey())
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

CHeapNode CMaxHeap::GetTop()
{
	return NULL;
}

bool CMaxHeap::IsEmpty()
{
	return mSize == 0;
}

bool CMaxHeap::IsFull()
{
	return mSize == MAX_ELEMENT - 1;
}

void CMaxHeap::Display()
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

CHeapNode& CMaxHeap::getParent(const int i)
{
	return mArrNode[i / 2];
}

CHeapNode& CMaxHeap::getLeft(const int i)
{
	return mArrNode[i * 2];
}

CHeapNode& CMaxHeap::getRight(const int i)
{
	return mArrNode[i * 2 + 1];
}

void heapSort(int a[], int n)
{
	CMaxHeap h;
	for (int i = 0; i < n; ++i)
	{
		h.Insert(a[i]);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		a[i] = h.Remove().GetKey();
	}
}
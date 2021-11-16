#include <cstdio>
#include "LinkedList.h"

CLinkedList::CLinkedList()
	: mHead(0)
{
}

CLinkedList::~CLinkedList()
{
	Clear();
}

void CLinkedList::Insert(int pos, CNode* node)
{
	CNode* prev = GetEntry(pos - 1);
	if (nullptr != prev) 
	{
		prev->InsertNext(node);
	}
}

CNode* CLinkedList::Remove(int pos)
{
	CNode* prev = GetEntry(pos - 1);
	return prev->RemoveNext();
}

CNode* CLinkedList::GetEntry(int pos)
{
	CNode* n = &mHead;
	for (int i = -1; i < pos; ++i, n = n->GetLink())
	{
		if (nullptr == n)
		{
			break;
		}
	}
	return n;
}

bool CLinkedList::IsEmpty()
{
	return nullptr == getHead();
}

CNode* CLinkedList::Find(int val)
{
	for (CNode* p = getHead(); p != nullptr; p = p->GetLink())
	{
		if (p->HasData(val))
		{
			return p;
		}
		else
		{
			return nullptr;
		}
	}
}

void CLinkedList::Replace(int pos, CNode* node)
{
	CNode* prev = GetEntry(pos - 1);
	if (nullptr != prev)
	{
		delete prev->RemoveNext();
		prev->InsertNext(node);
	}
}

int CLinkedList::GetSize()
{
	int size = 0;
	for (CNode* p = getHead(); p != nullptr; p = p->GetLink())
	{
		++size;
	}
	return size;
}

void CLinkedList::Display()
{
	printf("[전체 항목 수 = %2d] : ", GetSize());
	for (CNode* p = getHead(); p != nullptr; p = p->GetLink())
	{
		p->Display();
	}
	printf("\n");
}

CNode* CLinkedList::getHead()
{
	return mHead.GetLink();
}

void CLinkedList::Clear()
{
	while (!IsEmpty()) {
		delete Remove(0);
	}
}

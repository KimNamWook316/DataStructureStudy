#include "DblLinkedList.h"

CDblLinkedList::CDblLinkedList()
{
}

CDblLinkedList::~CDblLinkedList()
{
	Clear();
}

bool CDblLinkedList::IsEmpty()
{
	return mHead.GetNextLink() == nullptr;
}

void CDblLinkedList::Insert(int pos, CDoubleNode* node)
{
	CDoubleNode* n = getEntry(pos-1);
	if (n)
	{
		n->InsertNext(node);
	}
}

void CDblLinkedList::Remove(int pos)
{
	CDoubleNode* n = getEntry(pos);
	CDoubleNode* deleted = n->Remove();
	delete deleted;
}

CDoubleNode* CDblLinkedList::Find(int val)
{
	for (CDoubleNode* pNode = getHead(); pNode != nullptr; pNode = pNode->GetNextLink())
	{
		if (pNode->HasData(val))
		{
			return pNode;
		}
	}
	return nullptr;
}

void CDblLinkedList::Replace(int pos, CDoubleNode* node)
{
	Remove(pos);
	Insert(pos, node);
}

int CDblLinkedList::GetSize()
{
	int count = 0;
	for (CDoubleNode* p = getHead(); p != nullptr; p = p->GetNextLink())
	{
		if (nullptr == p)
		{
			break;
		}
		++count;
	}
	return count;
}

void CDblLinkedList::Display()
{
	printf("[이중 연결 리스트 항목 수 : <%2d>] : ", GetSize());
	for (CDoubleNode* p = getHead(); p != nullptr; p = p->GetNextLink())
	{
		p->Display();
	}
	printf("\n");
}

void CDblLinkedList::Clear()
{
	while (!IsEmpty())
	{
		Remove(0);
	}
}

CDoubleNode* CDblLinkedList::getHead()
{
	return mHead.GetNextLink();
}

CDoubleNode* CDblLinkedList::getEntry(int pos)
{
	CDoubleNode* pCurNode = &mHead;
	for (int i = -1; i < pos; ++i, pCurNode = pCurNode->GetNextLink())
	{
		if (pCurNode == nullptr)
		{
			break;
		}
	}
	return pCurNode;
}

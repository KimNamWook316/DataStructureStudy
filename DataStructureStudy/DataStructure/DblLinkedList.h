#pragma once

#include "DoubleNode.h"

class CDblLinkedList
{
public:
	CDblLinkedList();
	~CDblLinkedList();
	bool IsEmpty();
	void Insert(int pos, CDoubleNode* node);
	void Remove(int pos);
	CDoubleNode* Find(int val);
	void Replace(int pos, CDoubleNode* node);
	int GetSize();

	void Display();
	void Clear();

private:
	CDoubleNode* getHead();
	CDoubleNode* getEntry(int pos);

private:
	CDoubleNode mHead;
};


#pragma once

#include "Node.h"

class CLinkedList
{
public:
	CLinkedList();
	~CLinkedList();
	void Insert(int pos, CNode* node);
	CNode* Remove(int pos);
	CNode* GetEntry(int pos);
	bool IsEmpty();
	CNode* Find(int val);
	void Replace(int pos, CNode* node);
	int GetSize();
	void Display();
	void Clear();

private:
	CNode* getHead();
private:
	CNode mHead;
};


#pragma once

#include <cstdio>

class CDoubleNode
{
public:
	CDoubleNode();
	CDoubleNode(int data);
	~CDoubleNode();

	bool HasData(int data);
	CDoubleNode* GetNextLink();
	CDoubleNode* GetPrevLink();
	void SetNextLink(CDoubleNode* node);
	void SetPrevLink(CDoubleNode* node);
	void InsertNext(CDoubleNode* next);
	CDoubleNode* Remove();

	void Display();

private:
	CDoubleNode*	mPrev;
	CDoubleNode*	mNext;
	int				mData;
};


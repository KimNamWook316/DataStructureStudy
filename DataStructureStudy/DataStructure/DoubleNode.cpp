#include "DoubleNode.h"

CDoubleNode::CDoubleNode()
	: mPrev(nullptr)
	, mNext(nullptr)
	, mData(0)
{
}

CDoubleNode::CDoubleNode(int data)
	: mPrev(nullptr)
	, mNext(nullptr)
	, mData(data)
{
}

CDoubleNode::~CDoubleNode()
{
}

bool CDoubleNode::HasData(int data)
{
	return mData == data;
}

CDoubleNode* CDoubleNode::GetNextLink()
{
	return mNext;
}

CDoubleNode* CDoubleNode::GetPrevLink()
{
	return mPrev;
}

void CDoubleNode::SetNextLink(CDoubleNode* node)
{
	mNext = node;
}

void CDoubleNode::SetPrevLink(CDoubleNode* node)
{
	if (nullptr != node)
	{
		mPrev = node;
	}
}

void CDoubleNode::InsertNext(CDoubleNode* node)
{
	CDoubleNode* curNext = GetNextLink();
	mNext = node;
	node->SetPrevLink(this);

	if (curNext)
	{
		node->SetNextLink(curNext);
		curNext->SetPrevLink(node);
	}
}

CDoubleNode* CDoubleNode::Remove()
{
	if (mPrev)
	{
		mPrev->SetNextLink(mNext);
	}
	if (mNext)
	{
		mNext->SetPrevLink(mPrev);
	}
	return this;
}

void CDoubleNode::Display()
{
	printf(" <%2d>", mData);
}

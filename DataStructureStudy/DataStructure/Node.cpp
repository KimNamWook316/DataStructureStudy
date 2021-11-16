#include <cstdio>
#include "Node.h"

CNode::CNode(int val)
	: mData(val)
	, mLink(nullptr)
{
}

CNode* CNode::GetLink()
{
	return mLink;
}

void CNode::SetLink(CNode* next)
{
	mLink = next;
}

void CNode::Display()
{
	printf(" <%2d>", mData);
}

bool CNode::HasData(int val)
{
	return mData == val;
}

void CNode::InsertNext(CNode* node)
{
	if (node != nullptr) 
	{
		node->mLink = mLink;
		mLink = node;
	}
}

CNode* CNode::RemoveNext()
{
	CNode* removed = mLink;
	if (nullptr != mLink) {
		mLink = removed->mLink;
	}
	return removed;
}

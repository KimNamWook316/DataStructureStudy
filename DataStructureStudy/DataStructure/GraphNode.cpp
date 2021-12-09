#include "GraphNode.h"

CGraphNode::CGraphNode(const int id, CGraphNode* link)	:
	mID(id),
	mLink(link)
{
}

CGraphNode::~CGraphNode()
{
	if (mLink != nullptr)
	{
		delete mLink;
	}
}

CGraphNode* CGraphNode::GetLink()
{
	return mLink;
}

void CGraphNode::SetLink(CGraphNode* node)
{
	mLink = node;
}

void CGraphNode::Display()
{
	std::cout << mID;
}

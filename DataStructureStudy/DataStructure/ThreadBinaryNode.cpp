#include "ThreadBinaryNode.h"

CThreadBinaryNode::CThreadBinaryNode(const int data, CThreadBinaryNode* pLeft, CThreadBinaryNode* pRight,
	bool bIsThread = false)	:
	mData(data),
	mpLeft(pLeft),
	mpRight(pRight),
	mbIsThread(bIsThread)
{
}

CThreadBinaryNode::~CThreadBinaryNode()
{
}

void CThreadBinaryNode::SetRight(CThreadBinaryNode* pR)
{
	mpRight = pR;
}

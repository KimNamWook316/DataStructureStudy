#include "BinaryNode.h"

CBinaryNode::CBinaryNode(const int val, CBinaryNode* left, CBinaryNode* right)	:
	mData(val),
	mpLeft(left),
	mpRight(right)
{
}

CBinaryNode::~CBinaryNode()
{
}

void CBinaryNode::SetData(const int data)
{
	mData = data;
}

void CBinaryNode::SetLeft(CBinaryNode* pNode)
{
	mpLeft = pNode;
}

void CBinaryNode::SetRight(CBinaryNode* pNode)
{
	mpRight = pNode;
}

int CBinaryNode::GetData() const
{
	return mData;
}

CBinaryNode* CBinaryNode::GetLeft() const
{
	return mpLeft;
}

CBinaryNode* CBinaryNode::GetRight() const
{
	return mpRight;
}

bool CBinaryNode::IsLeaf()
{
	return ((mpLeft == nullptr) && (mpRight == nullptr));
}

void CBinaryNode::Print()
{
	std::cout << "Data : " << (char)mData << std::endl;
}

void CBinaryNode::PreOrder()
{
	Print();
	if (mpLeft != nullptr)
	{
		mpLeft->PreOrder();
	}
	if (mpRight != nullptr)
	{
		mpRight->PreOrder();
	}
}

void CBinaryNode::InOrder()
{
	if (mpLeft != nullptr)
	{
		mpLeft->InOrder();
	}
	Print();
	if (mpRight != nullptr)
	{
		mpRight->InOrder();
	}
}

void CBinaryNode::PostOrder()
{
	if (mpLeft != nullptr)
	{
		mpLeft->PostOrder();
	}
	if (mpRight != nullptr)
	{
		mpRight->PostOrder();
	}
	Print();
}

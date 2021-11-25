#include <iostream>
#include "ThreadBinaryTree.h"

CThreadBinaryTree::CThreadBinaryTree()	:
	mpRoot(nullptr)
{
}

CThreadBinaryTree::~CThreadBinaryTree()
{
}

void CThreadBinaryTree::SetRoot(CThreadBinaryNode* pNode)
{
	mpRoot = pNode;
}

bool CThreadBinaryTree::IsEmpty()
{
	return mpRoot == nullptr;
}

void CThreadBinaryTree::ThreadInorder()
{
	if (!IsEmpty())
	{
		std::cout << "스레드 이진트리 : ";
		
		CThreadBinaryNode* q = mpRoot;
		while (q->GetLeft())
		{
			q = q->GetLeft();
		}

		do
		{
			std::cout << (char)q->GetData() << " ";
			q = FindSuccessor(q);
		} while (q);
		std::cout << std::endl;
	}
}

CThreadBinaryNode* CThreadBinaryTree::FindSuccessor(CThreadBinaryNode* pNode)
{
	CThreadBinaryNode* q = pNode->GetRight();

	if (q == nullptr || pNode->GetIsThread())
	{
		return q;
	}

	while (q->GetLeft() != nullptr)
	{
		q = q->GetLeft();
	}
	return q;
}

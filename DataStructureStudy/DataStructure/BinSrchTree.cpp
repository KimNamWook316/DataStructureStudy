#include "BinSrchTree.h"

CBinSrchTree::CBinSrchTree()
{
}

CBinSrchTree::~CBinSrchTree()
{
}

CBinaryNode* CBinSrchTree::SearchRecursive(CBinaryNode* pNode, const int key)
{
	if (pNode == nullptr)
	{
		return nullptr;
	}

	if (key == pNode->GetData())
	{
		return pNode;
	}
	else if (key < pNode->GetData())
	{
		SearchRecursive(pNode->GetLeft(), key);
	}
	else
	{
		SearchRecursive(pNode->GetRight(), key);
	}
}

CBinaryNode* CBinSrchTree::Search(const int key)
{
	return nullptr;
}

// Iteration Search
CBinaryNode* CBinSrchTree::Search(CBinaryNode* pNode, const int key)
{
	while (pNode != nullptr)
	{
		if (pNode->GetData() == key)
		{
			return pNode;
		}
		else if (pNode->GetData() < key)
		{
			pNode = pNode->GetLeft();
		}
		else
		{
			pNode = pNode->GetRight();
		}
	}
	return nullptr;
}

void CBinSrchTree::InsertRecursive(CBinaryNode* pRoot, CBinaryNode* pNode)
{
	if (pNode->GetData() == pRoot->GetData())
	{
		return;
	}
	else if (pNode->GetData() < pRoot->GetData())
	{
		if (pRoot->GetLeft() == nullptr)
		{
			pRoot->SetLeft(pNode);
		}
		else
		{
			InsertRecursive(pNode->GetLeft(), pNode);
		}
	}
	else
	{
		if (pRoot->GetRight() == nullptr)
		{
			pRoot->SetRight(pNode);
		}
		else
		{
			InsertRecursive(pRoot->GetRight(), pNode);
		}
	}
}

void CBinSrchTree::Insert(CBinaryNode* pNode)
{
}

void CBinSrchTree::Insert(CBinaryNode* pL, CBinaryNode* pR)
{
}

void CBinSrchTree::Remove(const int data)
{
}

void CBinSrchTree::Remove(CBinaryNode* pParent, CBinaryNode* pNode)
{
	// 단말 노드면
	if (pNode->IsLeaf())
	{
		// 루트 노드인 경우
		if (pParent == nullptr)
		{
			// 빈 트리가 된다.
			mpRoot = nullptr;
		}
		else
		{
			// 지울 노드가 왼쪽 자식일 경우 부모의 왼쪽을 지운다. 
			if (pParent->GetLeft() == pNode)
			{
				pParent->SetLeft(nullptr);
			}
			// 오른쪽인 경우
			else if (pParent->GetRight() == pNode)
			{
				pParent->SetRight(nullptr);
			}
		}
	}
	// 지울 노드에 왼쪽이나 오른쪽 둘  하나에만 자식이 있을 경우
	else if (pNode->GetLeft() == nullptr || pNode->GetRight() == nullptr)
	{
		CBinaryNode* child = (pNode->GetLeft() != nullptr) ? pNode->GetLeft() : pNode->GetRight();

		// 지울 노드가 루트 노드인 경우
		if (pNode == mpRoot)
		{
			// 자식을 루트로 대체한다.
			mpRoot = child;
		}

		else
		{
			// 부모의 오른쪽을 해당 자식으로 대체한다.
			if (pParent->GetLeft() == pNode)
			{
				pParent->SetLeft(child);
			}
			else
			{
				pParent->SetRight(child);
			}
		}
	}
	else
	{
		CBinaryNode* succeedParent = pNode;			  // 계승 노드의 부모 노드
		CBinaryNode* succeedNode = pNode->GetRight(); // 계승 노드

		// 현재 삭제할 노드의 오른쪽 노드에서, 왼쪽 끝까지 간다.
		while (succeedNode->GetLeft() != nullptr)
		{
			succeedParent = succeedNode;
			succeedNode = succeedNode->GetLeft();
		}

		// 계승 노드의 부모의 왼 쪽이 계승 노드이다 -> 왼 쪽으로 한 번 이상 타고 들어갔다.
		if (succeedParent->GetLeft() == succeedNode)
		{
			// 더 이상 계승 노드에 왼쪽이 없다는 의미이므로, 계승 노드에 있는 오른쪽 노드를 계승 부모 노드의 왼 쪽에 직접 연결
			succeedParent->SetLeft(succeedNode->GetRight());
		}

		// while문 한 번도 수행 안 했다 -> 지울 노드의 바로 오른쪽 노드가 계승 노드이다.
		else
		{
			// 지울 노드의 오른쪽 노드와 계승 노드의 오른쪽 노드를 연결함, 계승 노드에 왼 쪽 없음
			succeedParent->SetRight(succeedNode->GetRight());
		}

		// 계승 노드의 데이터를 pNode로 복사함 ( 실제로 지워지는 것은 계승 노드 )
		pNode->SetData(succeedNode->GetData());
		pNode = succeedNode;
	}

	// 동적할당 해제
	delete pNode;
}
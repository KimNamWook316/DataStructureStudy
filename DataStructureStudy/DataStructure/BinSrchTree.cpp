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
	// �ܸ� ����
	if (pNode->IsLeaf())
	{
		// ��Ʈ ����� ���
		if (pParent == nullptr)
		{
			// �� Ʈ���� �ȴ�.
			mpRoot = nullptr;
		}
		else
		{
			// ���� ��尡 ���� �ڽ��� ��� �θ��� ������ �����. 
			if (pParent->GetLeft() == pNode)
			{
				pParent->SetLeft(nullptr);
			}
			// �������� ���
			else if (pParent->GetRight() == pNode)
			{
				pParent->SetRight(nullptr);
			}
		}
	}
	// ���� ��忡 �����̳� ������ ��  �ϳ����� �ڽ��� ���� ���
	else if (pNode->GetLeft() == nullptr || pNode->GetRight() == nullptr)
	{
		CBinaryNode* child = (pNode->GetLeft() != nullptr) ? pNode->GetLeft() : pNode->GetRight();

		// ���� ��尡 ��Ʈ ����� ���
		if (pNode == mpRoot)
		{
			// �ڽ��� ��Ʈ�� ��ü�Ѵ�.
			mpRoot = child;
		}

		else
		{
			// �θ��� �������� �ش� �ڽ����� ��ü�Ѵ�.
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
		CBinaryNode* succeedParent = pNode;			  // ��� ����� �θ� ���
		CBinaryNode* succeedNode = pNode->GetRight(); // ��� ���

		// ���� ������ ����� ������ ��忡��, ���� ������ ����.
		while (succeedNode->GetLeft() != nullptr)
		{
			succeedParent = succeedNode;
			succeedNode = succeedNode->GetLeft();
		}

		// ��� ����� �θ��� �� ���� ��� ����̴� -> �� ������ �� �� �̻� Ÿ�� ����.
		if (succeedParent->GetLeft() == succeedNode)
		{
			// �� �̻� ��� ��忡 ������ ���ٴ� �ǹ��̹Ƿ�, ��� ��忡 �ִ� ������ ��带 ��� �θ� ����� �� �ʿ� ���� ����
			succeedParent->SetLeft(succeedNode->GetRight());
		}

		// while�� �� ���� ���� �� �ߴ� -> ���� ����� �ٷ� ������ ��尡 ��� ����̴�.
		else
		{
			// ���� ����� ������ ���� ��� ����� ������ ��带 ������, ��� ��忡 �� �� ����
			succeedParent->SetRight(succeedNode->GetRight());
		}

		// ��� ����� �����͸� pNode�� ������ ( ������ �������� ���� ��� ��� )
		pNode->SetData(succeedNode->GetData());
		pNode = succeedNode;
	}

	// �����Ҵ� ����
	delete pNode;
}
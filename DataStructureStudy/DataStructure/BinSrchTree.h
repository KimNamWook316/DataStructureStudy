#pragma once

#include "LinkBinaryTree.h"

class CBinSrchTree : public CLinkBinaryTree
{
public:
	CBinSrchTree();
	~CBinSrchTree();

public:
	CBinaryNode* SearchRecursive(CBinaryNode* pNode, const int key);
	CBinaryNode* Search(const int key);
	CBinaryNode* Search(CBinaryNode* pNode, const int key);

	void InsertRecursive(CBinaryNode* pRoot, CBinaryNode* pNode);
	void Insert(CBinaryNode* pNode);

	void Remove(const int data);
	void Remove(CBinaryNode* pParent, CBinaryNode* pNode);
};
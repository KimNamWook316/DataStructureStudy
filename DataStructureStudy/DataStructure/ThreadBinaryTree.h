#pragma once

#include "ThreadBinaryNode.h"

class CThreadBinaryTree
{
public:
	CThreadBinaryTree();
	~CThreadBinaryTree();

public:
	void SetRoot(CThreadBinaryNode* pNode);
	bool IsEmpty();
	void ThreadInorder();
	CThreadBinaryNode* FindSuccessor(CThreadBinaryNode* pNode);

private:
	CThreadBinaryNode* mpRoot;
};


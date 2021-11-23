#pragma once

#include "BinaryNode.h"

class CLinkBinaryTree
{
public:
	CLinkBinaryTree();
	~CLinkBinaryTree();

public:
	void SetRoot(class CBinaryNode* node);
	class CBinaryNode* GetRoot();
	bool IsEmpty();

	void InOrder();
	void PreOrder();
	void PostOrder();
	void LevelOrder();

	int GetCount();
	int GetHeight();
	int GetLeafCount();

protected:

private:
	class CBinaryNode* mpRoot;
};


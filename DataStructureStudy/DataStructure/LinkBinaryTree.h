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

	// 수식 트리 계산
	int Caculate();

protected:
	int getCount(class CBinaryNode* node);
	int getLeafCount(class CBinaryNode* node);
	int getHeight(class CBinaryNode* node);
	int calculate(class CBinaryNode* node);

protected:
	class CBinaryNode* mpRoot;
};


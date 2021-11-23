#pragma once

#include <iostream>

class CBinaryNode
{
public:
	CBinaryNode(const int val = 0, CBinaryNode* left = nullptr, CBinaryNode* right = nullptr);
	~CBinaryNode();

public:
	void SetData(const int data);
	void SetLeft(CBinaryNode* pNode);
	void SetRight(CBinaryNode* pNode);

	int GetData() const;
	CBinaryNode* GetLeft() const;
	CBinaryNode* GetRight() const;
	bool IsLeaf();
	void Print();

	void PreOrder();
	void InOrder();
	void PostOrder();

protected:
	int mData;
	CBinaryNode* mpLeft;
	CBinaryNode* mpRight;
};


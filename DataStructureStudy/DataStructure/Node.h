#pragma once
class CNode
{
private:
	CNode*	mLink;
	int		mData;

public:
	CNode(int val = 0);
	CNode* GetLink();
	void SetLink(CNode* next);
	void Display();

	bool HasData(int val);
	void InsertNext(CNode* node);
	CNode* RemoveNext();
};


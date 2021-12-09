#pragma once

#include <iostream>

class CGraphNode
{
public:
	CGraphNode(const int id, CGraphNode* link = nullptr);
	~CGraphNode();

public:
	CGraphNode* GetLink();
	void SetLink(CGraphNode* node);
	int GetID() const
	{
		return mID;
	}
public:
	void Display();
	
private:
	int mID;
	CGraphNode* mLink;
};


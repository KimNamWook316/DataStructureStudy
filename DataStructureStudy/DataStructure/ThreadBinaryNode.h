#pragma once
class CThreadBinaryNode
{
public:
	CThreadBinaryNode(const int data, CThreadBinaryNode* pLeft, CThreadBinaryNode* pRight, bool bIsThread);
	~CThreadBinaryNode();

	int GetData() const
	{
		return mData;
	}

	bool GetIsThread() const
	{
		return mbIsThread;
	}

	void SetRight(CThreadBinaryNode* pR);
	
	CThreadBinaryNode* GetLeft()
	{
		return mpLeft;
	}
	
	CThreadBinaryNode* GetRight()
	{
		return mpRight;
	}

private:
	bool mbIsThread;
	int mData;
	CThreadBinaryNode* mpLeft;
	CThreadBinaryNode* mpRight;
};


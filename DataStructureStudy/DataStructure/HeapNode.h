#pragma once

class CHeapNode
{
public:
	CHeapNode();
	CHeapNode(const int key);
	
public:
	void Display();

public:
	void SetKey(const int key)
	{
		mKey = key;
	}

	int GetKey()
	{
		return mKey;
	}

private:
	int mKey;
};


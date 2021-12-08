#include <iostream>
#include "HeapNode.h"

CHeapNode::CHeapNode()
{
}

CHeapNode::CHeapNode(const int key)	:
	mKey(key)
{
}

void CHeapNode::Display()
{
	std::cout << " " << mKey;
}

#pragma once
#include "LocationNode.h"
class LocationStack {
public:
	explicit LocationStack();
	~LocationStack();

	void Push(LocationNode* loc);
	LocationNode* Pop();
	LocationNode* Peek();

	bool IsEmpty();

private:
	LocationNode* mTop;
};


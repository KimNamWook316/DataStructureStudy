#pragma once
#define MAX_QUEUE_SIZE 20
#include <cstdio>
#include <cstdlib>
#include "Customer.h"

inline void error(const char* str) {
	printf(str);
	exit(1);
}

class CustomerQueue {
public:
	explicit CustomerQueue();
	virtual ~CustomerQueue();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(const Customer& val);
	const Customer& Dequeue();
	const Customer& Peek();
protected:
	int mFront;
	int mRear;
	Customer mData[MAX_QUEUE_SIZE];
};

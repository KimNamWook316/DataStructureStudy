#include "CustomerQueue.h"

CustomerQueue::CustomerQueue() 
	: mFront(0)
	, mRear(0) {
}

CustomerQueue::~CustomerQueue()
{
}

bool CustomerQueue::IsEmpty()
{
	return mFront == mRear;
}

bool CustomerQueue::IsFull()
{
	return (1 == (mFront + MAX_QUEUE_SIZE) - mRear);
}

void CustomerQueue::Enqueue(const Customer & val)
{
	if (IsFull()) {
		error("Queue Overflow");
	}
	int Idx = (mRear + 1) % MAX_QUEUE_SIZE;
	mData[++mRear] = val;
}

const Customer & CustomerQueue::Dequeue()
{
	if (IsEmpty()) {
		error("Queue Underflow");
	}
	int Idx = (mFront + 1) % MAX_QUEUE_SIZE;
	return mData[++mFront];
}

const Customer & CustomerQueue::Peek()
{
	if (IsEmpty()) {
		error("Queue Underflow");
	}
	int temp = (mFront + 1) % MAX_QUEUE_SIZE;
	return mData[temp];
}

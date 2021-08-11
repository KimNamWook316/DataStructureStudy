#include <cstdio>
#include <cstdlib>
#include "CircularQueue.h"

CircularQueue::CircularQueue()
	: mFront(0)
	, mRear(0){
}

CircularQueue::~CircularQueue(){
}

bool CircularQueue::IsEmpty()
{
	return mFront == mRear;
}

bool CircularQueue::IsFull()
{
	return (1 == (mFront + MAX_QUEUE_SIZE) - mRear);
}

void CircularQueue::Enqueue(const int & val){
	if (IsFull()) {
		error("Queue Overflow");
	}
	int Idx = (mRear + 1) % MAX_QUEUE_SIZE;
	mData[++mRear] = val;
}

const int & CircularQueue::Dequeue(){
	if (IsEmpty()) {
		error("Queue Underflow");
	}
	int Idx = (mFront + 1) % MAX_QUEUE_SIZE;
	return mData[++mFront];
}

const int & CircularQueue::Peek(){
	if (IsEmpty()) {
		error("Queue Underflow");
	}
	int temp = (mFront + 1) % MAX_QUEUE_SIZE;
	return mData[temp];
}

void CircularQueue::Display() const {
	printf("Queue Elements : ");
	int maxIdx = (mFront < mRear) ? mRear : mRear + MAX_QUEUE_SIZE;
	for (int i = mFront + 1; i <= maxIdx; ++i) {
		printf("[%2d]", mData[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
}

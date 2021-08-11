#include "CircularDeque.h"

CircularDeque::CircularDeque() :
	CircularQueue(){
}

CircularDeque::~CircularDeque(){
}

void CircularDeque::AddFront(const int & val){
	if (IsFull()) {
		error("Queue Overflow");
	}
	mData[mFront] = val;
	mFront = (mFront == 0) ? MAX_QUEUE_SIZE - 1 : mFront - 1;
}

void CircularDeque::AddRear(const int & val){
	Enqueue(val);
}

const int & CircularDeque::DeleteFront(){
	return Dequeue();
}

const int & CircularDeque::DeleteRear(){
	if (IsEmpty()) {
		error("Queue Underflow");
	}
	mRear = (mRear == 0) ? MAX_QUEUE_SIZE - 1 : mRear - 1;
	return mData[mRear];
}

const int & CircularDeque::GetFront(){
	return Peek();
}

const int & CircularDeque::GetRear(){
	int idx = (mRear == 0) ? MAX_QUEUE_SIZE - 1 : mRear - 1;
	return mData[idx];
}

void CircularDeque::Display() const{
	printf("Deque elements : ");
	int maxIdx = (mFront < mRear) ? mRear : mRear + MAX_QUEUE_SIZE;
	for (int i = mFront + 1; i <= maxIdx; ++i) {
		printf("[%2d]", mData[i % MAX_QUEUE_SIZE]);
	}
	printf("\n");
}


#include "OperandStack.h"

OperandStack::OperandStack() : mTop(-1) {
}

void OperandStack::Push(const double & e) {
	if (IsFull()) 
		error("stack overflow");
	mData[++mTop] = e;
}

double OperandStack::Pop(){
	if (IsEmpty())
		error("stack underflow");
	return mData[mTop--];
}

bool OperandStack::IsEmpty() const {
	return (-1 == mTop);
}

bool OperandStack::IsFull() const {
	return (MAX_SIZE_STACK - 1 == mTop);
}

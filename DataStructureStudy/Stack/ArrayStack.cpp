#include "ArrayStack.h"

inline void error(const char* message){
    printf("%s\n", message);
    exit(1);
}

ArrayStack::ArrayStack() : mTop(-1) {};

void ArrayStack::Push(const int& item){
    if(IsFull()){
        error("Stack Overflow");
        return;
    }
    mData[++mTop] = item;
}

int ArrayStack::Pop(){
    if(IsEmpty()){
        error("Stack Underflow");
    }
    return mData[mTop--];
}

int ArrayStack::Peek(){
    if(IsEmpty()){
        error("Stack Underflow");
    }
    return mData[mTop];
}

bool ArrayStack::IsEmpty(){
    return (-1 == mTop);
}

bool ArrayStack::IsFull(){
    return (MAX_STACK_SIZE == mTop-1);
}

void ArrayStack::Display(){
    printf("Number of stack elements : %2d", mTop+1);
    for(int i = 0; i <= mTop; ++i)
        printf("<%2d>", mData[i]);
    printf("\n");
}
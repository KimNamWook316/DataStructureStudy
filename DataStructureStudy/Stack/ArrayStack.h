#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__
#include <cstdio>
#include <cstdlib>

#define MAX_STACK_SIZE 20
class ArrayStack{
    int mTop;
    int mData[MAX_STACK_SIZE];
public:
    ArrayStack();
    void Push(const int& item);
    int Pop();
    int Peek();
    bool IsEmpty();
    bool IsFull();
    void Display();
};
#endif
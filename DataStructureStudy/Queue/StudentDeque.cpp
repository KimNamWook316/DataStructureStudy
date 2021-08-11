#include "StudentDeque.h"

StudentDeque::StudentDeque()
    :mFront(0)
    ,mRear(0){
}

StudentDeque::~StudentDeque(){
}

bool StudentDeque::IsEmpty()
{
    return mFront == mRear;
}

bool StudentDeque::IsFull()
{
    return (1 == (mFront + MAX_DEQUE_SIZE) - mRear);
}

void StudentDeque::AddFront(const INFO& val){
    if (IsFull()){
        error("Deque Overflow");
    }
    mData[mFront] = val;
    mFront = (mFront == 0) ? MAX_DEQUE_SIZE - 1 : mFront - 1;
}

const int& StudentDeque::DeleteFront(){
}

const int& StudentDeque::DeleteRear()
{
    // TODO: insert return statement here
}

const int& StudentDeque::GetFront()
{
    // TODO: insert return statement here
}

const int& StudentDeque::GetRear()
{
    // TODO: insert return statement here
}

void StudentDeque::Display() const
{
}

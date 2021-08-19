#include "LocationStack.h"
#include "define.h"

LocationStack::LocationStack() 
    :mTop(nullptr){
}

LocationStack::~LocationStack() {
    while (!IsEmpty()) {
        SAFE_DELETE(Pop());
    }
}

void LocationStack::Push(LocationNode* loc) {
    if (IsEmpty()) {
        mTop = loc;
    } else {
        loc->SetLink(mTop);
        mTop = loc;
    }
}

LocationNode* LocationStack::Pop() {
    if (IsEmpty()) {
        return nullptr;
    }
    LocationNode* temp = mTop;
    mTop = mTop->GetLink();
    return temp;
}

LocationNode* LocationStack::Peek() {
    if (IsEmpty()) {
        return nullptr;
    }
    return mTop;
}

bool LocationStack::IsEmpty() {
    return nullptr == mTop;
}

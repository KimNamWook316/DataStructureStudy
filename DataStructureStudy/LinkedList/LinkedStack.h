#pragma once
#include "Node.h"
class LinkedStack{
public:
	explicit LinkedStack()
		: mTop(nullptr){}
	
	~LinkedStack(){
		while (IsEmpty()) { delete Pop(); }
	}

	bool IsEmpty() {
		return nullptr == mTop;
	}

	void Push(Node* val){
		if (IsEmpty()){
			mTop = val;
		}
		else {
		val->SetLink(mTop);
		mTop = val;
		}
	}
	
	Node* Pop(){
		if (IsEmpty()){
			return nullptr;
		}
		Node* temp = mTop;
		mTop = mTop->GetLink();
		return temp;
	}

	Node* Peek(){
		if (IsEmpty()){
			return nullptr;
		}
		return mTop;
	}

	void Display(){
		printf("[LinkedStack]\n");
		for (Node* p = mTop; p != nullptr; p = p->GetLink()){
			p->Display();
		}
		printf("\n");
	}
private:
	Node* mTop;
};
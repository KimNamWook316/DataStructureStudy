#include "Node.h"
class LinkedQueue{
public:
	explicit LinkedQueue()
		:mFront(nullptr), mRear(nullptr){
	}
	~LinkedQueue(){
		while (IsEmpty()) delete Dequeue();
	}
	void Enqueue(Node* node){
		if (IsEmpty()){
			mFront = node;
			mRear = node;
		} else {
			mRear->SetLink(node);
			mRear = node;
		}
	}
	Node* Dequeue(){
		if (IsEmpty()){
			return nullptr;
		}
		Node* temp = mFront;
		mFront = mFront->GetLink();
		if (nullptr == mFront){
			mRear = nullptr;
		}
		return temp;
	}
	Node* Peek(){
		if (IsEmpty()){
			return nullptr;
		}
		return mFront;
	}
	bool IsEmpty(){
		return mFront == nullptr;
	};
	void Display(){
		printf("[Queue Elements]\n");
		for (Node* p = mFront; p != nullptr; p = p->GetLink()){
			p->Display();
		}
		printf("\n");
	}

private:
	Node* mFront;
	Node* mRear;
};
#pragma once
#include "Student.h"
class Node : public Student{
public:
	Node(const int& i, const char* name = "", const char* dept = "")
		:Student(i,name,dept), mLink(nullptr){
	}
	Node* GetLink() { return mLink; }
	void SetLink(Node* link){
		mLink = link;
	}
private:
	Node* mLink;
};
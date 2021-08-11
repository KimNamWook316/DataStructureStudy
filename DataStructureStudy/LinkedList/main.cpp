#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"
using namespace std;

int main(){
	LinkedStack stack;
	stack.Push(new Node(2015130007, "홍길동", "컴퓨터공학과"));
	stack.Push(new Node(2015130008, "이순신", "기계공학과"));
	stack.Push(new Node(2015130009, "황희", "법학과"));
	stack.Display();

	Node* node = stack.Pop();
	printf("[POP항목]\n");
	node->Display();
	printf("\n");
	delete node;
	stack.Display();

	printf("====================================================================\n");
	LinkedQueue que;
	que.Enqueue(new Node(2015130007, "홍길동", "컴퓨터공학과"));
	que.Enqueue(new Node(2015130008, "이순신", "기계공학과"));
	que.Enqueue(new Node(2015130010, "황희", "법학과"));	
	que.Enqueue(new Node(2015130011, "몰라", "경영학과"));
	que.Enqueue(new Node(2015130012, "누구", "경제학부"));
	que.Enqueue(new Node(2015130013, "익명", "시각디자인과"));
	
	que.Display();
	delete que.Dequeue();
	delete que.Dequeue();
	delete que.Dequeue();
	que.Display();
	return 0;
}
#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"
using namespace std;

int main(){
	LinkedStack stack;
	stack.Push(new Node(2015130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	stack.Push(new Node(2015130008, "�̼���", "�����а�"));
	stack.Push(new Node(2015130009, "Ȳ��", "���а�"));
	stack.Display();

	Node* node = stack.Pop();
	printf("[POP�׸�]\n");
	node->Display();
	printf("\n");
	delete node;
	stack.Display();

	printf("====================================================================\n");
	LinkedQueue que;
	que.Enqueue(new Node(2015130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	que.Enqueue(new Node(2015130008, "�̼���", "�����а�"));
	que.Enqueue(new Node(2015130010, "Ȳ��", "���а�"));	
	que.Enqueue(new Node(2015130011, "����", "�濵�а�"));
	que.Enqueue(new Node(2015130012, "����", "�����к�"));
	que.Enqueue(new Node(2015130013, "�͸�", "�ð������ΰ�"));
	
	que.Display();
	delete que.Dequeue();
	delete que.Dequeue();
	delete que.Dequeue();
	que.Display();
	return 0;
}
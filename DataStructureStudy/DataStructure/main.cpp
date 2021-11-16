#define CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>


#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>������ operator new�� malloc�� 

// Derived�ؼ� ���� �� ���, ��� �� �� ����.

#endif

#include "LinkedList.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CLinkedList list;
	list.Insert(0, new CNode(10));
	list.Insert(0, new CNode(20));
	list.Insert(1, new CNode(30));
	list.Insert(list.GetSize(), new CNode(40));
	list.Insert(2, new CNode(50));
	list.Display();
	CNode* deleted = list.Remove(2);
	delete deleted;
	deleted = list.Remove(list.GetSize() - 1);
	delete deleted;
	deleted = list.Remove(0);
	delete deleted;
	list.Replace(1, new CNode(90));
	list.Display();
	list.Clear();
	list.Display();

	return 0;
}
#define CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>


#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>등으로 operator new나 malloc을 

// Derived해서 정의 한 경우, 사용 할 수 없다.

#endif

#include "LinkedList.h"
#include "DblLinkedList.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Single
	//CLinkedList list;
	//list.Insert(0, new CNode(10));
	//list.Insert(0, new CNode(20));
	//list.Insert(1, new CNode(30));
	//list.Insert(list.GetSize(), new CNode(40));
	//list.Insert(2, new CNode(50));
	//list.Display();
	//CNode* deleted = list.Remove(2);
	//delete deleted;
	//deleted = list.Remove(list.GetSize() - 1);
	//delete deleted;
	//deleted = list.Remove(0);
	//delete deleted;
	//list.Replace(1, new CNode(90));
	//list.Display();
	//list.Clear();
	//list.Display();

	// Double-Linked List
	CDblLinkedList list;
	list.Insert(0, new CDoubleNode(10));
	list.Insert(0, new CDoubleNode(20));
	list.Insert(1, new CDoubleNode(30));
	list.Insert(list.GetSize(), new CDoubleNode(40));
	list.Insert(2, new CDoubleNode(50));
	list.Display();
	list.Remove(2);
	list.Remove(list.GetSize() - 1);
	list.Remove(0);
	list.Replace(1, new CDoubleNode(90));
	list.Display();
	list.Clear();
	list.Display();

	return 0;
}
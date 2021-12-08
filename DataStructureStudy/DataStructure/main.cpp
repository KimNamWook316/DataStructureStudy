#define CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>


#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>등으로 operator new나 malloc을 

// Derived해서 정의 한 경우, 사용 할 수 없다.

#endif

#include "LinkedList.h"
#include "DblLinkedList.h"
#include "LinkBinaryTree.h"
#include "ThreadBinaryTree.h"
#include "MaxHeap.h"
#include "AdjMatGraph.h"

void heapSort(int a[], int n);

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

	//// Double-Linked List
	//CDblLinkedList list;
	//list.Insert(0, new CDoubleNode(10));
	//list.Insert(0, new CDoubleNode(20));
	//list.Insert(1, new CDoubleNode(30));
	//list.Insert(list.GetSize(), new CDoubleNode(40));
	//list.Insert(2, new CDoubleNode(50));
	//list.Display();
	//list.Remove(2);
	//list.Remove(list.GetSize() - 1);
	//list.Remove(0);
	//list.Replace(1, new CDoubleNode(90));
	//list.Display();
	//list.Clear();
	//list.Display();

 //	// Binary Tree
 //	CLinkBinaryTree tree;
 //	CBinaryNode* d = new CBinaryNode('D');
 //	CBinaryNode* e = new CBinaryNode('E');
 //	CBinaryNode* b = new CBinaryNode('B', d, e);
 //	CBinaryNode* f = new CBinaryNode('F');
 //	CBinaryNode* c = new CBinaryNode('C', f);
 //	CBinaryNode* a = new CBinaryNode('A', b, c);
 //	tree.SetRoot(a);
 //
 //	tree.PreOrder();
 //	tree.InOrder();
 //	tree.PostOrder();
 //	tree.LevelOrder();
 //
 //	std::cout << "노드 개수 : " << tree.GetCount() << std::endl;
 //	std::cout << "단말 개수 : " << tree.GetLeafCount() << std::endl;
 //	std::cout << "트리 높이 : " << tree.GetHeight() << std::endl;
 //
 //	CLinkBinaryTree opTree;
 //	CBinaryNode* n1 = new CBinaryNode(3);
 //	CBinaryNode* n2 = new CBinaryNode(2);
 //	CBinaryNode* n3 = new CBinaryNode('*', n1, n2);
 //	CBinaryNode* n4 = new CBinaryNode(5);
 //	CBinaryNode* n5 = new CBinaryNode(6);
 //	CBinaryNode* n6 = new CBinaryNode('-', n4, n5);
 //	CBinaryNode* n7 = new CBinaryNode('+', n3, n6);
 //	opTree.SetRoot(n7);
 //
 //	std::cout << "계산 결과 : " << opTree.Caculate() << std::endl;
 //
 //	// 스레드 이진트리
 //	CThreadBinaryTree threadTree;
 //	//			G
 //	//		C		F
 //	//	A	  B    D   E
 //	CThreadBinaryNode* tN1 = new CThreadBinaryNode('A', nullptr, nullptr, true);
 //	CThreadBinaryNode* tN2 = new CThreadBinaryNode('B', nullptr, nullptr, true);
 //	CThreadBinaryNode* tN3 = new CThreadBinaryNode('C', tN1, tN2, false);
 //	CThreadBinaryNode* tN4 = new CThreadBinaryNode('D', nullptr, nullptr, true);
 //	CThreadBinaryNode* tN5 = new CThreadBinaryNode('E', nullptr, nullptr, false);
 //	CThreadBinaryNode* tN6 = new CThreadBinaryNode('F', tN4, tN5, false);
 //	CThreadBinaryNode* tN7 = new CThreadBinaryNode('G', tN3, tN6, false);
 //	threadTree.SetRoot(tN1);
 //	tN1->SetRight(tN3);
 //	tN2->SetRight(tN7);
 //	tN4->SetRight(tN6);
 //	threadTree.ThreadInorder();
 //
 //	// Max Heap
	CMaxHeap heap;

	heap.Insert(10);
	heap.Insert(5);
	heap.Insert(30);
	heap.Insert(8);
	heap.Insert(9);
	heap.Insert(3);
	heap.Insert(7);
	heap.Display();

	heap.Remove();
	heap.Display();
	heap.Remove();
	heap.Display();
	std::cout << std::endl;

	int data[10];

	for (int i = 0; i < 10; ++i)
	{
		data[i] = rand() % 100;
	}

	std::cout << "Before Heap Sort" << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "  " << data[i];
	}
	std::cout << std::endl;

	heapSort(data, 10);

	std::cout << "After Heap Sort" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "  " << data[i];
	}
	std::cout << std::endl;

	// Graph
	CAdjMatGraph graph;

	for (int i = 0; i < 4; ++i)
	{
		graph.InsertVertex('A' + i);
	}
	graph.InsertEdge(0, 1);
	graph.InsertEdge(0, 3);
	graph.InsertEdge(1, 2);
	graph.InsertEdge(1, 3);
	graph.InsertEdge(2, 3);

	std::cout << "Adj Matrix Graph : " << std::endl;
	graph.Display();
	
	return 0;
}
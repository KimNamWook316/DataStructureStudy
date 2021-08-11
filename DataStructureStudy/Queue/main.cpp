//#include "CircularQueue.h"
//#include "CircularDeque.h"
#include <ctime>
#include "BankSimulator.h"

int main() {
	srand(unsigned(time(NULL)));
	BankSimulator sim;
	sim.ReadSimulationParameters();
	sim.Run();
	sim.PrintStat();

	//CircularQueue queue;
	//for (int i = 1; i < 10; ++i) {
	//	queue.Enqueue(i);
	//}
	//queue.Display();
	//queue.Dequeue();
	//queue.Dequeue();
	//queue.Dequeue();
	//queue.Display();

	//CircularDeque deq;
	//for (int i = 1; i < 10; ++i) {
	//	if (i % 2) deq.AddFront(i);
	//	else       deq.AddRear(i);
	//}

	//deq.Display();
	//deq.DeleteFront();
	//deq.DeleteRear();
	//deq.DeleteFront();
	//deq.Display();

	return 0;
}
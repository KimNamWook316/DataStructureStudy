#include "CircularQueue.h"

const int& GetFibo(const int& n) {
	if (1 == n) return 0;
	if (2 == n) return 1;

	CircularQueue que;
	que.Enqueue(0);
	que.Enqueue(1);

	for (int i = 2; i < n; ++i) {
		que.Enqueue(que.Dequeue() + que.Peek());
	}
	que.Dequeue();
	return que.Dequeue();
}

int main() {
	int fibo = GetFibo(10);

	printf("Fibo times : %d\n", fibo);

	return 0;
}
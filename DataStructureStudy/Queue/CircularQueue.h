#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__
#define MAX_QUEUE_SIZE 20
#include <cstdio>
#include <cstdlib>

inline void error(const char* str) {
	printf(str);
	exit(1);
}

class CircularQueue {
public:
	explicit CircularQueue();
	virtual ~CircularQueue();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(const int& val);
	const int& Dequeue();
	const int& Peek();
	virtual void Display() const;
protected:
	int mFront;
	int mRear;
	int mData[MAX_QUEUE_SIZE];
};

#endif // !__CIRCULAR_QUEUE_H__

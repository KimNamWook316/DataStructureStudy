#pragma once
#include <cstdio>
#include <cstdlib>
#include "StudentInfo.h"
#define MAX_DEQUE_SIZE 30
inline void error(const char* str) {
	printf(str);
	exit(1);
}
class StudentDeque{
public:
	explicit StudentDeque();
	~StudentDeque();
	bool IsEmpty();
	bool IsFull();

	void AddFront(const INFO& val);
	void AddRear(const INFO& val);

	const int& DeleteFront();
	const int& DeleteRear();

	const int& GetFront();
	const int& GetRear();

	virtual void Display() const;
protected:
	int mFront;
	int mRear;
	INFO mData[MAX_DEQUE_SIZE];
};


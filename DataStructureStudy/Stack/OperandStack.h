#ifndef __OPERANDSTACK_H__
#define __OPERANDSTACK_H__
#define MAX_SIZE_STACK 20
#include <cstdio>
#include <cstdlib>

inline void error(const char* str = "") { printf("%s\n", str); exit(1); }

class OperandStack {
public:
	explicit OperandStack();
	void Push(const double& e);
	double Pop();
	bool IsEmpty() const;
	bool IsFull() const;

private:
	int mTop;
	double mData[MAX_SIZE_STACK];
};

#endif // !__OPERANDSTACK_H__

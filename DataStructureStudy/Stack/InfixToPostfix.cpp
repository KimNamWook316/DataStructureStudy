#include "ArrayStack.h"

int GetPriorityOperand(const char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default:
		break;
	}
	return -1;
}

void infixToPostfix(FILE* fp = stdin) {
	char c;
	double val;
	ArrayStack stack;
	while ('\n' != (c = getc(fp))) {
		if (('0' <= c) && ('9' >= c)) {
			ungetc(c, fp);
			fscanf_s(fp, "%lf", &val);
			printf("%4.1f", val);
		} else if (('+' == c) || ('-' == c) || ('*' == c) || ('/' == c)) {
			if (stack.IsEmpty()) {
				stack.Push(c);
				continue;
			} else {
				while (GetPriorityOperand(stack.Peek()) >= GetPriorityOperand(c)) {
					printf("%c", stack.Pop());
				}
				stack.Push(c);
			}
		} else if (('(' == c)) {
			stack.Push(c);
		} else if ((')' == c)) {
			while (stack.Peek() != '(') {
				printf("%c", stack.Pop());
			}
			stack.Pop();
		}
	}
	while (!stack.IsEmpty()) {
		printf("%c", stack.Pop());
	}
	printf("\n");
}

//int main() {
//	printf("수식 입력(Infix) : ");
//	infixToPostfix();
//	return 0;
//}
//#include "CImaginary.h"
//#include "CRectangle.h"
//#include "CMatrix.h"
//#include "Polynomial.h"
#include "OperandStack.h"

double calcPostfixExpr(FILE* fp = stdin) {
	char c;
	OperandStack stack;
	while ('\n' != ( c = getc(fp))) {
		if (('+' == c) || ('-' == c) || ('*' == c) || ('/' == c)) {
			double temp1 = stack.Pop();
			double temp2 = stack.Pop();
			switch (c) {
			case '+':
				stack.Push(temp2 + temp1);
				break;
			case '-':
				stack.Push(temp2 - temp1);
				break;
			case '*':
				stack.Push(temp2 * temp1);
				break;
			case '/':
				stack.Push(temp2 / temp1);
				break;
			default:
				break;
			}
		} else if (('0' <= c) && ('9' >= c)) {
			ungetc(c, fp);
			double val;
			fscanf_s(fp, "%lf", &val);
			stack.Push(val);
		}
	}
	return stack.Pop();
};

int main() {
	printf("수식 입력 = ");
	double res = calcPostfixExpr();
	printf("결과 = %f\n", res);
	return 0;
}

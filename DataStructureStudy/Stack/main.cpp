//#include "CImaginary.h"
//#include "CRectangle.h"
//#include "CMatrix.h"
//#include "Polynomial.h"
//#include "OperandStack.h"
#include <stack>
#include "Location2D.h";
using namespace std;
const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1',},
	{'e','0','1','0','0','1',},
	{'1','0','0','0','1','1',},
	{'1','0','1','0','1','1',},
	{'1','0','1','0','0','x',},
	{'1','1','1','1','1','1',},
};

bool isValidLocation(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
};

int main() {
	stack<Location2D> locStack;
	Location2D entryLoc(1, 0);
	locStack.push(entryLoc);

	bool bSuccess = false;

	while (!locStack.empty()) {
		printf("탐색중 : 현재 위치 : %d, %d ...\n", entryLoc.row, entryLoc.col);
		if ('x' == map[entryLoc.row][entryLoc.col]) {
			bSuccess = true;
			break;
		}

		if(isValidLocation(entryLoc.row - 1, entryLoc.col))
			locStack.push(Location2D(entryLoc.row - 1, entryLoc.col));
		if (isValidLocation(entryLoc.row + 1, entryLoc.col))
			locStack.push(Location2D(entryLoc.row + 1, entryLoc.col));
		if (isValidLocation(entryLoc.row, entryLoc.col - 1))
			locStack.push(Location2D(entryLoc.row, entryLoc.col - 1));
		if (isValidLocation(entryLoc.row, entryLoc.col + 1))
			locStack.push(Location2D(entryLoc.row, entryLoc.col + 1));

		map[entryLoc.row][entryLoc.col] = '1';
		entryLoc = locStack.top();
		locStack.pop();
	}
	
	if (bSuccess)
		printf("미로 탐색 성공!\n");
	else
		printf("미로 탐색 실패!\n");
	return 0;
}

//double calcPostfixExpr(FILE* fp = stdin) {
//	char c;
//	OperandStack stack;
//	while ('\n' != (c = getc(fp))) {
//		if (('+' == c) || ('-' == c) || ('*' == c) || ('/' == c)) {
//			double temp1 = stack.Pop();
//			double temp2 = stack.Pop();
//			switch (c) {
//			case '+':
//				stack.Push(temp2 + temp1);
//				break;
//			case '-':
//				stack.Push(temp2 - temp1);
//				break;
//			case '*':
//				stack.Push(temp2 * temp1);
//				break;
//			case '/':
//				stack.Push(temp2 / temp1);
//				break;
//			default:
//				break;
//			}
//		} else if (('0' <= c) && ('9' >= c)) {
//			ungetc(c, fp);
//			double val;
//			fscanf_s(fp, "%lf", &val);
//			stack.Push(val);
//		}
//	}
//	return stack.Pop();
//};
//
//int main() {
	//printf("수식 입력 = ");
	//double res = calcPostfixExpr();
	//printf("결과 = %f\n", res);
//	return 0;
//}


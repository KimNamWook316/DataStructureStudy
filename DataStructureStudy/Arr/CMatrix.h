#ifndef __CMATRIX_H__
#define __CMATRIX_H__
#include <cstdio>

class CMatrix {
private:
	int row;
	int col;
	int** mat;

	void allocateMemory(const int& row, const int& col);

public:
	CMatrix();
	CMatrix(const int& row, const int& col);
	CMatrix(const int& row, const int& col, int** mat);
	~CMatrix();
	void SetValue();
	CMatrix Transpose();
	void Print();
};
#endif // !__MATRIX_H__

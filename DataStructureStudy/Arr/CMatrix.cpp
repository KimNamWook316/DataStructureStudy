#include "CMatrix.h"

void CMatrix::allocateMemory(const int & row, const int & col) {
	mat = new int*[row];
	for (int i = 0; i < row; ++i)
		mat[i] = new int[col];
}

CMatrix::CMatrix() :row(0), col(0){
	mat = nullptr;
}

CMatrix::CMatrix(const int & row, const int & col) :row(row), col(col){
	allocateMemory(row, col);
}

CMatrix::CMatrix(const int& row, const int& col, int ** mat) 
	:row(row), col(col) {
	allocateMemory(row, col);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			this->mat[i][j] = mat[i][j];
}

CMatrix::~CMatrix() {
	if (mat != nullptr) {
		for (int i = 0; i < row; ++i)
			delete[] mat[i];
		delete[] mat;
	}
}

void CMatrix::SetValue() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d 행 %d 열 원소 :", i, j);
			scanf_s("%d", &mat[i][j]);
		}
	}
}

CMatrix CMatrix::Transpose() {
	int** temp = new int*[col];
	for (int i = 0; i < col; ++i)
		temp[i] = new int[row];

	for (int i = 0; i < col; ++i) {
		for (int j = 0; j < row; ++j) {
			temp[i][j] = mat[j][i];
		}
	}
	return CMatrix(col, row, temp);
}

void CMatrix::Print() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

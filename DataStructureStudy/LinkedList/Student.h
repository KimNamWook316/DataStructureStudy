#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_STRING 100
class Student{
public:
	Student(const int& i = 0, const char* n = "", const char* d = "") { Set(i, n, d); }
	void Set(const int& i, const char* n, const char* d) {
		mId = i;
		strcpy_s(mName, MAX_STRING, n);
		strcpy_s(mDept, MAX_STRING, n);
	}
	void Display(){
		printf(" �й�:%-15d ����:%-10s, �а�:%-20s\n", mId, mName, mDept);
	}
private:
	int mId;
	char mName[MAX_STRING];
	char mDept[MAX_STRING];
};
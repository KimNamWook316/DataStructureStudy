#include "SparsePoly.h"

SparsePoly::SparsePoly() : mNTerms(0){}

void SparsePoly::Read() {
	printf("다항식의 최고 차수를 입력하시오 : ");
	scanf_s("%d", mNTerms);
	printf("각 항의 계수를 입력하시오 (%d개):", mNTerms + 1);
	for (int i = 0; i <= mNTerms; ++i) {

	}
}

void SparsePoly::Add(SparsePoly sA, SparsePoly sB) {
	
}

void SparsePoly::Display(const char * str) {
}

#include <cstring>
#include <cstdio>
#include "Polynomial.h"

Polynomial::Polynomial() : mDegree(0){}

void Polynomial::Read() {
	printf("다항식의 최고 차수를 입력하시오 : ");
	scanf_s("%d", &mDegree);
	printf("각 항의 계수를 입력하시오 (%d개):", mDegree + 1);
	for (int i = 0; i <= mDegree; ++i)
		scanf_s("%f", mCoef + i);
}

void Polynomial::Display(const char * str) {
	printf("\t%s", str);

	for (int i = 0; i < mDegree; ++i) {
		if (mCoef[i] == 0) {
			continue;
		} else if (mCoef[i] == 1) {
			printf(" x^%5.1d + ", mDegree - i);
		} else {
			printf("%5.1f x^%d + ", mCoef[i], mDegree - i);
		}
	}
	if (mCoef[mDegree] != 0)
		printf(" %4.1f\n", mCoef[mDegree]);
	else
		printf("0\n");
}

void Polynomial::Add(Polynomial pA, Polynomial pB) {
	if (pA.mDegree > pB.mDegree) {
		*this = pA;
		for (int i = 0; i <= pB.mDegree; ++i)
			mCoef[i + (mDegree - pB.mDegree)] += pB.mCoef[i];
	} else {
		*this = pB;
		for (int i = 0; i <= pA.mDegree; ++i)
			mCoef[i + (mDegree - pA.mDegree)] += pA.mCoef[i];
	}
}

void Polynomial::Sub(Polynomial pA, Polynomial pB) {
	pB.Negate();
	Add(pA, pB);
}

void Polynomial::Mult(Polynomial pA, Polynomial pB) {
	Polynomial T; 
	T.mDegree = (pA.mDegree + pB.mDegree);
	for (int i = 0; i <= T.mDegree; ++i)
		T.mCoef[i] = 0;

	if (pA.mDegree > pB.mDegree) {
		for (int i = 0; i <= pB.mDegree; ++i)
			for (int j = 0; j <= pA.mDegree; ++j)
				T.mCoef[j + i] += pA.mCoef[j] * pB.mCoef[i];
	} else {
		for (int i = 0; i <= pA.mDegree; ++i)
			for (int j = 0; j <= pB.mDegree; ++j)
				T.mCoef[j + i] += pB.mCoef[j] * pA.mCoef[i];
	}
	*this = T;
}

void Polynomial::Trim() {
	if (mCoef[0] != 0)
		return;
	int idx = 0;
	int deg = mDegree;
	while (mCoef[idx] == 0) {
		++idx;
	}
	deg -= idx;
	memmove(mCoef, mCoef + idx, sizeof(float)*mDegree);
	mDegree = deg;
}

bool Polynomial::IsZero() { return mDegree == 0; }

void Polynomial::Negate() {
	for (int i = 0; i <= mDegree; ++i)
		mCoef[i] = -mCoef[i];
}

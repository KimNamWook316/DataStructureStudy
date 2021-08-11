#pragma once
#include "Term.h"
#include <cstdio>
#define MAX_DEGREE 80
class SparsePoly {
	int		mNTerms;
	Term	mTerm[MAX_DEGREE];
public:
	SparsePoly();
	void Read();
	void Add(SparsePoly sA, SparsePoly sB);
	void Display(const char *str = "SPoly = ");
};
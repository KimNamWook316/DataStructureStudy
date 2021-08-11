#pragma once
#define MAX_DEGREE 80
class Polynomial {
	int mDegree;
	float mCoef[MAX_DEGREE];
public:
	Polynomial();
	void Read();
	void Display(const char* str = " Poly = ");
	void Add(Polynomial pA, Polynomial pB);
	void Sub(Polynomial pA, Polynomial pB);
	void Mult(Polynomial pA, Polynomial pB);
	void Trim();
	bool IsZero();
	void Negate();
};
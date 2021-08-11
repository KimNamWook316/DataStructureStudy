#ifndef __CIMAGINARY_H__
#define __CIMAGINARY_H__
#include <cstdio>

class CImaginary {
private:
	double m_dReal;
	double m_dImag;
public:
	CImaginary();
	CImaginary(double _dReal, double _dImag);
	CImaginary Add(const CImaginary& _c1, const CImaginary& _c2);
	CImaginary Sub(const CImaginary& _c1, const CImaginary& _c2);
	CImaginary Mul(const CImaginary& _c1, const CImaginary& _c2);
	void Print();
};

#endif // !__CIMAGINARY_H__

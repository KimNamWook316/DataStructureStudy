#ifndef __CRECTANGLE_H__
#define __CRECTANGLE_H__
#include <cstdio>

class CRectangle {
private:
	double m_dWidth;
	double m_dHeight;

public:
	CRectangle();
	CRectangle(const double& _d1, const double& _d2);
	double Area();
	double Perimeter();
	void Print();
};

#endif // !__CRECTANGLE_H__

#include "CRectangle.h"

CRectangle::CRectangle() : m_dWidth(0), m_dHeight(0){}

CRectangle::CRectangle(const double & _dW, const double & _dH) 
 : m_dWidth(_dW), m_dHeight(_dH) {}

double CRectangle::Area() {
	return m_dWidth * m_dHeight;
}

double CRectangle::Perimeter() {
	return m_dWidth * 2 + m_dHeight * 2;
}

void CRectangle::Print() {
	printf("Width : %f\n", m_dWidth);
	printf("Height : %f\n", m_dHeight);
	printf("Area : %f\n", this->Area());
	printf("Perimeter : %f\n", this->Perimeter());
}

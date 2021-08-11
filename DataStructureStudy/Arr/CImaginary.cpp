#include "CImaginary.h"

CImaginary::CImaginary() : m_dReal(0), m_dImag(0){
}
CImaginary::CImaginary(double _dReal, double _dImag) 
	: m_dReal(_dReal), m_dImag(_dImag) {
}
CImaginary CImaginary::Add(const CImaginary & _c1, const CImaginary & _c2) {
	return CImaginary((_c1.m_dReal + _c2.m_dReal), (_c1.m_dImag + _c2.m_dImag));
}

CImaginary CImaginary::Sub(const CImaginary & _c1, const CImaginary & _c2) {
	return CImaginary((_c1.m_dReal - _c2.m_dReal), (_c1.m_dImag - _c2.m_dImag));
}

CImaginary CImaginary::Mul(const CImaginary & _c1, const CImaginary & _c2) {
	double dReal = (_c1.m_dReal * _c2.m_dReal) + ((_c1.m_dImag * _c2.m_dImag) * -1);
	double dImag = (_c1.m_dReal * _c2.m_dImag) + (_c2.m_dReal * _c1.m_dImag);
	return CImaginary(dReal, dImag);
}

void CImaginary::Print() {
	printf("%f + %fi\n", m_dReal, m_dImag);
}

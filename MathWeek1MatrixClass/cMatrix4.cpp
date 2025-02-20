#include "cMatrix4.h"

void Matrix4::SetElement(int _iX, int _iY, float _fValue)
{
	m_fMatrix[_iX - 1][_iY - 1] = _fValue;
}

float Matrix4::GetElement(int _iX, int _iY) const
{
	return m_fMatrix[_iX - 1][_iY - 1];
}

void Matrix4::Identity(Matrix4& _rResult)
{

}

void Matrix4::Zero(Matrix4& _rResult)
{
}

bool Matrix4::Equals(const Matrix4& _rA, const Matrix4& _rB)
{
	return false;
}

void Matrix4::Add(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult)
{
}

void Matrix4::Subtract(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult)
{
}

void Matrix4::Multiply(float _fScalar, const Matrix4& _rA, Matrix4& _rResult)
{
}

void Matrix4::Multiply(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult)
{
}

void Matrix4::Transpose(const Matrix4& _rA, Matrix4& _rResult)
{
}

float Matrix4::Determinant(const Matrix4& _rA)
{
	return 0.0f;
}

bool Matrix4::Inverse(const Matrix4& _rA, Matrix4& _rResult)
{
	return false;
}

bool Matrix4::TestHarness()
{
	return false;
}

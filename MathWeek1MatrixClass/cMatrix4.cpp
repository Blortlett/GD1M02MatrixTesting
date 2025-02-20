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
    // Loop through matrix and set diagonal to 1, rest to 0
    for (int xIndex = 1; xIndex < 5; ++xIndex) {
        for (int yIndex = 1; yIndex < 5; ++yIndex) {
            if (xIndex == yIndex) {
                _rResult.SetElement(xIndex, yIndex, 1);
            } else {
                _rResult.SetElement(xIndex, yIndex, 0);
            }
        }
    }
}

void Matrix4::Zero(Matrix4& _rResult)
{
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {

				_rResult.SetElement(xIndex, yIndex, 0);

		}
	}
}

bool Matrix4::Equals(const Matrix4& _rA, const Matrix4& _rB)
{
	int matrix1Value;
	int matrix2Value;
	// loop through array positions for both arays
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			matrix1Value = _rA.GetElement(xIndex, yIndex);
			matrix2Value = _rB.GetElement(xIndex, yIndex);
			// if not equal then return out false
			if (matrix1Value != matrix2Value) return false;
		}
	}

	// if made it here, all should be equal as bro
	return true;
}

void Matrix4::Add(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult)
{
	int matrix1Value;
	int matrix2Value;
	int sumOfValues;

	// loop through array positions for both arays
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			matrix1Value = _rA.GetElement(xIndex, yIndex);
			matrix2Value = _rB.GetElement(xIndex, yIndex);
			sumOfValues = matrix1Value + matrix2Value;
			// Set position equal to sum of same positions in matrix 1&2
			_rResult.SetElement(xIndex, yIndex, sumOfValues);
		}
	}
}

void Matrix4::Subtract(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult)
{
	int matrix1Value;
	int matrix2Value;
	int result;

	// loop through array positions for both arays
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			matrix1Value = _rA.GetElement(xIndex, yIndex);
			matrix2Value = _rB.GetElement(xIndex, yIndex);
			result = matrix1Value - matrix2Value;
			// Set position equal to sum of same positions in matrix 1&2
			_rResult.SetElement(xIndex, yIndex, result);
		}
	}
}

void Matrix4::Multiply(float _fScalar, const Matrix4& _rA, Matrix4& _rResult)
{
	int matrixPosValue;
	int result;

	// loop through array positions for both arays
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			matrixPosValue = _rA.GetElement(xIndex, yIndex);
			result = matrixPosValue * _fScalar;
			// Set position equal to sum of same positions in matrix 1&2
			_rResult.SetElement(xIndex, yIndex, result);
		}
	}
}

void Matrix4::Multiply(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult)
{
	// Loop through each row of _rA
	for (int i = 0; i < 4; ++i) {
		// Loop through each column of _rB
		for (int j = 0; j < 4; ++j) {
			_rResult.SetElement(i, j, 0.0f); // Make sure result starts off as 0

			// Perform the dot product of row i from _rA with column j from _rB
			for (int k = 0; k < 4; ++k) {
				_rResult.SetElement(i, j, (_rA.GetElement(i, k) * _rB.GetElement(k,j)));
			}
		}
	}
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

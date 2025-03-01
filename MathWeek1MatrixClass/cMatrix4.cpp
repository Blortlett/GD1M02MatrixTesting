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
	for (int i = 1; i < 5; ++i) {
		// Loop through each column of _rB
		for (int j = 1; j < 5; ++j) {
			_rResult.SetElement(i, j, 0.0f); // Make sure result starts off as 0

			// Perform the dot product of row i from _rA with column j from _rB
			for (int k = 1; k < 5; ++k) {
				_rResult.SetElement(i, j, (_rA.GetElement(i, k) * _rB.GetElement(k,j)));
			}
		}
	}
}

void Matrix4::Transpose(const Matrix4& _rA, Matrix4& _rResult)
{
	// loop through array positions for both arays
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			_rResult.SetElement(xIndex, yIndex, _rA.GetElement(yIndex, xIndex));
		}
	}
}

float Matrix4::Determinant(const Matrix4& _rA)
{
	float det = 0.0f;

	for (int col = 0; col < 4; ++col) {
		// Extract 3x3 minor
		float minor[3][3];
		int minorRow = 0;
		for (int i = 1; i < 4; ++i) { // Skip row 0
			int minorCol = 0;
			for (int j = 0; j < 4; ++j) {
				if (j == col) continue; // Skip current column
				minor[minorRow][minorCol] = _rA.m_fMatrix[i][j];
				++minorCol;
			}
			++minorRow;
		}

		// Compute cofactor
		float cofactor = ((col % 2 == 0) ? 1 : -1) * _rA.m_fMatrix[0][col] * Determinant3x3(minor);
		det += cofactor;
	}

	return det;
}
// return 3x3 grid for determinant function to work with
float Matrix4::Determinant3x3(float m[3][3]) {
	return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
		- m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
		+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
bool Matrix4::Inverse(const Matrix4& _rA, Matrix4& _rResult)
{
	float det = Determinant(_rA);
	if (det == 0.0f) {
		return false; // Not invertible
	}

	float invDet = 1.0f / det;
	float cofactors[4][4];

	// Compute cofactors
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			// Compute 3x3 minor
			float minor[3][3];
			int minorRow = 0;
			for (int i = 0; i < 4; ++i) {
				if (i == row) continue; // Skip current row
				int minorCol = 0;
				for (int j = 0; j < 4; ++j) {
					if (j == col) continue; // Skip current column
					minor[minorRow][minorCol] = _rA.m_fMatrix[i][j];
					++minorCol;
				}
				++minorRow;
			}

			// Compute cofactor
			float cofactor = ((row + col) % 2 == 0 ? 1 : -1) * Determinant3x3(minor);
			cofactors[row][col] = cofactor;
		}
	}

	// Compute adjugate (transpose of cofactor matrix)
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			_rResult.m_fMatrix[row][col] = cofactors[col][row] * invDet;
		}
	}

	return true;
}
bool Matrix4::TestHarness()
{
	return false;
}


// Helper Functions
void Matrix4::PrintMatrix() {
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			float value = GetElement(xIndex, yIndex);
			cout << (value < 0 ? " " : "  ") << value;
		}
		cout << endl;
	}
		cout << "\n" << endl;
}

void Matrix4::RandomizeMatrix() {
	// Loop through matrix and assign random number
	int randNumber;

	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			int randNumber = RandomInt();
			SetElement(xIndex, yIndex, randNumber);
		}
	}
}

int Matrix4::RandomInt() {
	return (std::rand() % MAX_RAND_NUMBER) - 9;
}
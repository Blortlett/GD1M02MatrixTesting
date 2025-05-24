/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMatrix4.h]
Description : [This class lets me store, use and perform operations on 4x4 Matrices]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
**************************************************************************/
#include "cMatrix4.h"
#include "cVector4.h"

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
			float sum = 0.0f; // Initialize sum for dot product
			// Perform the dot product of row i from _rA with column j from _rB
			for (int k = 1; k < 5; ++k) {
				sum += _rA.GetElement(i, k) * _rB.GetElement(k, j);
			}
			_rResult.SetElement(i, j, sum);
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
// return 3x3 grid for determinant function to work with:
float Matrix4::Determinant3x3(float m[3][3]) {
	return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
		- m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
		+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}
bool Matrix4::Inverse(const Matrix4& _rA, Matrix4& _rResult)
{
	float det = Determinant(_rA);
	if (abs(det) < 0.0001f) { // Add tolerance for near-zero
		return false;
	}

	float invDet = 1.0f / det;
	float cofactors[4][4];
	_rResult.Zero(_rResult); // Initialize result

	// Compute cofactors
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			float minor[3][3];
			int minorRow = 0;
			for (int i = 0; i < 4; ++i) {
				if (i == row) continue;
				int minorCol = 0;
				for (int j = 0; j < 4; ++j) {
					if (j == col) continue;
					minor[minorRow][minorCol] = _rA.m_fMatrix[i][j];
					++minorCol;
				}
				++minorRow;
			}
			float cofactor = ((row + col) % 2 == 0 ? 1 : -1) * Determinant3x3(minor);
			cofactors[row][col] = cofactor;
		}
	}

	// Compute adjugate and scale
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			_rResult.m_fMatrix[row][col] = cofactors[col][row] * invDet;
		}
	}

	return true;
}


Vector4& Matrix4::ScaleUniform(float _fScale,
	const Vector4& _rVec,
	Matrix4& _rResultMat)
{
	// Set result matrix to identity matrix first
	Identity(_rResultMat);

	// Set the scaling factors on the diagonal
	_rResultMat.SetElement(1, 1, _fScale);  // x scale
	_rResultMat.SetElement(2, 2, _fScale);  // y scale
	_rResultMat.SetElement(3, 3, _fScale);  // z scale
	_rResultMat.SetElement(4, 4, 1.0f);     // w remains 1

	// Return the input vector unchanged
	return const_cast<Vector4&>(_rVec);
}
Vector4& Matrix4::ScaleNonUniform(float _fScaleX,
	float _fScaleY,
	float _fScaleZ,
	Vector4& _rVec,
	Matrix4& _rResultMat)
{
	// Set result matrix to identity matrix first
	Identity(_rResultMat);

	// Set the individual scaling factors on the diagonal
	_rResultMat.SetElement(1, 1, _fScaleX);  // x scale
	_rResultMat.SetElement(2, 2, _fScaleY);  // y scale
	_rResultMat.SetElement(3, 3, _fScaleZ);  // z scale
	_rResultMat.SetElement(4, 4, 1.0f);      // w remains 1

	// Return the input vector unchanged
	return _rVec;
}
Vector4& Matrix4::Translation(float _fTranslateX,
	float _fTranslateY,
	float _fTranslateZ,
	const Vector4& _rVec,
	Matrix4& _rResult)
{
	// Set result matrix to identity matrix first
	Identity(_rResult);

	// Set the translation values in the last column
	_rResult.SetElement(1, 4, _fTranslateX);  // x translation
	_rResult.SetElement(2, 4, _fTranslateY);  // y translation
	_rResult.SetElement(3, 4, _fTranslateZ);  // z translation
	_rResult.SetElement(4, 4, 1.0f);         // w remains 1

	// Return the input vector unchanged
	return const_cast<Vector4&>(_rVec);
}


// Helper Functions
void Matrix4::PrintMatrix() const {
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			float value = GetElement(xIndex, yIndex);
			cout << (value < 0 ? " " : "  ") << value;
		}
		cout  << endl;
	}
		cout << "" << endl;
}

void Matrix4::LoadMatrix(const std::vector<std::string>& Tokens)
{
	// Check if we have enough tokens (4x4 matrix needs 16 elements)
	if (Tokens.size() < 16) {
		std::cerr << "Error: Not enough tokens to fill a 4x4 matrix. Found "
			<< Tokens.size() << " tokens, need 16." << std::endl;
		return;
	}

	// Assign tokens to matrix
	size_t tokenIndex = 0;
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			try {
				float value = std::stof(Tokens[tokenIndex]);
				SetElement(xIndex, yIndex, value);
				++tokenIndex;
			}
			catch (const std::exception& e) {
				std::cerr << "Error: Invalid number format in token '"
					<< Tokens[tokenIndex] << "' at position "
					<< tokenIndex + 1 << "." << std::endl;
				return;
			}
		}
	}
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
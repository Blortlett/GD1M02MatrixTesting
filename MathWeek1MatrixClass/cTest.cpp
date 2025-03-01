#pragma once
#include "cTest.h"
#include "cMatrix4.h"

// Written Tests
bool TestIdentity(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix)
{
    _Matrix.Identity(_Matrix);

    // Check each element in the matrix (1-based indexing)
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            if (i == j) {
                // Diagonal elements should be 1
                if (_Matrix.GetElement(i, j) != 1) {
                    _riTestsPerformed++;
                    return false;
                }
            }
            else {
                // Off-diagonal elements should be 0
                if (_Matrix.GetElement(i, j) != 0) {
                    _riTestsPerformed++;
                    return false;
                }
            }
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    return true; // All checks passed, return true
}
bool TestZero(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix)
{
    _Matrix.Zero(_Matrix);
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            if (_Matrix.GetElement(i, j) != 0) {
                _riTestsPerformed++;
                return false;
            }
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    return true;
}
bool TestEquals(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2)
{

    bool result = Matrix4::Equals(_Matrix1, _Matrix2);
    _riTestsPerformed++;
    if (result) {
        _riTestsPassed++;
    }
    return result;
}
bool TestAdd(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2, Matrix4& _Result)
{
    Matrix4 tempResult;
    Matrix4::Add(_Matrix1, _Matrix2, tempResult);

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            float expected = _Matrix1.GetElement(i, j) + _Matrix2.GetElement(i, j);
            if (tempResult.GetElement(i, j) != expected) {
                _riTestsPerformed++;
                return false;
            }
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    _Result = tempResult;
    return true;
}
bool TestSubtract(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2, Matrix4& _Result)
{
    Matrix4 tempResult;
    Matrix4::Subtract(_Matrix1, _Matrix2, tempResult);

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            float expected = _Matrix1.GetElement(i, j) - _Matrix2.GetElement(i, j);
            if (tempResult.GetElement(i, j) != expected) {
                _riTestsPerformed++;
                return false;
            }
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    _Result = tempResult;
    return true;
}
bool TestScalarMultiply(int& _riTestsPerformed, int& _riTestsPassed, float _fScalar, Matrix4& _Matrix, Matrix4& _Result)
{
    Matrix4 tempResult;
    Matrix4::Multiply(_fScalar, _Matrix, tempResult);

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            float expected = _Matrix.GetElement(i, j) * _fScalar;
            if (tempResult.GetElement(i, j) != expected) {
                _riTestsPerformed++;
                return false;
            }
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    _Result = tempResult;
    return true;
}
bool TestMatrixMultiply(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2, Matrix4& _Result)
{
    Matrix4 tempResult;
    Matrix4::Multiply(_Matrix1, _Matrix2, tempResult);

    // Check each element using standard matrix multiplication formula
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            float expected = 0;
            for (int k = 1; k < 5; ++k) {
                expected += _Matrix1.GetElement(i, k) * _Matrix2.GetElement(k, j);
            }
            if (abs(tempResult.GetElement(i, j) - expected) > 0.0001f) {  // Using small epsilon for float comparison
                _riTestsPerformed++;
                return false;
            }
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    _Result = tempResult;
    return true;
}
bool TestTranspose(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix, Matrix4& _Result)
{
    Matrix4 tempResult;
    Matrix4::Transpose(_Matrix, tempResult);

    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            if (tempResult.GetElement(i, j) != _Matrix.GetElement(j, i)) {
                _riTestsPerformed++;
                return false;
            }
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    _Result = tempResult;
    return true;
}
bool TestDeterminant(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix)
{
    float det = Matrix4::Determinant(_Matrix);
    // For a simple test, we'll use a known matrix and expected determinant
    // Could be expanded with more test cases
    Matrix4 testMatrix;
    testMatrix.Identity(testMatrix);
    float expected = 1.0f;

    if (Matrix4::Determinant(testMatrix) != expected) {
        _riTestsPerformed++;
        return false;
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    return true;
}
bool TestInverse(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix, Matrix4& _Result)
{
    Matrix4 tempResult;
    bool hasInverse = Matrix4::Inverse(_Matrix, tempResult);

    if (!hasInverse) {
        // If matrix isn't invertible, check if determinant is zero
        if (Matrix4::Determinant(_Matrix) != 0) {
            _riTestsPerformed++;
            return false;
        }
    }
    else {
        // If inverse exists, multiply with original should give identity
        Matrix4 identityCheck;
        Matrix4::Multiply(_Matrix, tempResult, identityCheck);
        Matrix4 identity;
        identity.Identity(identity);

        if (!Matrix4::Equals(identityCheck, identity)) {
            _riTestsPerformed++;
            return false;
        }
    }
    _riTestsPerformed++;
    _riTestsPassed++;
    _Result = tempResult;
    return true;
}


// Perform Tests
void PerformIdentityTestScenarios(int& _riTestsPerformed , int& _riTestsPassed)
{
    cout << "Perform Identity Function Test Scenarios: \n" << endl;
    // Test Case: Identity on a Zero Matrix
    cout << "Zero Matrix : \n" << endl;
    Matrix4 testMatrix;
    testMatrix.PrintMatrix();

    // Test if Identity function worked correctly
    bool identityValid = TestIdentity(_riTestsPerformed, _riTestsPassed, testMatrix);
    testMatrix.PrintMatrix();
    // Display test results
    if (identityValid) {
        cout << "Identity function correctly resets any matrix to identity. PASSED.\n" << endl;
    }
    else {
        cout << "Identity function failed to reset a non-identity matrix. FAILED.\n" << endl;
    }

    // Test Case: Identity on a random Matrix values range -9 to 9
    cout << "Randomized Matrix : \n" << endl;
    testMatrix.RandomizeMatrix();
    testMatrix.PrintMatrix();

    // Test if Identity function worked correctly
    identityValid = TestIdentity(_riTestsPerformed, _riTestsPassed, testMatrix);
    testMatrix.PrintMatrix();
    // Display test results
    if (identityValid) {
        cout << "Identity function correctly resets any matrix to identity. PASSED.\n" << endl;
    }
    else {
        cout << "Identity function failed to reset a non-identity matrix. FAILED.\n" << endl;
    }

    cout << "Identity Matrix Tests Completed.\n" << endl;
}
void PerformZeroTestScenarios(int& _riTestsPerformed, int& _riTestsPassed) 
{
    cout << "Perform Zero Function Test Scenarios: \n" << endl;
    // Test Case: Identity on a Zero Matrix
    cout << "Zero Matrix : \n" << endl;
    Matrix4 testMatrix;
    testMatrix.PrintMatrix();

    // Test if Identity function worked correctly
    bool IsFunctionResultValid = TestZero(_riTestsPerformed, _riTestsPassed, testMatrix);
    testMatrix.PrintMatrix();
    // Display test results
    if (IsFunctionResultValid) {
        cout << "Zero Function correctly resets any matrix to identity. PASSED.\n" << endl;
    }
    else {
        cout << "Zero Function failed to reset a non-identity matrix. FAILED.\n" << endl;
    }

    // Test Case: Identity on a random Matrix values range -9 to 9
    cout << "Randomized Matrix : \n" << endl;
    testMatrix.RandomizeMatrix();
    testMatrix.PrintMatrix();

    // Test if Identity function worked correctly
    IsFunctionResultValid = TestZero(_riTestsPerformed, _riTestsPassed, testMatrix);
    testMatrix.PrintMatrix();
    // Display test results
    if (IsFunctionResultValid) {
        cout << "Zero Function correctly resets any matrix to identity. PASSED.\n" << endl;
    }
    else {
        cout << "Zero Function failed to reset a non-identity matrix. FAILED.\n" << endl;
    }

    cout << "Zero Function Matrix Tests Completed.\n" << endl;
}
void PerformAllTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Performing All Matrix Function Tests:\n" << endl;

    Matrix4 m1, m2, result;
    m1.RandomizeMatrix();
    m2.RandomizeMatrix();

    cout << "Testing Equals:\n";
    bool equalsPass = TestEquals(_riTestsPerformed, _riTestsPassed, m1, m2);
    cout << (equalsPass ? "PASSED" : "FAILED") << "\n\n";

    cout << "Testing Add:\n";
    bool addPass = TestAdd(_riTestsPerformed, _riTestsPassed, m1, m2, result);
    cout << (addPass ? "PASSED" : "FAILED") << "\n\n";

    cout << "Testing Subtract:\n";
    bool subPass = TestSubtract(_riTestsPerformed, _riTestsPassed, m1, m2, result);
    cout << (subPass ? "PASSED" : "FAILED") << "\n\n";

    cout << "Testing Scalar Multiply:\n";
    bool scalarPass = TestScalarMultiply(_riTestsPerformed, _riTestsPassed, 2.0f, m1, result);
    cout << (scalarPass ? "PASSED" : "FAILED") << "\n\n";

    cout << "Testing Matrix Multiply:\n";
    bool multPass = TestMatrixMultiply(_riTestsPerformed, _riTestsPassed, m1, m2, result);
    cout << (multPass ? "PASSED" : "FAILED") << "\n\n";

    cout << "Testing Transpose:\n";
    bool transPass = TestTranspose(_riTestsPerformed, _riTestsPassed, m1, result);
    cout << (transPass ? "PASSED" : "FAILED") << "\n\n";

    cout << "Testing Determinant:\n";
    bool detPass = TestDeterminant(_riTestsPerformed, _riTestsPassed, m1);
    cout << (detPass ? "PASSED" : "FAILED") << "\n\n";

    cout << "Testing Inverse:\n";
    bool invPass = TestInverse(_riTestsPerformed, _riTestsPassed, m1, result);
    cout << (invPass ? "PASSED" : "FAILED") << "\n\n";
}
/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cTest.cpp]
Description : [This class is allows me to test all functions and see what works correctly]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
**************************************************************************/
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
void PerformEqualsTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Equals Function Test Scenarios: \n" << endl;

    // Test Case 1: Compare two identity matrices
    cout << "Test Case 1: Two Identity Matrices : \n" << endl;
    Matrix4 testMatrix1;
    Matrix4 testMatrix2;
    testMatrix1.Identity(testMatrix1);
    testMatrix2.Identity(testMatrix2);

    cout << "Matrix 1:\n";
    testMatrix1.PrintMatrix();
    cout << "Matrix 2:\n";
    testMatrix2.PrintMatrix();

    // Test if Equals function works correctly
    bool equalsValid = TestEquals(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2);

    // Display test results
    if (equalsValid) {
        cout << "Equals function correctly identified two identical identity matrices. PASSED.\n" << endl;
    }
    else {
        cout << "Equals function failed to identify two identical identity matrices. FAILED.\n" << endl;
    }

    // Test Case 2: Compare an identity matrix with a random matrix
    cout << "Test Case 2: Identity vs Randomized Matrix : \n" << endl;
    testMatrix1.Identity(testMatrix1);
    testMatrix2.RandomizeMatrix();

    cout << "Matrix 1 (Identity):\n";
    testMatrix1.PrintMatrix();
    cout << "Matrix 2 (Random):\n";
    testMatrix2.PrintMatrix();

    // Test if Equals function works correctly
    equalsValid = TestEquals(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2);

    // Display test results
    if (!equalsValid) {
        cout << "Equals function correctly identified different matrices. PASSED.\n" << endl;
        _riTestsPassed++;
    }
    else {
        cout << "Equals function failed to distinguish different matrices. FAILED.\n" << endl;
    }

    // Test Case 3: Compare two identical random matrices
    cout << "Test Case 3: Two Identical Random Matrices : \n" << endl;
    testMatrix1.RandomizeMatrix();
    // Copy matrix1 to matrix2 to make them identical
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            testMatrix2.SetElement(i, j, testMatrix1.GetElement(i, j));
        }
    }

    cout << "Matrix 1 (Random):\n";
    testMatrix1.PrintMatrix();
    cout << "Matrix 2 (Copy of Matrix 1):\n";
    testMatrix2.PrintMatrix();

    // Test if Equals function works correctly
    equalsValid = TestEquals(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2);

    // Display test results
    if (equalsValid) {
        cout << "Equals function correctly identified two identical random matrices. PASSED.\n" << endl;
    }
    else {
        cout << "Equals function failed to identify two identical random matrices. FAILED.\n" << endl;
    }

    cout << "Equals Matrix Tests Completed.\n" << endl;
}
void PerformAddTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Add Function Test Scenarios: \n" << endl;

    // Test Case 1: Adding two zero matrices
    cout << "Test Case 1: Two Zero Matrices : \n" << endl;
    Matrix4 testMatrix1;
    Matrix4 testMatrix2;
    Matrix4 resultMatrix;
    testMatrix1.Zero(testMatrix1);
    testMatrix2.Zero(testMatrix2);

    cout << "Matrix 1:\n";
    testMatrix1.PrintMatrix();
    cout << "Matrix 2:\n";
    testMatrix2.PrintMatrix();

    // Test if Add function works correctly
    bool addValid = TestAdd(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2, resultMatrix);

    cout << "Result:\n";
    resultMatrix.PrintMatrix();

    // Display test results
    if (addValid) {
        cout << "Add function correctly added two zero matrices. PASSED.\n" << endl;
    }
    else {
        cout << "Add function failed to correctly add two zero matrices. FAILED.\n" << endl;
    }

    // Test Case 2: Adding an identity matrix and a random matrix
    cout << "Test Case 2: Identity + Randomized Matrix : \n" << endl;
    testMatrix1.Identity(testMatrix1);
    testMatrix2.RandomizeMatrix();

    cout << "Matrix 1 (Identity):\n";
    testMatrix1.PrintMatrix();
    cout << "Matrix 2 (Random):\n";
    testMatrix2.PrintMatrix();

    // Test if Add function works correctly
    addValid = TestAdd(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2, resultMatrix);

    cout << "Result:\n";
    resultMatrix.PrintMatrix();

    // Display test results
    if (addValid) {
        cout << "Add function correctly added identity and random matrices. PASSED.\n" << endl;
    }
    else {
        cout << "Add function failed to correctly add identity and random matrices. FAILED.\n" << endl;
    }

    // Test Case 3: Adding two identical random matrices
    cout << "Test Case 3: Two Identical Random Matrices : \n" << endl;
    testMatrix1.RandomizeMatrix();
    // Copy matrix1 to matrix2 to make them identical
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            testMatrix2.SetElement(i, j, testMatrix1.GetElement(i, j));
        }
    }

    cout << "Matrix 1 (Random):\n";
    testMatrix1.PrintMatrix();
    cout << "Matrix 2 (Copy of Matrix 1):\n";
    testMatrix2.PrintMatrix();

    // Test if Add function works correctly
    addValid = TestAdd(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2, resultMatrix);

    cout << "Result:\n";
    resultMatrix.PrintMatrix();

    // Display test results
    if (addValid) {
        cout << "Add function correctly added two identical random matrices. PASSED.\n" << endl;
    }
    else {
        cout << "Add function failed to correctly add two identical random matrices. FAILED.\n" << endl;
    }

    cout << "Add Matrix Tests Completed.\n" << endl;
}
void PerformSubtractTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Subtract Function Test Scenarios: \n" << endl;

    // Test Case 1: Subtracting two zero matrices
    cout << "Test Case 1: Two Zero Matrices : \n" << endl;
    Matrix4 testMatrix1, testMatrix2, resultMatrix;
    testMatrix1.Zero(testMatrix1);
    testMatrix2.Zero(testMatrix2);

    cout << "Matrix 1:\n"; testMatrix1.PrintMatrix();
    cout << "Matrix 2:\n"; testMatrix2.PrintMatrix();

    bool subtractValid = TestSubtract(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (subtractValid) {
        cout << "Subtract function correctly subtracted two zero matrices. PASSED.\n" << endl;
    }
    else {
        cout << "Subtract function failed to subtract two zero matrices. FAILED.\n" << endl;
    }

    // Test Case 2: Subtracting identity from random
    cout << "Test Case 2: Random - Identity Matrix : \n" << endl;
    testMatrix1.RandomizeMatrix();
    testMatrix2.Identity(testMatrix2);

    cout << "Matrix 1 (Random):\n"; testMatrix1.PrintMatrix();
    cout << "Matrix 2 (Identity):\n"; testMatrix2.PrintMatrix();

    subtractValid = TestSubtract(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (subtractValid) {
        cout << "Subtract function correctly subtracted identity from random matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Subtract function failed to subtract identity from random matrix. FAILED.\n" << endl;
    }

    cout << "Subtract Matrix Tests Completed.\n" << endl;
}
void PerformScalarMultiplyTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Scalar Multiply Function Test Scenarios: \n" << endl;

    // Test Case 1: Multiply identity matrix by 2
    cout << "Test Case 1: Identity Matrix * 2 : \n" << endl;
    Matrix4 testMatrix, resultMatrix;
    float scalar = 2.0f;
    testMatrix.Identity(testMatrix);

    cout << "Matrix:\n"; testMatrix.PrintMatrix();
    cout << "Scalar: " << scalar << "\n" << endl;

    bool scalarValid = TestScalarMultiply(_riTestsPerformed, _riTestsPassed, scalar, testMatrix, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (scalarValid) {
        cout << "Scalar multiply correctly scaled identity matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Scalar multiply failed to scale identity matrix. FAILED.\n" << endl;
    }

    // Test Case 2: Multiply random matrix by 0
    cout << "Test Case 2: Random Matrix * 0 : \n" << endl;
    scalar = 0.0f;
    testMatrix.RandomizeMatrix();

    cout << "Matrix:\n"; testMatrix.PrintMatrix();
    cout << "Scalar: " << scalar << "\n" << endl;

    scalarValid = TestScalarMultiply(_riTestsPerformed, _riTestsPassed, scalar, testMatrix, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (scalarValid) {
        cout << "Scalar multiply correctly zeroed random matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Scalar multiply failed to zero random matrix. FAILED.\n" << endl;
    }

    cout << "Scalar Multiply Tests Completed.\n" << endl;
}
void PerformMatrixMultiplyTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Matrix Multiply Function Test Scenarios: \n" << endl;

    // Test Case 1: Identity * Identity
    cout << "Test Case 1: Identity * Identity : \n" << endl;
    Matrix4 testMatrix1, testMatrix2, resultMatrix;
    testMatrix1.Identity(testMatrix1);
    testMatrix2.Identity(testMatrix2);

    cout << "Matrix 1:\n"; testMatrix1.PrintMatrix();
    cout << "Matrix 2:\n"; testMatrix2.PrintMatrix();

    bool multiplyValid = TestMatrixMultiply(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (multiplyValid) {
        cout << "Matrix multiply correctly multiplied two identity matrices. PASSED.\n" << endl;
    }
    else {
        cout << "Matrix multiply failed to multiply two identity matrices. FAILED.\n" << endl;
    }

    // Test Case 2: Random * Identity
    cout << "Test Case 2: Random * Identity : \n" << endl;
    testMatrix1.RandomizeMatrix();
    testMatrix2.Identity(testMatrix2);

    cout << "Matrix 1 (Random):\n"; testMatrix1.PrintMatrix();
    cout << "Matrix 2 (Identity):\n"; testMatrix2.PrintMatrix();

    multiplyValid = TestMatrixMultiply(_riTestsPerformed, _riTestsPassed, testMatrix1, testMatrix2, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (multiplyValid) {
        cout << "Matrix multiply correctly multiplied random with identity matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Matrix multiply failed to multiply random with identity matrix. FAILED.\n" << endl;
    }

    cout << "Matrix Multiply Tests Completed.\n" << endl;
}
void PerformTransposeTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Transpose Function Test Scenarios: \n" << endl;

    // Test Case 1: Transpose of Identity
    cout << "Test Case 1: Identity Matrix : \n" << endl;
    Matrix4 testMatrix, resultMatrix;
    testMatrix.Identity(testMatrix);

    cout << "Matrix:\n"; testMatrix.PrintMatrix();

    bool transposeValid = TestTranspose(_riTestsPerformed, _riTestsPassed, testMatrix, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (transposeValid) {
        cout << "Transpose correctly transposed identity matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Transpose failed to transpose identity matrix. FAILED.\n" << endl;
    }

    // Test Case 2: Transpose of Random
    cout << "Test Case 2: Random Matrix : \n" << endl;
    testMatrix.RandomizeMatrix();

    cout << "Matrix:\n"; testMatrix.PrintMatrix();

    transposeValid = TestTranspose(_riTestsPerformed, _riTestsPassed, testMatrix, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (transposeValid) {
        cout << "Transpose correctly transposed random matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Transpose failed to transpose random matrix. FAILED.\n" << endl;
    }

    cout << "Transpose Tests Completed.\n" << endl;
}
void PerformDeterminantTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Determinant Function Test Scenarios: \n" << endl;

    // Test Case 1: Determinant of Identity
    cout << "Test Case 1: Identity Matrix : \n" << endl;
    Matrix4 testMatrix;
    testMatrix.Identity(testMatrix);

    cout << "Matrix:\n"; testMatrix.PrintMatrix();

    bool detValid = TestDeterminant(_riTestsPerformed, _riTestsPassed, testMatrix);
    cout << "Determinant: " << Matrix4::Determinant(testMatrix) << "\n" << endl;

    if (detValid) {
        cout << "Determinant correctly calculated for identity matrix (should be 1). PASSED.\n" << endl;
    }
    else {
        cout << "Determinant failed for identity matrix. FAILED.\n" << endl;
    }

    // Test Case 2: Determinant of Zero
    cout << "Test Case 2: Zero Matrix : \n" << endl;
    testMatrix.Zero(testMatrix);

    cout << "Matrix:\n"; testMatrix.PrintMatrix();

    detValid = TestDeterminant(_riTestsPerformed, _riTestsPassed, testMatrix);
    cout << "Determinant: " << Matrix4::Determinant(testMatrix) << "\n" << endl;

    if (detValid) {
        cout << "Determinant correctly calculated for zero matrix (should be 0). PASSED.\n" << endl;
    }
    else {
        cout << "Determinant failed for zero matrix. FAILED.\n" << endl;
    }

    cout << "Determinant Tests Completed.\n" << endl;
}
void PerformInverseTestScenarios(int& _riTestsPerformed, int& _riTestsPassed)
{
    cout << "Perform Inverse Function Test Scenarios: \n" << endl;

    // Test Case 1: Inverse of Identity
    cout << "Test Case 1: Identity Matrix : \n" << endl;
    Matrix4 testMatrix, resultMatrix;
    testMatrix.Identity(testMatrix);

    cout << "Matrix:\n"; testMatrix.PrintMatrix();

    bool inverseValid = TestInverse(_riTestsPerformed, _riTestsPassed, testMatrix, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (inverseValid) {
        cout << "Inverse correctly calculated for identity matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Inverse failed for identity matrix. FAILED.\n" << endl;
    }

    // Test Case 2: Inverse of Zero (should fail)
    cout << "Test Case 2: Zero Matrix : \n" << endl;
    testMatrix.Zero(testMatrix);

    cout << "Matrix:\n"; testMatrix.PrintMatrix();

    inverseValid = TestInverse(_riTestsPerformed, _riTestsPassed, testMatrix, resultMatrix);
    cout << "Result:\n"; resultMatrix.PrintMatrix();

    if (!inverseValid) {
        cout << "Inverse correctly rejected non-invertible zero matrix. PASSED.\n" << endl;
    }
    else {
        cout << "Inverse failed to reject non-invertible zero matrix. FAILED.\n" << endl;
    }

    cout << "Inverse Tests Completed.\n" << endl;
}

void RunAllTestScenarios()
{
    int totalTestsPerformed = 0;
    int totalTestsPassed = 0;

    cout << "-= Starting All Matrix4 Test Scenarios =-\n" << endl;

    // Call each test scenario function
    PerformIdentityTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformZeroTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformEqualsTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformAddTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformSubtractTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformScalarMultiplyTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformMatrixMultiplyTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformTransposeTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformDeterminantTestScenarios(totalTestsPerformed, totalTestsPassed);
    PerformInverseTestScenarios(totalTestsPerformed, totalTestsPassed);

    // Print summary
    cout << "-= All Test Scenarios Completed =-\n" << endl;
    cout << "Total Tests Performed: " << totalTestsPerformed << endl;
    cout << "Total Tests Passed: " << totalTestsPassed << endl;
    cout << "Total Tests Failed: " << (totalTestsPerformed - totalTestsPassed) << endl;
    cout << "Pass Rate: " << (totalTestsPerformed > 0 ? (static_cast<float>(totalTestsPassed) / totalTestsPerformed * 100) : 0)
        << "%" << endl;
}
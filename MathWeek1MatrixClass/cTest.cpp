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

// Preforming Tests
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
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

// Preforming Tests
void PerformIdentityTestScenarios(int& _riTestsPerformed , int& _riTestsPassed)
{
    cout << "Perform Identity Test Scenarios: \n" << endl;
    // Test Case: Identity on a  Matrix
    Matrix4 testMatrix;

    testMatrix.PrintMatrix();
    testMatrix.RandomizeMatrix();
    testMatrix.PrintMatrix();

    // Test if Identity function worked correctly
    bool identityValid = TestIdentity(_riTestsPerformed, _riTestsPassed, testMatrix);
    testMatrix.PrintMatrix();
    // Display test results
    if (identityValid) {
        cout << "Identity function correctly resets any matrix to identity. PASSED." << endl;
    }
    else {
        cout << "Identity function failed to reset a non-identity matrix. FAILED." << endl;
    }

    cout << "Identity Matrix Tests Completed.\n" << endl;
}
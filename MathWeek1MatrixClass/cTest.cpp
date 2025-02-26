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
                    return false;
                }
            }
            else {
                // Off-diagonal elements should be 0
                if (_Matrix.GetElement(i, j) != 0) {
                    return false;
                }
            }
        }
    }

    return true; // All checks passed, return true
}

// Preforming Tests

void PerformIdentityTestScenarios(int& _riTestsPerformed , int& _riTestsPassed)
{
    cout << "Perform Identity Test Scenarios:" << endl;

    // Test Case: Identity on a Non-Zero Matrix
    Matrix4 testMatrix;
    testMatrix.SetElement(0, 0, 5);
    testMatrix.SetElement(1, 2, -3);
    testMatrix.SetElement(3, 3, 9);

    testMatrix.PrintMatrix();

    testMatrix.Identity(testMatrix); // Apply Identity()

    bool identityValid = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if ((i == j && testMatrix.GetElement(i, j) != 1) ||
                (i != j && testMatrix.GetElement(i, j) != 0)) {
                identityValid = false;
            }
        }
    }

    if (identityValid) {
        cout << "Identity function correctly resets any matrix to identity. PASSED.\n";
    }
    else {
        cout << "Identity function failed to reset a non-identity matrix. FAILED.\n";
    }

    cout << "Identity Matrix Tests Completed.\n";
}
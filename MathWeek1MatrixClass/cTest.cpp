#pragma once
#include "cTest.h"
#include "cMatrix4.h"

// Written Tests
bool TestIdentity()
{
    Matrix4 testMatrix;
    testMatrix.Identity(testMatrix);

    // Check each element in the matrix (1-based indexing)
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            if (i == j) {
                // Diagonal elements should be 1
                if (testMatrix.GetElement(i, j) != 1) {
                    return false;
                }
            }
            else {
                // Off-diagonal elements should be 0
                if (testMatrix.GetElement(i, j) != 0) {
                    return false;
                }
            }
        }
    }

    return true; // All checks passed, return true
}

// Preforming Tests

void PerformIdentityTestScenarios()
{

}
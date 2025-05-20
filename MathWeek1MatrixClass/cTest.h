/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cTest.h]
Description : [This class is allows me to test all functions and see what works correctly]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cMatrix4.h"

bool TestIdentity(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix);
bool TestZero(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix);
bool TestEquals(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2);
bool TestAdd(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2, Matrix4& _Result);
bool TestSubtract(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2, Matrix4& _Result);
bool TestScalarMultiply(int& _riTestsPerformed, int& _riTestsPassed, float _fScalar, Matrix4& _Matrix, Matrix4& _Result);
bool TestMatrixMultiply(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix1, Matrix4& _Matrix2, Matrix4& _Result);
bool TestTranspose(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix, Matrix4& _Result);
bool TestDeterminant(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix);
bool TestInverse(int& _riTestsPerformed, int& _riTestsPassed, Matrix4& _Matrix, Matrix4& _Result);

void PerformIdentityTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformZeroTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformEqualsTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformAddTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformSubtractTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformScalarMultiplyTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformMatrixMultiplyTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformTransposeTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformDeterminantTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);
void PerformInverseTestScenarios(int& _riTestsPerformed, int& _riTestsPassed);

void RunAllTestScenarios();
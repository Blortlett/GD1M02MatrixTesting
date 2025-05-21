/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAssignmentOperations.h]
Description : [This class is what will trigger matrix operations one by one as per assignment brief]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cMatrix4.h"

class cAssignmentOperations
{
private:
	static const Matrix4 MatrixA;
	static const Matrix4 MatrixB;
public:
	// Assignment tasks
	float DeterminantA();
	Matrix4 TransposeA();
	Matrix4 InverseA();
	Matrix4 MultiplyAByScalar();
	Matrix4 APlusB();
	Matrix4 AMinusB();
	Matrix4 AMultiplyByB();
	Matrix4 BMultiplyByA();
	Matrix4 IdentityMatrixA();
	Matrix4 IdentityMatrixB();

	// Printers
	void PrintMatrixA() const { MatrixA.PrintMatrix(); }

	// Getters
	static Matrix4 GetMatrixA() { return MatrixA; }
	static Matrix4 GetMatrixB() { return MatrixB; }
};
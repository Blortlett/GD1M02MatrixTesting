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
#include "cAssignmentOperations.h"

float cAssignmentOperations::DeterminantA()
{
	float Determinant = Matrix4::Determinant(MatrixA);
	return Determinant;
}

Matrix4 cAssignmentOperations::TransposeA()
{
	Matrix4 TransposeOfA = GetMatrixA();
	Matrix4::Transpose(GetMatrixA(), TransposeOfA);
	return TransposeOfA;
}

Matrix4 cAssignmentOperations::InverseA()
{
	return Matrix4();
}

Matrix4 cAssignmentOperations::MultiplyAByScalar()
{
	return Matrix4();
}

Matrix4 cAssignmentOperations::APlusB()
{
	return Matrix4();
}

Matrix4 cAssignmentOperations::AMinusB()
{
	return Matrix4();
}

Matrix4 cAssignmentOperations::AMultiplyByB()
{
	return Matrix4();
}

Matrix4 cAssignmentOperations::BMultiplyByA()
{
	return Matrix4();
}

Matrix4 cAssignmentOperations::IdentityMatrixA()
{
	return Matrix4();
}

Matrix4 cAssignmentOperations::IdentityMatrixB()
{
	return Matrix4();
}

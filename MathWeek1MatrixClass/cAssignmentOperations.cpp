/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cAssignmentOperations.h]
Description : [This class is what will trigger matrix operations one by one as per assignment brief]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
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
	Matrix4 InverseOfA = GetMatrixA();
	Matrix4::Inverse(GetMatrixA(), InverseOfA);
	return InverseOfA;
}

Matrix4 cAssignmentOperations::MultiplyAByScalar()
{
	Matrix4 ScalarMultMatrix = GetMatrixA();
	Matrix4::Multiply(ScalarValue, GetMatrixA(), ScalarMultMatrix);
	return ScalarMultMatrix;
}

Matrix4 cAssignmentOperations::APlusB()
{
	Matrix4 Result;
	Matrix4::Add(GetMatrixA(), GetMatrixB(), Result);
	return Result;
}

Matrix4 cAssignmentOperations::AMinusB()
{
	Matrix4 Result;
	Matrix4::Subtract(GetMatrixA(), GetMatrixB(), Result);
	return Result;
}

Matrix4 cAssignmentOperations::AMultiplyByB()
{
	Matrix4 Result;
	Matrix4::Multiply(GetMatrixA(), GetMatrixB(), Result);
	return Result;
}

Matrix4 cAssignmentOperations::BMultiplyByA()
{
	Matrix4 Result;
	Matrix4::Multiply(GetMatrixB(), GetMatrixA(), Result);
	return Result;
}

Matrix4 cAssignmentOperations::IdentityMatrixA()
{
	Matrix4 Result = GetMatrixA();
	Matrix4::Identity(Result);
	return Result;
}

Matrix4 cAssignmentOperations::IdentityMatrixB()
{
	Matrix4 Result = GetMatrixB();
	Matrix4::Identity(Result);
	return Result;
}

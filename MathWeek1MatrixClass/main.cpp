/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [main.cpp]
Description : [App starts here]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/

// 4x4 Matrix class
#include "cAssignmentOperations.h"
/*
// Test Class
#include "cTest.h"
// Random number stuff
#include <cstdlib>
#include <ctime>
#include <initializer_list>
*/


//void SeedRandom();

int main()
{
	cAssignmentOperations Operations;

	// Operation 1)
	std::cout << "Question 1) Determinant of A:" << std::endl;
	std::cout << "Matrix A:" << std::endl;
	Operations.PrintMatrixA();
	std::cout << "Determinant of A: " << Operations.DeterminantA() << "\n" << std::endl;

	// Operation 2)
	std::cout << "Question 2) Transpose of A:" << std::endl;
	std::cout << "Matrix A:" << std::endl;
	Operations.PrintMatrixA();
	std::cout << "Transpose of A:" << std::endl;
	Operations.TransposeA().PrintMatrix();
	std::cout << "\n" << std::endl;

	// Operation 3)
	std::cout << "Question 3) Inverse of A:" << std::endl;
	std::cout << "Matrix A:" << std::endl;
	Operations.PrintMatrixA();
	std::cout << "Inverse of A:" << std::endl;
	Operations.InverseA().PrintMatrix();
	std::cout << "\n" << std::endl;

	// Operation 4)
	std::cout << "Question 4) Multiply A by scalar Value:" << std::endl;
	std::cout << "Matrix A:" << std::endl;
	Operations.PrintMatrixA();
	std::cout << "A * Scalar:" << std::endl;
	Operations.InverseA().PrintMatrix();
	std::cout << "\n" << std::endl;

	/*
	SeedRandom();
	int iTestsPerformed = 0;
	int iTestsPassed = 0;

	RunAllTestScenarios();

	return 0;
	*/
}

/*
void SeedRandom() {
	std::srand(std::time({}));
}
*/
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
	std::cout << "Matrix A:" << std::endl;
	Operations.PrintMatrixA();
	std::cout << "Determinant of A: " << Operations.DeterminantA() << "\n" << std::endl;

	// Operation 2)
	std::cout << "Matrix A:" << std::endl;
	Operations.PrintMatrixA();
	std::cout << "\nDeterminant of A: " << Operations.DeterminantA() << std::endl;
	Operations.TransposeA().PrintMatrix();
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
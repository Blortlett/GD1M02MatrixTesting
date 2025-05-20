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
#include "cMatrix4.h"
// Test Class
#include "cTest.h"
// Random number stuff
#include <cstdlib>
#include <ctime>
#include <initializer_list>


void SeedRandom();

int main()
{
	SeedRandom();
	int iTestsPerformed = 0;
	int iTestsPassed = 0;

	RunAllTestScenarios();

	return 0;
}

void SeedRandom() {
	std::srand(std::time({}));
}






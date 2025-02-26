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
	int iTestsPreformed = 0;
	int iTestsPassed = 0;

	PerformIdentityTestScenarios(iTestsPreformed, iTestsPassed);
	


	return 0;
}

void SeedRandom() {
	std::srand(std::time({}));
}






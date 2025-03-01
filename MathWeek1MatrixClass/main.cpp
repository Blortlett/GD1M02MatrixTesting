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

	PerformIdentityTestScenarios(iTestsPerformed, iTestsPassed);
	PerformZeroTestScenarios(iTestsPerformed, iTestsPassed);
	PerformAllTestScenarios(iTestsPerformed, iTestsPassed);

	cout << "Tests Performed: " << iTestsPerformed << endl;
	cout << "Tests Passed: " << iTestsPassed << endl;
	cout << "Tests Failed: " << (iTestsPerformed - iTestsPassed) << endl;

	return 0;
}

void SeedRandom() {
	std::srand(std::time({}));
}






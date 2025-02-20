// 4x4 Matrix class
#include "cMatrix4.h"
// Random number stuff
#include <cstdlib>
#include <ctime>
#include <initializer_list>

const int MAX_RAND_NUMBER = 19;
void SeedRandom();
int RandomInt();
void RandomizeMatrix(Matrix4* _matrix);
void PrintMatrix(Matrix4* _matrix);

int main()
{
	Matrix4 Matrix;
	SeedRandom();

	RandomizeMatrix(&Matrix);
	PrintMatrix(&Matrix);

	return 0;
}

void SeedRandom() {
	std::srand(std::time({}));
}

int RandomInt() {
	return (std::rand() % MAX_RAND_NUMBER) - 9;
}

void RandomizeMatrix(Matrix4* _matrix) {
	// NullCheck
	if (_matrix == nullptr) 
		throw std::runtime_error("Error: Matrix is null");
	// Loop through matrix and assign random number
	int randNumber;

	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			randNumber = RandomInt();
			_matrix->SetElement(xIndex, yIndex, randNumber);
		}
	}
}

void PrintMatrix(Matrix4* _matrix)
{
	for (int xIndex = 1; xIndex < 5; ++xIndex) {
		for (int yIndex = 1; yIndex < 5; ++yIndex) {
			// If matrix[x][y] is a positive number, print it with an extra space to align everything    // The turnary might make the code more confusing but I am trying to learn them
			cout << (_matrix->GetElement(xIndex, yIndex) < 0 ? " " : "  ") << _matrix->GetElement(xIndex, yIndex);
		}
		cout << endl;
	}
}
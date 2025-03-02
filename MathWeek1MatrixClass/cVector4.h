#pragma once
#include <iostream>

class Vector4
{
public:
	float x, y, z, w;
	Vector4() : x(0), y(0), z(0), w(0) {}

	void Display() const {
		std::cout << "Vector4(" << x << ", " << y << ", " << z << ", " << w << ")\n" << std::endl;
	}
};
/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cVector4.h]
Description : [This class lets me store, use and print to screen vector4s]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
**************************************************************************/
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
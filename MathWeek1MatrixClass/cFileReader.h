/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cFileReader.h]
Description : [Reads input file and passes to the matrix calculator]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
**************************************************************************/

#include <string>
#include "cMatrix4.h"

#pragma once
class cFileReader
{
private:
	const std::string mFileAddress = "Input/Input.txt";

	Matrix4 mMatrix1;
	Matrix4 mMatrix2;
	float mValue;

	void LoadFile();

public:
	cFileReader();

};


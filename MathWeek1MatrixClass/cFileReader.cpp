/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cFileReader.cpp]
Description : [Reads input file and passes to the matrix calculator]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
**************************************************************************/

#include "cFileReader.h"

#include <fstream>
#include <iostream>

void cFileReader::LoadFile()
{
	std::fstream File;
	File.open(mFileAddress);	//Opens file

	if (!File.is_open())	//If file not found
	{
		return;
	}

	std::string Line;
	int LineNum = 0;

	int Index = 0;
	int SpaceIndexs[3];

	//Goes down the file line by line until end of file is reached
	for (int j = 0; j < 4; j++)	//For every row in matrix
	{
		std::getline(File, Line);

		//
		//Retrieval of data
		//
		for (int i = 0; i < Line.length(); i++)	//For each char in line
		{
			switch (Line[i])
			{
			case ' ':
				SpaceIndexs[Index] = i;
				Index++;
				break;
			default:
				break;
			}
		}
		Index = 0;
		LineNum++;

		//
		//Sets elements in matrix
		//
		mMatrix1.SetElement(0, j, std::stof(Line.substr(0, SpaceIndexs[0] + 1)));
		mMatrix1.SetElement(1, j, std::stof(Line.substr(SpaceIndexs[0] + 1, SpaceIndexs[1] - SpaceIndexs[0] + 1)));
		mMatrix1.SetElement(2, j, std::stof(Line.substr(SpaceIndexs[1] + 1, SpaceIndexs[2] - SpaceIndexs[1] + 1)));
		mMatrix1.SetElement(3, j, std::stof(Line.substr(SpaceIndexs[2] + 1)));

		//std::cout << mMatrix1.GetElement(0, j) << std::endl;
		//std::cout << mMatrix1.GetElement(1, j) << std::endl;
		//std::cout << mMatrix1.GetElement(2, j) << std::endl;
		//std::cout << mMatrix1.GetElement(3, j) << std::endl;

	}

	std::getline(File, Line);

	//Goes down the file line by line until end of file is reached
	for (int j = 0; j < 4; j++)	//For every row in matrix
	{
		std::getline(File, Line);

		//
		//Retrieval of data
		//
		for (int i = 0; i < Line.length(); i++)	//For each char in line
		{
			switch (Line[i])
			{
			case ' ':
				SpaceIndexs[Index] = i;
				Index++;
				break;
			default:
				break;
			}
		}
		Index = 0;
		LineNum++;

		//
		//Sets elements in matrix
		//
		mMatrix2.SetElement(0, j, std::stof(Line.substr(0, SpaceIndexs[0] + 1)));
		mMatrix2.SetElement(1, j, std::stof(Line.substr(SpaceIndexs[0] + 1, SpaceIndexs[1] - SpaceIndexs[0] + 1)));
		mMatrix2.SetElement(2, j, std::stof(Line.substr(SpaceIndexs[1] + 1, SpaceIndexs[2] - SpaceIndexs[1] + 1)));
		mMatrix2.SetElement(3, j, std::stof(Line.substr(SpaceIndexs[2] + 1)));

		//std::cout << mMatrix1.GetElement(0, j) << std::endl;
		//std::cout << mMatrix1.GetElement(1, j) << std::endl;
		//std::cout << mMatrix1.GetElement(2, j) << std::endl;
		//std::cout << mMatrix1.GetElement(3, j) << std::endl;

	}

	std::getline(File, Line);
	std::getline(File, Line);

	mValue = std::stof(Line);

	std::cout << mValue << std::endl;

	File.close();	//Closes file
}

cFileReader::cFileReader()
{
	LoadFile();
}

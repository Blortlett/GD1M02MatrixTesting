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

void cFileReader::LoadFile(Matrix4& Matrix1, Matrix4& Matrix2, int& scalar)
{
	// Open file
	std::fstream File;
	File.open(mFileAddress);
	// check its open
	if (!File.is_open())	//If file not found
	{
		std::cout << "Error: File not found." << std::endl;
		return;
	} 

	// Line reading variables
	std::string Line;
	std::vector<std::string> Tokens;
	std::string Delimiter = " ";
	int lineCount = 0;

	// Read only the first 4 lines - Load Matrix 1
	while (std::getline(File, Line) && lineCount < 4) 
	{

		// Tokenize the current line
		Tokenize(Line, Tokens, Delimiter);

		// Check if we have enough tokens for a 4x4 matrix
		if (Tokens.size() >= 16) 
		{
			Matrix4 matrix;
			Matrix1.LoadMatrix(Tokens); // Load tokens into matrix
		}
		// Else: Repeat until Tokens.size() = 16

		lineCount++;
	}


	// Reset lineCount
	lineCount = 0;
	//clear the tokens vector
	if (Tokens.size() > 0)
	{
		Tokens.erase(Tokens.begin(), Tokens.end());
	}


	// Read next 5 lines - Load matrix 2
	while (std::getline(File, Line) && lineCount < 5) 
	{
		// Tokenize the current line
		Tokenize(Line, Tokens, Delimiter);

		// Check if we have enough tokens for a 4x4 matrix
		if (Tokens.size() >= 16) 
		{
			Matrix4 matrix;
			Matrix2.LoadMatrix(Tokens); // Load tokens into matrix
		}
		// Else: Repeat until Tokens.size() = 16

		lineCount++;
	}

	// Skip a line then load scalar value
	std::getline(File, Line);
	std::getline(File, Line);
	scalar = std::stoi(Line);


	File.close();	//Closes file
}

void cFileReader::Tokenize(const string& sSource, std::vector<string>& vTokens, const string& sDelimiter)
{
	// Skip delimiters at beginning.
	string::size_type lastPos = sSource.find_first_not_of(sDelimiter, 0);

	// Find first "non-delimiter".
	string::size_type pos = sSource.find_first_of(sDelimiter, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// Found a token, add it to the vector.
		vTokens.push_back(sSource.substr(lastPos, pos - lastPos));

		// Skip delimiters.  Note the "not_of"
		lastPos = sSource.find_first_not_of(sDelimiter, pos);

		// Find next "non-delimiter"
		pos = sSource.find_first_of(sDelimiter, lastPos);
	}
}


cFileReader::cFileReader()
{
	
}

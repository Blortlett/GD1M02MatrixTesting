/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMainMenu.cpp]
Description : [Implementation of interactive menu for matrix operations]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
**************************************************************************/
#include "cMainMenu.h"
#include <iostream>
#include <limits>

cMainMenu::cMainMenu() {
    // Load matrices and scalar from file
    mFileReader.LoadFile(mMatrix1, mMatrix2, mScalar);
    std::cout << "Loaded Matrix1:\n";
    mMatrix1.PrintMatrix();
    std::cout << "Loaded Matrix2:\n";
    mMatrix2.PrintMatrix();
    std::cout << "Loaded Scalar: " << mScalar << "\n\n";
}

void cMainMenu::Menu()
{
    // print main menu
    cout << "\n    Main Menu" << endl;
    cout << "-----------------" << endl;
    cout << " 1) Uniform Scaling" << endl;
    cout << " 2) Non-Uniform Scaling" << endl;
    cout << " 3) Translation" << endl;
    cout << " 4) Rotation about XYZ" << endl;
    cout << " 5) Projection about XYZ" << endl;
    cout << " 9) Quit Program" << endl;

    // prompt user input
    int userSelection;
    cout << "Enter selection: ";
    cin >> userSelection;



    switch (userSelection)
    {
    case 1: // Scaling Operations
        PerformScaleUniform(mMatrix1);
        break;
    case 2: // Scaling Operations
        PerformScaleNonuniform(mMatrix1);
        break;
    case 3: // Translation Operations
        PerformTranslate(mMatrix1);
        break;
    case 4: // Rotation Operations
        PerformRotate(mMatrix1);
        break;
    case 5: // Projection Operations
        PerformProject(mMatrix1);
        break;
    case 9: // Quit Program
        mbRunning = false;
        break;
    default:
        cout << "I didn't quite catch that, try again..." << endl;
        break;
    }

}


void cMainMenu::UpdateMenu() {
    while (mbRunning)
    {
        Menu();
    }
}

void cMainMenu::PerformScaleUniform(Matrix4& _rMatrix) {
    float scale = GetFloatInput("Enter uniform scale factor: ");
    Matrix4 result;
    Vector4 vec;
    Matrix4::ScaleUniform(scale, vec, result);
    std::cout << "Resulting Uniform Scale Matrix:\n";
    result.PrintMatrix();
}

void cMainMenu::PerformScaleNonuniform(Matrix4& _rMatrix) {
    float scaleX = GetFloatInput("Enter X scale factor: ");
    float scaleY = GetFloatInput("Enter Y scale factor: ");
    float scaleZ = GetFloatInput("Enter Z scale factor: ");
    Matrix4 result;
    Vector4 vec;
    Matrix4::ScaleNonUniform(scaleX, scaleY, scaleZ, vec, result);
    std::cout << "Resulting Non-Uniform Scale Matrix:\n";
    result.PrintMatrix();
}

void cMainMenu::PerformTranslate(Matrix4& _rMatrix) {
    float transX = GetFloatInput("Enter X translation: ");
    float transY = GetFloatInput("Enter Y translation: ");
    float transZ = GetFloatInput("Enter Z translation: ");
    Matrix4 result;
    Vector4 vec;
    Matrix4::Translation(transX, transY, transZ, vec, result);
    std::cout << "Resulting Translation Matrix:\n";
    result.PrintMatrix();
}

void cMainMenu::PerformRotate(Matrix4& _rMatrix) {
    float angleX = GetFloatInput("Enter X rotation angle (in radians): ");
    float angleY = GetFloatInput("Enter Y rotation angle (in radians): ");
    float angleZ = GetFloatInput("Enter Z rotation angle (in radians): ");
    Matrix4 result;
    Vector4 vec;
    Matrix4::RotationXYZ(angleX, angleY, angleZ, vec, result);
    std::cout << "Resulting Rotation Matrix:\n";
    result.PrintMatrix();
}

void cMainMenu::PerformProject(Matrix4& _rMatrix) {
    bool projX = GetBoolInput("Project onto X-axis? (y/n): ");
    bool projY = GetBoolInput("Project onto Y-axis? (y/n): ");
    bool projZ = GetBoolInput("Project onto Z-axis? (y/n): ");
    Matrix4 result;
    Vector4 vec;
    Matrix4::ProjectionXYZ(projX, projY, projZ, vec, result);
    std::cout << "Resulting Projection Matrix:\n";
    result.PrintMatrix();
}

float cMainMenu::GetFloatInput(const std::string& _prompt) {
    std::cout << _prompt;
    float value;
    while (!(std::cin >> value)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

bool cMainMenu::GetBoolInput(const std::string& _prompt) {
    std::cout << _prompt;
    char input;
    while (true) {
        input = std::cin.get();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (input == 'y' || input == 'Y') return true;
        if (input == 'n' || input == 'N') return false;
        std::cout << "Invalid input. Please enter 'y' or 'n': ";
    }
}
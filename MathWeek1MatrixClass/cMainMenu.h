/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMainMenu.h]
Description : [Interactive menu to perform matrix transformations]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz, Oliver.NooneJones@mds.ac.nz]
**************************************************************************/
#pragma once
#include "cMatrix4.h"
#include "cVector4.h"
#include "cFileReader.h"
#include <string>

class cMainMenu {
private:
    Matrix4 mMatrix1;
    Matrix4 mMatrix2;
    int mScalar;
    cFileReader mFileReader;

    bool mbRunning = true;

    // Helper functions for menu operations
    void Menu();
    void PerformScaleUniform(Matrix4& _rMatrix);
    void PerformScaleNonuniform(Matrix4& _rMatrix);
    void PerformTranslate(Matrix4& _rMatrix);
    void PerformRotate(Matrix4& _rMatrix);
    void PerformProject(Matrix4& _rMatrix);

    // MultipleTransformMethod
    void SelectMultipleTransformations(Matrix4& _rMatrix);

    // Helper functions
    float GetFloatInput(const std::string& _prompt);
    bool GetBoolInput(const std::string& _prompt);

public:
    cMainMenu();
    void UpdateMenu();
};
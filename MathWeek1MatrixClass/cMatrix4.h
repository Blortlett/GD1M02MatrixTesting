/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : [cMatrix4.h]
Description : [This class lets me store, use and perform operations on 4x4 Matrices]
Author : [Matthew Bartlett, Oliver Noone-Jones]
Mail : [matthewbartlett@mds.ac.nz]
**************************************************************************/
#pragma once
#include <iostream>
#include "cVector4.h"
using namespace std;

class Matrix4 {
private:
    float m_fMatrix[4][4];
    static const int MAX_RAND_NUMBER = 19;

public:
    // Constructor
    Matrix4() : m_fMatrix{0} {}

    // 0-based index gets and sets
    void SetElement(int _iX, int _iY, float _fValue);
    float GetElement(int _iX, int _iY) const;

    // Static member functions
    static void Identity(Matrix4& _rResult);
    static void Zero(Matrix4& _rResult);
    static bool Equals(const Matrix4& _rA, const Matrix4& _rB);
    
    // Math Functions
    static void Add(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult);
    static void Subtract(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult);
    static void Multiply(float _fScalar, const Matrix4& _rA, Matrix4& _rResult);
    static void Multiply(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult);
    static void Transpose(const Matrix4& _rA, Matrix4& _rResult);
    static float Determinant(const Matrix4& _rA);
    static float Determinant3x3(float m[3][3]);
    static bool Inverse(const Matrix4& _rA, Matrix4& _rResult);
    static Vector4& ScaleUniform(float _fScale,
        const Vector4& _rVec,
        Matrix4& _rResultMat);
    static Vector4& ScaleNonUniform(float _fScaleX,
        float _fScaleY,
        float _fScaleZ,
        Vector4& _rVec,
        Matrix4& _rResultMat);
    static Vector4& Translation(float _fTranslateX,
        float _fTranslateY,
        float _fTranslateZ,
        const Vector4& _rVec,
        Matrix4& _rResult);

    // Helper Functions
    void PrintMatrix() const;
    void RandomizeMatrix();
    int RandomInt();
};
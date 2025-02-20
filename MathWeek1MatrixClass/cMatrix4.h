#pragma once
#include <iostream>
using namespace std;

class Matrix4 {
private:
    float m_fMatrix[4][4];

public:
    // 0 based index.
    void SetElement(int _iX, int _iY, float _fValue);
    float GetElement(int _iX, int _iY) const;

    // Static member functions
    static void Identity(Matrix4& _rResult);
    static void Zero(Matrix4& _rResult);
    static bool Equals(const Matrix4& _rA, const Matrix4& _rB);
    
    static void Add(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult);
    static void Subtract(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult);
    static void Multiply(float _fScalar, const Matrix4& _rA, Matrix4& _rResult);
    static void Multiply(const Matrix4& _rA, const Matrix4& _rB, Matrix4& _rResult);
    static void Transpose(const Matrix4& _rA, Matrix4& _rResult);
    static float Determinant(const Matrix4& _rA);
    static bool Inverse(const Matrix4& _rA, Matrix4& _rResult);
    static bool TestHarness();
};
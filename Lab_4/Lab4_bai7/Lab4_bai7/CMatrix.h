#pragma once
#include <iostream>
#include <vector>
#include "CVector.h"

using namespace std;

class CMatrix {
private:
    int rows, cols;
    vector<vector<double>> a;
public:
    CMatrix(int r = 0, int c = 0);

    int getRows() const;
    int getCols() const;

    vector<double>& operator[](int i);
    const vector<double>& operator[](int i) const;

    CMatrix operator+(const CMatrix& m) const;
    CMatrix operator*(const CMatrix& m) const;   // Matrix * Matrix
    CVector operator*(const CVector& v) const;   // Matrix * Vector

    friend istream& operator>>(istream& in, CMatrix& m);
    friend ostream& operator<<(ostream& out, const CMatrix& m);
};
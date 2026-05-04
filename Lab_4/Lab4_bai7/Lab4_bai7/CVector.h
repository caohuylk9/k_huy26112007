#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CVector {
private:
    vector<double> a;
public:
    CVector(int n = 0);
    int size() const;

    double& operator[](int i);
    const double& operator[](int i) const;

    CVector operator+(const CVector& v) const;
    CVector operator-(const CVector& v) const;

    friend istream& operator>>(istream& in, CVector& v);
    friend ostream& operator<<(ostream& out, const CVector& v);
};
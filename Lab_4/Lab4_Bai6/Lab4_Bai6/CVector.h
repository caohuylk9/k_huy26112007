#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CVector
{
private:
    vector<double> a;

public:
    // constructor
    CVector(int n = 0);

    // kích thước
    int size() const;

    // truy cập phần tử
    double& operator[](int i);
    const double& operator[](int i) const;

    // phép toán
    CVector operator+(const CVector& v);
    CVector operator-(const CVector& v);

    // nhập xuất
    friend istream& operator>>(istream& in, CVector& v);
    friend ostream& operator<<(ostream& out, const CVector& v);
};
#pragma once
#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;
public:
    PhanSo(int t = 0, int m = 1);
    void rutGon();
    friend istream& operator>>(istream& in, PhanSo& ps);
    friend ostream& operator<<(ostream& out, const PhanSo& ps);
    PhanSo operator+(const PhanSo& ps) const;
    PhanSo operator-(const PhanSo& ps) const;
    PhanSo operator*(const PhanSo& ps) const;
    PhanSo operator/(const PhanSo& ps) const;
    bool operator==(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps) const;
    bool operator<(const PhanSo& ps) const;
};
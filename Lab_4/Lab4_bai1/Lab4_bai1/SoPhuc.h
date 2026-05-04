#pragma once
#include <iostream>
using namespace std;

class SoPhuc
{
private:
    double PhanThuc;
    double PhanAo;

public:
    // Constructor (số thực = số phức đặc biệt)
    SoPhuc(double thuc = 0, double ao = 0);

    // Nạp chồng toán tử << và >>
    friend istream& operator>>(istream& in, SoPhuc& sp);
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);

    // Toán tử + - * /
    SoPhuc operator+(const SoPhuc& sp) const;
    SoPhuc operator-(const SoPhuc& sp) const;
    SoPhuc operator*(const SoPhuc& sp) const;
    SoPhuc operator/(const SoPhuc& sp) const;

    // So sánh
    bool operator==(const SoPhuc& sp) const;
    bool operator!=(const SoPhuc& sp) const;
};
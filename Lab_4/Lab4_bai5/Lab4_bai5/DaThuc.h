#pragma once
#include <iostream>
#include <vector>
using namespace std;
// Khai báo class DaThuc
class DaThuc
{
private:
    int bac;
    vector<double> a; // a[i] là hệ số của x^(bac-i)
public:
    DaThuc(int b = 0);
    void ChuanHoa();
    DaThuc operator+(const DaThuc& b);
    DaThuc operator-(const DaThuc& b);
    double GiaTriDaThuc(double x);
    friend istream& operator>>(istream& in, DaThuc& dt);
    friend ostream& operator<<(ostream& out, const DaThuc& dt);
};
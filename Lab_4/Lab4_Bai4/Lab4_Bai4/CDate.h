#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class CDate {
private:
    int iNgay, iThang, iNam;
public:
    CDate(int d = 1, int m = 1, int y = 2000);
    static bool LaNamNhuan(int y);
    static int SoNgayTrongThang(int m, int y);
    long long TongSoNgay();
    // nhập xuất
    friend istream& operator>>(istream& is, CDate& d);
    friend ostream& operator<<(ostream& os, const CDate& d);

    // ++ --
    CDate& operator++();      // ++ trước
    CDate operator++(int);    // ++ sau
    CDate& operator--();        // -- trước
    CDate operator--(int);  //-- sau

    // + -
    CDate operator+(int ngay);
    CDate operator-(int ngay);

    // khoảng cách
    int operator-(CDate d2);
};
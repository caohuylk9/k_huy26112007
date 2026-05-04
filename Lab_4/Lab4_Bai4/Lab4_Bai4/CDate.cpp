#include "CDate.h"

// Constructor
CDate::CDate(int d, int m, int y) : iNgay(d), iThang(m), iNam(y) {}

// Năm nhuận
bool CDate::LaNamNhuan(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Số ngày trong tháng
int CDate::SoNgayTrongThang(int m, int y) {
    switch (m) {
    case 4: case 6: case 9: case 11: return 30;
    case 2: return LaNamNhuan(y) ? 29 : 28;
    default: return 31;
    }
}

// Tổng số ngày
long long CDate::TongSoNgay() {
    long total = iNgay;
    for (int y = 1; y < iNam; ++y)
        total += LaNamNhuan(y) ? 366 : 365;
    for (int m = 1; m < iThang; ++m)
        total += SoNgayTrongThang(m, iNam);
    return total;
}

// Nhập
istream& operator>>(istream& is, CDate& d) {
    cout << "Nhap Ngay Thang Nam: ";
    is >> d.iNgay >> d.iThang >> d.iNam;
    return is;
}

// Xuất
ostream& operator<<(ostream& os, const CDate& d) {
    os << (d.iNgay < 10 ? "0" : "") << d.iNgay << "/"
        << (d.iThang < 10 ? "0" : "") << d.iThang << "/"
        << d.iNam;
    return os;
}

// ++ trước
CDate& CDate::operator++() {
    iNgay++;
    if (iNgay > SoNgayTrongThang(iThang, iNam)) {
        iNgay = 1;
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    return *this;
}

// ++ sau
CDate CDate::operator++(int) {
    CDate tam = *this;
    ++(*this);
    return tam;
}

// -- trước
CDate& CDate::operator--() {
    iNgay--;
    if (iNgay < 1) {
        iThang--;
        if (iThang < 1) {
            iThang = 12;
            iNam--;
        }
        iNgay = SoNgayTrongThang(iThang, iNam);
    }
    return *this;
}

// -- sau
CDate CDate::operator--(int) {
    CDate tam = *this;
    --(*this);
    return tam;
}

// + ngày
CDate CDate::operator+(int ngay) {
    CDate res = *this;
    for (int i = 0; i < ngay; i++) ++res;
    return res;
}

// - ngày
CDate CDate::operator-(int ngay) {
    CDate res = *this;
    for (int i = 0; i < ngay; i++) --res;
    return res;
}

// khoảng cách
int CDate::operator-(CDate d2) {
    return this->TongSoNgay() - d2.TongSoNgay();
}
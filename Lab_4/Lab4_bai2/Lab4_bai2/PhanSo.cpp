#include "PhanSo.h"
#include <cmath>


PhanSo::PhanSo(int t, int m)
{
    if (m == 0) throw "Mau so khong hop le";

    tu = t;
    mau = m;
    rutGon();
}

void PhanSo::rutGon()
{
    int a = abs(tu);
    int b = abs(mau);

    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    tu /= a;
    mau /= a;

    if (mau < 0)
    {
        tu = -tu;
        mau = -mau;
    }
}


istream& operator>>(istream& in, PhanSo& ps)
{
    in >> ps.tu >> ps.mau;

    if (ps.mau == 0)
        throw "Mau so khong hop le"; // tránh việc chia cho 0

    ps.rutGon();
    return in;
}

ostream& operator<<(ostream& out, const PhanSo& ps)
{
    if (ps.mau == 1)
        // Nếu mẫu bằng 1 thì chỉ in tử số
        out << ps.tu;
    else
        out << ps.tu << "/" << ps.mau;
    // Nếu mẫu != 1 in dưới dạng a/b

    return out;
}

// Định nghĩa lại +
PhanSo PhanSo::operator+(const PhanSo& ps) const
{
    return PhanSo(
        tu * ps.mau + ps.tu * mau,
        mau * ps.mau
    );
}

// Định nghĩa lại -
PhanSo PhanSo::operator-(const PhanSo& ps) const
{
    return PhanSo(
        tu * ps.mau - ps.tu * mau,
        mau * ps.mau
    );
}
// Định nghĩa lại *
PhanSo PhanSo::operator*(const PhanSo& ps) const
{
    return PhanSo(tu * ps.tu, mau * ps.mau);
}

PhanSo PhanSo::operator/(const PhanSo& ps) const
{
    if (ps.tu == 0)
        throw "Chia cho 0";
    // / là nhân nghịch đảo nên nếu tử = 0 thì lỗi

    return PhanSo(tu * ps.mau, mau * ps.tu);
}
// Định nghĩa lại ==
bool PhanSo::operator==(const PhanSo& ps) const
{
    return tu * ps.mau == ps.tu * mau;
}
// Định nghĩa dấu >
bool PhanSo::operator>(const PhanSo& ps) const
{
    return tu * ps.mau > ps.tu * mau;
}

// Định nghĩa dấu <
bool PhanSo::operator<(const PhanSo& ps) const
{
    return tu * ps.mau < ps.tu * mau;
}
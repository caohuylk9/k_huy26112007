#include "SoPhuc.h"
#include <cmath>

SoPhuc::SoPhuc(double thuc, double ao)
// constructor nếu không truyền gì vào thì thuc = ao = 0
{
    PhanThuc = thuc;
    PhanAo = ao;
}

istream& operator>>(istream& in, SoPhuc& sp)
{
    in >> sp.PhanThuc >> sp.PhanAo;

    return in;
}

// Hàm xuất
ostream& operator<<(ostream& out, const SoPhuc& sp)
{
    if (sp.PhanThuc != 0 || sp.PhanAo == 0)
    {
        out << sp.PhanThuc; // in phần thực trước

        if (sp.PhanAo > 0)
        {
            if (sp.PhanAo == 1) out << " + i";
            else out << " + " << sp.PhanAo << "i";
        }
        else if (sp.PhanAo < 0)
        {
            if (sp.PhanAo == -1) out << " - i";
            else out << " - " << abs(sp.PhanAo) << "i";
        }
    }
    else
    {
        if (sp.PhanAo == 1) out << "i";
        else if (sp.PhanAo == -1) out << "-i";
        else out << sp.PhanAo << "i";
    }

    return out;
}

// Định nghĩa  +
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const
{
    return SoPhuc(PhanThuc + sp.PhanThuc,
        PhanAo + sp.PhanAo);
}

// Định nghĩa - 
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const
{
    return SoPhuc(PhanThuc - sp.PhanThuc,
        PhanAo - sp.PhanAo);
}

// Định nghĩa *
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const
{
    return SoPhuc(
        PhanThuc * sp.PhanThuc - PhanAo * sp.PhanAo,
        PhanThuc * sp.PhanAo + PhanAo * sp.PhanThuc
    );
}

// Định nghĩa /
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const
{
    double mau = sp.PhanThuc * sp.PhanThuc +
        sp.PhanAo * sp.PhanAo;

    if (mau == 0)
        throw "LOI: chia cho 0";

    return SoPhuc(
        (PhanThuc * sp.PhanThuc + PhanAo * sp.PhanAo) / mau,
        (PhanAo * sp.PhanThuc - PhanThuc * sp.PhanAo) / mau
    );
}

// so sánh bằng
bool SoPhuc::operator==(const SoPhuc& sp) const
{
    const double eps = 1e-9;
    return (abs(PhanThuc - sp.PhanThuc) < eps &&
        abs(PhanAo - sp.PhanAo) < eps);
}

// so sánh không bằng
bool SoPhuc::operator!=(const SoPhuc& sp) const
{
    return !(*this == sp);
}
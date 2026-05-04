#include "CVector.h"

CVector::CVector(int n)
{
    a.resize(n, 0);
}

int CVector::size() const
{
    return a.size();
}

// Nạp chồng []
double& CVector::operator[](int i)
{
    return a[i];
}

const double& CVector::operator[](int i) const
{
    return a[i];
}
 // Nhập
istream& operator>>(istream& in, CVector& v)
{
    for (int i = 0; i < v.a.size(); i++)
        in >> v.a[i];

    return in;
}

// Xuất
ostream& operator<<(ostream& out, const CVector& v)
{
    out << "(";

    for (int i = 0; i < v.a.size(); i++)
    {
        out << v.a[i];
        if (i < v.a.size() - 1)
            out << ", ";
    }

    out << ")";
    return out;
}

// Nạp chồng toán tử +
CVector CVector::operator+(const CVector& v)
{
    CVector kq(a.size());

    for (int i = 0; i < a.size(); i++)
        kq.a[i] = a[i] + v.a[i];

    return kq;
}

// Nạp chồng toán tử -
CVector CVector::operator-(const CVector& v)
{
    CVector kq(a.size());

    for (int i = 0; i < a.size(); i++)
        kq.a[i] = a[i] - v.a[i];

    return kq;
}
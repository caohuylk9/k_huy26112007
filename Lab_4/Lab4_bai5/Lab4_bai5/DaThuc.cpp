#include "DaThuc.h"
#include <cmath>


DaThuc::DaThuc(int b)
{
    bac = b;
    a.resize(b + 1, 0);
    // cho các giá trị a[i] = 0;
}

// Hàm chuẩn hóa
void DaThuc::ChuanHoa()
{
    while (a.size() > 1 && a[0] == 0)
        a.erase(a.begin());

    bac = a.size() - 1;
}

// Định nghĩa lại hàm nhập >>
istream& operator>>(istream& in, DaThuc& dt)
{
    for (int i = 0; i <= dt.bac; i++)
        in >> dt.a[i];

    dt.ChuanHoa();
    return in;
}

//Định nghĩa lại <<
ostream& operator<<(ostream& out, const DaThuc& dt)
{
    bool ok = false;

    for (int i = 0; i < dt.a.size(); i++)
    {
        if (dt.a[i] == 0) continue;

        int mu = dt.bac - i;

        if (ok)
        {
            if (dt.a[i] > 0) out << " + ";
            else out << " - ";
        }
        else
        {
            if (dt.a[i] < 0) out << "-";
        }

        if (abs(dt.a[i]) != 1 || mu == 0)
            out << abs(dt.a[i]);

        if (mu == 1) out << "x";
        else if (mu > 1) out << "x^" << mu;

        ok = true;
    }

    if (!ok) out << "0";
    return out;
}

// Định nghĩa lại dấu +
DaThuc DaThuc::operator+(const DaThuc& b)
{
    int maxBac = max(bac, b.bac);
    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++)
    {
        double x = (i <= bac) ? a[bac - i] : 0;
        double y = (i <= b.bac) ? b.a[b.bac - i] : 0;

        kq.a[maxBac - i] = x + y;
    }

    kq.ChuanHoa();
    return kq;
}

// Định nghĩa lại dấu -
DaThuc DaThuc::operator-(const DaThuc& b)
{
    int maxBac = max(bac, b.bac);
    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++)
    {
        double x = (i <= bac) ? a[bac - i] : 0;
        double y = (i <= b.bac) ? b.a[b.bac - i] : 0;

        kq.a[maxBac - i] = x - y;
    }

    kq.ChuanHoa();
    return kq;
}

// Hàm tính giá trị đa thức
double DaThuc::GiaTriDaThuc(double x)
{
    double S = 0;
    for (int i = 0; i < a.size(); i++)
        S = S * x + a[i];

    return S;
}
#include "cDaThuc.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

cDaThuc::cDaThuc(int b)
{
    bac = b;
    a.resize(b + 1, 0);
}

void cDaThuc::ChuanHoa()
{
    while (a.size() > 1 && a[0] == 0)
    {
        a.erase(a.begin());
    }
    bac = a.size() - 1;
}

void cDaThuc::Nhap()
{
    cout << "Nhap bac cua da thuc:\n";
    cin >> bac;

    a.resize(bac + 1);

    cout << "Nhap he so tu bac cao den thap:\n";
    for (int i = 0; i <= bac; i++)
    {
        cin >> a[i];
    }

    ChuanHoa(); 
}

void cDaThuc::Xuat()
{
    bool coIn = false;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0) continue;

        int mu = bac - i;

        if (coIn)
        {
            if (a[i] > 0) cout << " + ";
            else cout << " - ";
        }
        else
        {
            if (a[i] < 0) cout << "-";
        }
        if (abs(a[i]) != 1 || mu == 0)
        {
            cout << abs(a[i]);
        }
        if (mu == 1) cout << "x";
        else if (mu > 1) cout << "x^" << mu;

        coIn = true;
    }

    if (!coIn) cout << "0";

    cout << endl;
}
cDaThuc cDaThuc::CongDaThuc(cDaThuc b)
{
    int MaxBac = max(bac, b.bac);
    cDaThuc kq(MaxBac);

    for (int i = 0; i <= MaxBac; i++)
    {
        double dt1 = (i <= bac) ? a[bac - i] : 0;
        double dt2 = (i <= b.bac) ? b.a[b.bac - i] : 0;

        kq.a[MaxBac - i] = dt1 + dt2;
    }

    kq.ChuanHoa();
    return kq;
}
cDaThuc cDaThuc::TruDaThuc(cDaThuc b)
{
    int MaxBac = max(bac, b.bac);
    cDaThuc kq(MaxBac);

    for (int i = 0; i <= MaxBac; i++)
    {
        double dt1 = (i <= bac) ? a[bac - i] : 0;
        double dt2 = (i <= b.bac) ? b.a[b.bac - i] : 0;

        kq.a[MaxBac - i] = dt1 - dt2;
    }

    kq.ChuanHoa();
    return kq;
}
double cDaThuc::GiaTriDaThuc(double x)
{
    double S = 0;
    for (int i = 0; i < a.size(); i++)
    {
        S = S * x + a[i];
    }

    return S;
}
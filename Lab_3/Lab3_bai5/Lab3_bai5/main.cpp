#include "cDaThuc.h"
#include <iostream>
using namespace std;
int main() {
    cDaThuc A, B;

    cout << "Nhap A:\n";
    A.Nhap();

    cout << "Nhap B:\n";
    B.Nhap();

    cout << "\nA = ";
    A.Xuat();

    cout << "B = ";
    B.Xuat();

    double x;
    cout << "\nNhap x: ";
    cin >> x;

    cout << "A(" << x << ") = " << A.GiaTriDaThuc(x) << endl;
    cout << "B(" << x << ") = " << B.GiaTriDaThuc(x) << endl;
    
    cDaThuc C = A.CongDaThuc(B);
    cout << "\nA + B = ";
    C.Xuat();

    cDaThuc D = A.TruDaThuc(B);
    cout << "A - B = ";
    D.Xuat();

    return 0;
}
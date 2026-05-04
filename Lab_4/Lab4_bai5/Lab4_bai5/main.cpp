#include <iostream>
#include "DaThuc.h"
using namespace std;

int main()
{
    int n, m;

    // Nhập đa thức 1
    cout << "Nhap bac da thuc P1: ";
    cin >> n;

    DaThuc p1(n);

    cout << "Nhap he so P1 (a0 -> an): ";
    cin >> p1;

    //  Nhập đa thức 2
    cout << "Nhap bac da thuc P2: ";
    cin >> m;

    DaThuc p2(m);

    cout << "Nhap he so P2 (a0 -> an): ";
    cin >> p2;

    // Xuất
    cout << "\nP1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    // Tính tổng, hiệu
    DaThuc tong = p1 + p2;
    DaThuc hieu = p1 - p2;

    cout << "\nP1 + P2 = " << tong << endl;
    cout << "P1 - P2 = " << hieu << endl;

    // Tính giá trị
    double x;
    cout << "\nNhap x: ";
    cin >> x;

    cout << "P1(" << x << ") = " << p1.GiaTriDaThuc(x) << endl;
    cout << "P2(" << x << ") = " << p2.GiaTriDaThuc(x) << endl;

    return 0;
}
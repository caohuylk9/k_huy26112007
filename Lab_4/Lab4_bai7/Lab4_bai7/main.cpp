#include <iostream>
#include "CMatrix.h"
#include "CVector.h"

using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Nhap so dong va cot ma tran A: ";
    cin >> r1 >> c1;
    CMatrix A(r1, c1);
    cout << "Nhap ma tran A:\n";
    cin >> A;

    cout << "Nhap so dong va cot ma tran B: ";
    cin >> r2 >> c2;
    CMatrix B(r2, c2);
    cout << "Nhap ma tran B:\n";
    cin >> B;

    cout << "\nMa tran A:\n" << A;
    cout << "\nMa tran B:\n" << B;

    if (r1 == r2 && c1 == c2) {
        CMatrix C = A + B;
        cout << "\nA + B:\n" << C;
    }
    else {
        cout << "\nKhong the cong A va B (khac kich thuoc)\n";
    }

    if (c1 == r2) {
        CMatrix D = A * B;
        cout << "\nA * B:\n" << D;
    }
    else {
        cout << "\nKhong the nhan A * B (khong phu hop kich thuoc)\n";
    }

    int n;
    cout << "\nNhap kich thuoc vector (phai = so cot A): ";
    cin >> n;
    CVector v(n);
    cout << "Nhap vector:\n";
    cin >> v;

    cout << "Vector v = " << v << endl;

    if (c1 == n) {
        CVector res = A * v;
        cout << "\nA * v = " << res << endl;
    }
    else {
        cout << "\nKhong the nhan A * v (sai kich thuoc)\n";
    }

    return 0;
}
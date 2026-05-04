#include <iostream>
#include <iomanip>
#include "CDate.h"

using namespace std;

int main() {
    CDate NgayGui, NgayRut;
    double TienGui, LaiSuatNam;

    cout << "Nhap ngay gui (dd mm yyyy): ";
    cin >> NgayGui;

    cout << "Nhap ngay rut (dd mm yyyy): ";
    cin >> NgayRut;

    cout << "Nhap so tien gui (VND): ";
    cin >> TienGui;

    cout << "Nhap lai suat nam (%): ";
    cin >> LaiSuatNam;

    int SoNgay = NgayRut - NgayGui;

    if (SoNgay < 0) {
        cout << "Ngay rut khong the truoc ngay gui!" << endl;
        return 0;
    }

    double TienLai = TienGui * (LaiSuatNam / 100.0) * (SoNgay / 365.0);

    cout << "- So ngay gui: " << SoNgay << endl;
    cout << "- Tien lai: " << fixed << setprecision(0) << TienLai << " VND\n";
    cout << "- Tong tien: " << TienGui + TienLai << " VND\n";

    return 0;
}
#include <iostream>
#include <ctime>
#include "cArray.h"
using namespace std;

int main()
{
    cArray arr;
    srand(time(0));
    // Giúp mỗi lần random ra các số khác nhau

    cout << "--TAO MANG NGAU NHIEN--\n";
    arr.TaoNgauNhien();

    cout << "Mang vua tao la:\n";
    arr.Xuat();

    cout << "--DEM PHAN TU--\n";
    int x;
    cout << "Nhap phan tu can kiem tra: ";
    cin >> x;

    int d = arr.Dem(x);  
    if (d == 0) cout << "Phan tu khong xuat hien\n";
    else cout << "Phan tu xuat hien " << d << " lan\n";

    cout << "--KIEM TRA TANG DAN--\n";
    if (arr.KiemTraTangDan())
        cout << "Mang tang dan\n";
    else
        cout << "Mang KHONG tang dan\n";

    cout << "--SO LE NHO NHAT--\n";
    int le = arr.TimPhanTuLeNN();
    if (le == 0) cout << "Khong co so le\n";
    else cout << "So le nho nhat: " << le << endl;

    cout << "--SO NGUYEN TO LON NHAT--\n";
    int snt = arr.TimSNTLN();   
    if (snt == -1) cout << "Khong ton tai SNT\n";
    else cout << "So nguyen to lon nhat: " << snt << endl;

    cout << "--SAP XEP GIAM--\n";
    arr.SapXepGiam();
    arr.Xuat();

    return 0;
}
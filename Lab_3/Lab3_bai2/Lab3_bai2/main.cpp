#include <iostream>
#include "cDaGiac.h"
#include <vector>
using namespace std;

int main() {
    cDaGiac dg ;
    dg.Nhap();
    if (dg.TinhDienTich() == 0)
    {
        cout << "Da giac khong hop le!" << endl;
        // Nếu các điểm thẳng hàng thì đa giác đó không hợp lệ
        return 0;
    }
    dg.Xuat();
    cout << "Chu vi: " << dg.TinhChuVi() << endl;
    cout << "Dien tich: " << dg.TinhDienTich() << endl;


    dg.TinhTien(1, 1);  // Nhập giá trị cần tính tiến ( ví dụ :1)
    cout << "Toa do sau khi tinh tien: " << endl;
    dg.Xuat();
    dg.PhongTo(2);      // Nhập giá trị phóng to (ví dụ : 2)
    cout << "Toa do sau khi phong to: " << endl;
    dg.Xuat();
    dg.ThuNho(2);
    cout << "Toa do sau khi thu nho: " << endl;
    dg.Xuat();          //Nhập giá trị thu nhỏ ( ví dụ : 5)
    dg.Quay(250);       // Nhập góc quay ( ví dụ 250 độ)
    cout << "Toa do sau khi quay: " << endl;
    dg.Xuat();
    return 0;
}
#include <iostream>
#include "cTamGiac.h"

using namespace std;
int main() {
    cTamGiac tg;
    tg.Nhap();
    if (tg.KiemTra() != 0)
    {
        tg.Xuat();
        cout << "Loai: ";
        if (tg.KiemTra() == 1) cout << "Tam giac can \n";
        else if (tg.KiemTra() == 2) cout << "Tam giac vuong can \n";
        else if (tg.KiemTra() == 3) cout << "Tam giac vuong \n";
        else if (tg.KiemTra() == 4) cout << " Tam giac can \n";
        else cout <<"Tam giac thuong \n";
        cout << "Chu vi: " << tg.TinhChuVi() << endl;
        cout << "Dien tich: " << tg.TinhDienTich() << endl;


        tg.TinhTien(1, 1);  // Nhập giá trị cần tính tiến ( ví dụ :1)
        cout << "Toa do sau khi tinh tien: " << endl;
        tg.Xuat();
        tg.PhongTo(2);      // Nhập giá trị phóng to (ví dụ : 2)
        cout << "Toa do sau khi phong to: " << endl;
        tg.Xuat();
        tg.ThuNho(2);
        cout << "Toa do sau khi thu nho: " << endl;
        tg.Xuat();          //Nhập giá trị thu nhỏ ( ví dụ : 5)
        tg.Quay(250);       // Nhập góc quay ( ví dụ 250 độ)
        cout << "Toa do sau khi quay: " << endl;
        tg.Xuat();
    }
    else cout << "Khong phai la tam giac" << endl;
return 0;
}
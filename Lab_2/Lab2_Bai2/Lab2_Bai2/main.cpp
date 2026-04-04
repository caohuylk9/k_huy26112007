#include "PhanSo.h"
#include <iostream>
using namespace std;
int main() {
	PhanSo a, b;
	a.Nhap();								// Lần lượt nhập và tử và mẫu của phân số a
	a.RutGon();								// Rút gọn phân số a
	b.Nhap();								// Tương tự với b
	b.RutGon();
	cout << "Phan so a la: ";
	a.Xuat();								// Xuất ra phân số có dạng tử/mẫu
	cout << "Phan so b la: ";
	b.Xuat();

	PhanSo c, d, e, f;						// Lần lượt là các phân số Tổng, Hiệu, Tích, Thương giữa a và b;
	cout << "Tong hai phan so a va b la: ";
	c = a.TinhTong(b);			
	c.RutGon();
	c.Xuat();

	cout << "Hieu giua phan so a va b la: ";
	d = a.TinhHieu(b);						
	d.RutGon();
	d.Xuat();

	cout << "Tich hai phan so a va b la: ";
	e = a.TinhTich(b);
	e.RutGon();
	e.Xuat();

	cout << "Thuong giua phan so a va b la: ";
	f = a.TinhThuong(b);
	f.RutGon();
	f.Xuat();

	if (a.SoSanh(b) == 1) cout << "Phan so a lon hon phan so b" << endl;			// so sánh
	else if (a.SoSanh(b) == -1) cout << "Phan so b lon hon phan so a" << endl;
	else if (a.SoSanh(b) == 2) cout << "Khong the so sanh" << endl;		
	else cout << "Hai phan so bang nhau" << endl;
}
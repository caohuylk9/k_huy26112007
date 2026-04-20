#include "cNhanVienSX.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	vector <cNhanVienSX> a;
	int n;
	// n là số lương nhân viên
	cout << "--So luong NV:--\n";
	cin >> n;
	a.resize(n);
	// Thiết lập kích thước cho vector
	for (int i = 0; i < n; i++)
	{
		cout << "NV " << i << endl;
		a[i].Nhap();
		// Lần lượt nhập thông tin nhân viên
	}
	cout << "--Danh sach NV:--\n";
	for (int i = 0; i < n; i++)
	{
		// Xuất thông tin nhân viên
		cout << "STT " << i << "|"; a[i].Xuat();
	}
	cout <<"--Nhan vien co luong thap nhat la:-- \n";
	cNhanVienSX x = cNhanVienSX::TimLuongThapNhat(a);
	x.Xuat();
	// In ra nhân viên có lương thấp nhất

	cout << "--Tong luong ma cong ty can tra:-- " ;
	cout << cNhanVienSX::TongLuong(a) << endl;
	// In ra tổng lương công ty cần trả

	cout << "--Nhan vien lon tuoi nhat:--" << endl;
	cNhanVienSX y = cNhanVienSX::TimNVTuoiLN(a);
	y.Xuat();
	// Nhân viên lớn tuổi nhất
	cout << "--Danh sach da duoc sap xep theo luong tang dan :--\n";
	cNhanVienSX::SapXep(a);
	for (int i = 0; i < a.size(); i++)
	{
		a[i].Xuat();
	}
	// Danh sách nhân vienr theo thứ tự lương tăng

}
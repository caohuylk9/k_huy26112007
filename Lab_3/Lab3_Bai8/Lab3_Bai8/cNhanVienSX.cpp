#include "cNhanVienSX.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
cNhanVienSX::cNhanVienSX(string mnv , string ht , string ns , int ssp , int g )
// constructor
{
	MaNV = mnv;
	HoTen = ht;
	NgaySinh = ns;
	SoSP = ssp;
	Gia = g;	
}
void cNhanVienSX::Nhap()
{
	cin.ignore();
	cout << "Ma NV: \n";
	getline(cin, MaNV);
	cout << "Ho ten: ";
	getline(cin, HoTen);

	cout << "Ngay sinh (dd/mm/yyyy): ";
	getline(cin, NgaySinh);

	cout << "So san pham: ";
	cin >> SoSP;
	cout << "Gia mot san pham: ";
	cin >> Gia;
}
void cNhanVienSX::Xuat()
{
	// Xuất thông tin nhân viên dưới dạng |  | |  
	cout << MaNV << "|" << HoTen << "|" << NgaySinh
		<< "|" << SoSP << "|" << Gia << "|"
		<< "Luong: " << TinhLuong() <<endl;
}
long long cNhanVienSX::TinhLuong() const
{
	// Lương bằng số sản phẩm * giá
	return  1LL *SoSP * Gia;
}
long long cNhanVienSX::TongLuong(vector <cNhanVienSX> a)
{
	long long TL = 0;
	for (int i = 0; i < a.size(); i++)
	{
		// Tổng lương công ty phải trả là tổng lương các nhân viên
		TL += a[i].TinhLuong();
	}
	return TL;
}
int cNhanVienSX::Get()
{
	// cách số hóa 4 kí tự cuối trong chuỗi ngày sinh em nhặt trên mạng
	return stoi(NgaySinh.substr(6, 4));
}
cNhanVienSX cNhanVienSX::TimNVTuoiLN(vector <cNhanVienSX> a)
{
	cNhanVienSX NVLonTuoiNhat;
	int S = a[0].Get(); NVLonTuoiNhat = a[0];
	// Mặc định tạm thời nhân viên đầu lớn nhất 
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i].Get() < S) {
			S = a[i].Get(); NVLonTuoiNhat = a[i];
		}
	}
	return NVLonTuoiNhat;
}
cNhanVienSX cNhanVienSX::TimLuongThapNhat(vector <cNhanVienSX> a)
{
	cNhanVienSX NVLuongTN;
	int S = a[0].TinhLuong(); NVLuongTN = a[0];
	// Giả sử nhân viên đầu có lương thấp nhất
	for (int i = 1; i < a.size(); i++)
	{
		if (S > a[i].TinhLuong()) { S = a[i].TinhLuong(); NVLuongTN = a[i]; }
	}
	return NVLuongTN;
}
 bool cNhanVienSX::SoSanh( const cNhanVienSX& a, const cNhanVienSX& b)
{
	 // hàm so sánh lương
		return a.TinhLuong() < b.TinhLuong(); 
}
void cNhanVienSX::SapXep(vector<cNhanVienSX>& a)
{
	// Hàm sắp xếp lương tăng trên google
	sort(a.begin(),a.end(), SoSanh);
}
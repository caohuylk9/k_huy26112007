#pragma once
#include <string>
#include <vector>
using namespace std;
class cNhanVienSX
	// Khai báo class cNhanVienSX
{
private:
	string MaNV;
	string HoTen, NgaySinh;
	int SoSP;
	int Gia;
public:
	cNhanVienSX(string mnv = "", string ht = "", string ns = "", int sp = 0, int g = 0);
	void Nhap();
	void Xuat();
	long long TinhLuong() const;
	int Get();
	static long long TongLuong(vector <cNhanVienSX> a);
	static cNhanVienSX TimNVTuoiLN(vector <cNhanVienSX> a);
	static cNhanVienSX TimLuongThapNhat(vector<cNhanVienSX> a);
	static bool SoSanh( const cNhanVienSX &a, const cNhanVienSX &b);
	static void SapXep(vector<cNhanVienSX>& ds);
};


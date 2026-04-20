#pragma once
#include "Point.h"
class cTamGiac		// Khai báo hàm cTamGiac
{
private:
	Point A, B, C;
public:
	void Nhap();
	void Xuat();
	void TinhTien(double dx, double dy);
	void Quay(double alp);
	void PhongTo(double k);
	void ThuNho(double k);
	double TinhChuVi();
	double TinhDienTich();
	int KiemTra();
};


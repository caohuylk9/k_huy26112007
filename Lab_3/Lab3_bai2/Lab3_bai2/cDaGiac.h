#pragma once
#include <vector>
#include <string>
#include "Point.h"
using namespace std;
class cDaGiac // Khai báo class Đa Giác
{
	private:
		vector <Point> a;
	public:
		void Nhap();
		void Xuat();
		void TinhTien(double dx, double dy);
		void Quay(double alp);
		void PhongTo(double k);
		void ThuNho(double k);
		double TinhChuVi();
		double TinhDienTich();
};


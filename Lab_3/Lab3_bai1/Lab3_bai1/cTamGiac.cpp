#include "cTamGiac.h"
#include "Point.h"
#include <iostream>
using namespace std;
void cTamGiac::Nhap()
{
	cout << "Nhap diem A: \n";
	A.Nhap();
	// A có kiểu dữ liệu Point nên có thể dùng A.Nhap() của class Point
	cout << "Nhap diem B: \n";
	B.Nhap();
	cout << "Nhap diem C:\n";
	C.Nhap();
}

void cTamGiac::Xuat()
{
	cout << "Toa do dinh A: ";
	A.Xuat();
	// A có kiểu dữ liệu Point nên có thể dùng A.Xuat() của class Point
	cout << "Toa do dinh B: ";
	B.Xuat();
	cout << "Toa do dinh C: ";
	C.Xuat();
}
void cTamGiac::TinhTien(double dx, double dy)
{
	A.TinhTien(dx,dy);
	B.TinhTien(dx,dy);
	C.TinhTien(dx, dy);
}
double cTamGiac::TinhChuVi()
{
	return A.KhoangCach(B) + B.KhoangCach(C) + C.KhoangCach(A);
}
double cTamGiac::TinhDienTich()
{
	double a = B.KhoangCach(C), b = C.KhoangCach(A), c = A.KhoangCach(B);
	double p = TinhChuVi() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
	//  Công thức Heron về tính diện tích tam giác
}
int cTamGiac::KiemTra()
{
	double a = B.KhoangCach(C), b = C.KhoangCach(A), c = A.KhoangCach(B);
	if (a + b <= c || a + c <= b || b + c <= a) return 0;
	if (a == b && b == c) return 1;
	bool can = (a == b || b == c || a == c);
	bool vuong = (abs(a * a + b * b - c * c) < 0.01 || abs(a * a + c * c - b * b) < 0.01 || abs(b * b + c * c - a * a) < 0.01);
	// Dùng double nên có thể xảy ra một số sai số nhỏ nếu dùng a^2 + b^2 == c^2
	if (vuong && can) return 2;
	if (vuong) return 3;
	if (can) return 4;
	return 5;
}
void cTamGiac::Quay(double alp)
{
	Point G;
	G.SetXY((A.GetX() + B.GetX() + C.GetX()) / 3, (A.GetY() + B.GetY() + C.GetY()) / 3);
	// Tìm tọa độ trọng tâm G
	A.SetXY(A.GetX() - G.GetX(), A.GetY() - G.GetY());
	B.SetXY(B.GetX() - G.GetX(), B.GetY() - G.GetY());
	C.SetXY(C.GetX() - G.GetX(), C.GetY() - G.GetY());
	// Dời trọng tâm về gốc tọa độ
	A.Quay(alp); B.Quay(alp); C.Quay(alp);
	// Quay hình
	A.SetXY(A.GetX() + G.GetX(), A.GetY() + G.GetY());
	B.SetXY(B.GetX() + G.GetX(), B.GetY() + G.GetY());
	C.SetXY(C.GetX() + G.GetX(), C.GetY() + G.GetY());
	// Dời lại hình về chỗ cũ nhưng sau khi xoay
	// => lựa chọn quay hình quanh trọng tâm
}
void cTamGiac::PhongTo(double k)
{
	double gx = (A.GetX() + B.GetX() + C.GetX()) /3;
	double gy = (A.GetY() + B.GetY() + C.GetY()) /3;
	// Tìm trọng tâm G
	A.SetXY(gx + (A.GetX() - gx) * k, gy + (A.GetY() - gy) * k);
	B.SetXY(gx + (B.GetX() - gx) * k, gy + (B.GetY() - gy) * k);
	C.SetXY(gx + (C.GetX() - gx) * k, gy + (C.GetY() - gy) * k);
	// Lựa chọn phóng to hình theo trọng tâm G
}
void cTamGiac::ThuNho(double k) 
// Thu nhỏ k lần là phóng to 1/k lần
{
	if (k != 0) PhongTo(1.0 / k);
}
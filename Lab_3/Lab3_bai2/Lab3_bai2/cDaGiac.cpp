#include "cDaGiac.h"
#include "Point.h"
#include <cmath>
#include <iostream>
const double PI = 3.141592653589793;
using namespace std;
void cDaGiac::Nhap()
{
	cout << "Nhap so dinh: " << endl;
	int n;
	cin >> n;
	while (n < 3)
	{ // Nhập đến khi số đỉnh >= 3
		cout << "So dinh khong thoa,yêu cau nhap lai: \n ";
		cin >> n;
	}
	cout << "NHAP TOA DO CAC DINH THEO THU TU QUANH DA GIAC" << endl;
	// Phải nhập tọa độ theo thứ tự để có thể tính diện tích
	for (int i = 0; i < n; i++)
	{
		Point p;
		cout << "Nhap toa do diem thu " << i << endl;
		// Nhập vào tọa độ từng điểm
		p.Nhap();
		a.push_back(p);
	}
}

void cDaGiac::Xuat()
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << "Toa do dinh thu " << i << ": ";
		a[i].Xuat();
	}
}
void cDaGiac::TinhTien(double dx, double dy)
{
	for (int i = 0; i < a.size(); i++)
	{
		// Dùng hàm tịnh tiến lần lượt các điểm 
		a[i].TinhTien(dx, dy);
	}
}
double cDaGiac::TinhChuVi()
{ // Tính chu vi
	double S = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int j = (i + 1) % a.size();
		S += a[i].KhoangCach(a[j]);
	}
	return S;
}
double cDaGiac::TinhDienTich()
{
	double S = 0;
	for (int i = 0; i < a.size(); i++)
	{
		// Công thức tổng quát tính diện tích trên google
		int j = (i + 1) % a.size();
		S += a[i].GetX() * a[j].GetY();
		S -= a[i].GetY() * a[j].GetX();
	}
	return abs(S) / 2.0;
}
void cDaGiac::Quay(double angleDeg)		// cách này không đúng cho toàn bộ mọi đa giác
{
	int n = a.size();
	double Gx = 0, Gy = 0;			// Tìm trọng tâm G để xoay quanh trọng tâm
	double Rad = angleDeg / 180 * PI;
	for (int i = 0; i < n; i++)
	{
		Gx += a[i].GetX();
		Gy += a[i].GetY();
	}
	Gx /= n;
	Gy /= n;
	for (int i = 0; i < n; i++)
	{
		double x = a[i].GetX() - Gx;	// Dời các đỉnh sao cho tọng tâm trùng gốc tọa độ
		double y = a[i].GetY() - Gy;

		double x_new = x * cos(Rad) - y * sin(Rad);	// Xoay các đỉnh
		double y_new = x * sin(Rad) + y * cos(Rad);

		a[i].SetXY(x_new + Gx, y_new + Gy); // Dời các đỉnh về vị trí cũ nhưng đã được xoay
	}
}
void cDaGiac::PhongTo(double k)
{
	int n = a.size();
	double Gx = 0, Gy = 0;			// Tìm trọng tâm G để phóng to theo trọng tâm
	for (int i = 0; i < n; i++)
	{
		Gx += a[i].GetX();
		Gy += a[i].GetY();
	}
	Gx /= n;
	Gy /= n;
	for (int i = 0; i < n; i++)
	{
		a[i].SetXY(Gx + (a[i].GetX() - Gx) * k, Gy + (a[i].GetY() - Gy) * k);
		// Dời các đỉnh sao cho trọng tâm trùng gốc tọa độ -> phóng to -> dời lại
	}
}
void cDaGiac::ThuNho(double k)
{
	int n = a.size();
	double Gx = 0, Gy = 0;
	for (int i = 0; i < n; i++)
	{
		Gx += a[i].GetX();
		Gy += a[i].GetY();
	}
	Gx /= n;
	Gy /= n;
	// Tìm trọng tâm g
	for (int i = 0; i < n; i++)
	{
	// Dời các đỉnh sao cho trọng tâm trùng gốc tọa độ -> phóng to -> dời lại
		a[i].SetXY(
			Gx + (a[i].GetX() - Gx) * (1.0 / k),
			Gy + (a[i].GetY() - Gy) * (1.0 / k)
		);
	}
}
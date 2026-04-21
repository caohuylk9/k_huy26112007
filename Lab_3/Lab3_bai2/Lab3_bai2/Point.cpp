	#include "Point.h"
	#include <iostream>
	#include <cmath>
	const double PI = 3.141592653589793;
	using namespace std;
	void Point::Nhap()
	{
		// Hàm nhập vào tọa độ x,y
		cout << "Nhap hoanh do: ";
		cin >> x;
		cout << "Nhap tung do: ";
		cin >> y;
	}
	void Point::Xuat()
	{
		// Xuất ra tọa độ dưới dạng (x,y)
		cout << "(" << x << "," << y << ")" << endl;;
	}
	void Point::TinhTien(double dx, double dy)
	{
		//Hàm tịnh tiến từng điểm
		x += dx; y += dy;
	}
	void Point::Quay(double angleDeg)
	{
		// Sử dụng công thức trên google để xoay điểm
		double Rad = angleDeg / 180 * PI;
		double a = x, b = y;
		x = a * cos(Rad) - b * sin(Rad);
		y = a * sin(Rad) + b * cos(Rad);
	}
	double Point::GetX()
	{
		// lấy giá trị x
		return x;
	}
	double Point::GetY()
	{
		// lấy giá trị y
		return y;
	}
	void Point::SetXY(double xx, double yy)
	{
		x = xx; y = yy;
	}
	double Point::KhoangCach(Point& B)
	{
		// Hàm tính khoảng cách 
		double kc = sqrt(pow(x - B.x, 2) + pow(y - B.y, 2));
		return kc;
	}
	Point::Point(double xx, double yy) {
		x = xx;
		y = yy;
	}

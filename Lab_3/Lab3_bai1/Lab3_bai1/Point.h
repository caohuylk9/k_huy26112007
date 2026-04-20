#pragma once
class Point			
// Tạo class point là kiểu dữ liệu cho tọa độ class cTamGiac
{
private:
	double x, y;
public:
	Point (double x = 0.0, double y = 0.0);
	void Nhap();
	void Xuat();
	void TinhTien( double dx, double dy);
	void Quay(double angleDeg);
	double GetX();
	double GetY();
	void SetXY(double xx, double xy);
	double KhoangCach( Point &B);

};
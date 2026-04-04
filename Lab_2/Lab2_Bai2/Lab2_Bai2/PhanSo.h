#pragma once
class PhanSo					// Khai báo class
{
private:
	int iTu, iMau;
public:
	void Nhap();
	void Xuat();
	void RutGon();
	PhanSo TinhTong(PhanSo& a);
	PhanSo TinhHieu(PhanSo& a);
	PhanSo TinhTich(PhanSo& a);
	PhanSo TinhThuong(PhanSo& a);
	int SoSanh(PhanSo& a);
};


#pragma once
class SoPhuc
{
private:
	double iThuc, iAo;
public:
	void Nhap();
	void Xuat() ;
	SoPhuc TinhTong(const SoPhuc& a);
	SoPhuc TinhHieu(const SoPhuc& a) ;
	SoPhuc TinhTich(const SoPhuc& a) ;
	SoPhuc TinhThuong(const SoPhuc& a) ;
};


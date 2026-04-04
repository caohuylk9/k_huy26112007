#pragma once
#include <string>
class Time		//Khai báo class
{
private:
	int iGio, iPhut, iGiay;
public:
	void Nhap();
	void Xuat(std::string msg);
	void TinhCongThemMotGiay();
};


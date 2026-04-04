#include "Time.h"
#include <iostream>
#include <string>
using namespace std;
void Time::Nhap() // Nhap vao gio phut giay
{
	cout << "Nhap gio: " << endl;
	cin >> iGio;
	cout << "Nhap phut: "  << endl;
	cin >> iPhut;
	cout << "Nhap giay: " << endl;
	cin >> iGiay;
}
void Time::Xuat(string msg) 
{
	if (iGiay > 59|| iGiay <0 || iPhut > 59|| iPhut <0 || iGio > 23 || iGio <0)
		// Xét các điều kiện cơ bản về giờ phút giây
		// Phút và giây từ 0 -> 59, 60 là 0 giây của phút sau 
	{
		throw "LOI: thoi gian bi sai";
		// Nếu điều kiện trên sai thì dừng phần sau
	}
	cout << msg<< iGio << ":" << iPhut << ":" << iGiay << endl;
}

void Time::TinhCongThemMotGiay()
{

	if (++iGiay > 59)
		// Nếu giây >59 thì sẽ là 0 giây của phút sau
	{
		iGiay = 0;
		iPhut++;
	}
	if (iPhut > 59)
		// Tương tự với phút
	{
		iPhut = 0;
		iGio++;
	}
	if (iGio > 23)
		// Nếu giờ > 23 => 0 giờ hôm sau
	{
		iGio = 0;
	}
}
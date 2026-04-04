#include "PhanSo.h"
#include <iostream>
#include <numeric>
using namespace std;

void PhanSo::Nhap() {
	cin >> iTu >> iMau;									// Nhập vào tử và mẫu cuả phân số
}
void PhanSo::Xuat() {
	if (iTu == 0) cout << 0 << endl;					// Nếu tử bằng 0 thì in ra  0
	else if (iMau == 0) cout << "Phan so loi"<< endl;	// Nếu mẫu = 0 thì phân số lỗi
	else if (iMau == 1) cout << iTu<< endl;				
	else cout << iTu << "/" << iMau << endl;
}
void PhanSo::RutGon() {
	int n = gcd(iTu, iMau);
	iTu /= n;
	iMau /= n;
	if (iMau < 0)										//Nếu mẫu <0 đổi dấu - lên tử
	{
		iTu *= -1;
		iMau *= -1;
	}
}
PhanSo PhanSo::TinhTong(PhanSo& a) {
	PhanSo b;
	b.iTu = (iTu * a.iMau) + (iMau * a.iTu);
	b.iMau = iMau * a.iMau;
	return b;
}
PhanSo PhanSo::TinhHieu(PhanSo& a) {
	PhanSo c;
	c.iTu = (iTu * a.iMau) - (iMau * a.iTu);
	c.iMau = iMau * a.iMau;
	return c;
}
PhanSo PhanSo::TinhTich(PhanSo& a) {
	PhanSo d;
	d.iTu = iTu * a.iTu;
	d.iMau = iMau * a.iMau;
	return d;
}
PhanSo PhanSo::TinhThuong(PhanSo& a) {
	PhanSo e;
	e.iTu = iTu * a.iMau;
	e.iMau = iMau * a.iTu;
	return e;
}
int PhanSo::SoSanh(PhanSo& a) {
	if (iMau != 0 && a.iMau != 0)					// Nếu mẫu khác 0
	{
		if (iTu * a.iMau > a.iTu * iMau) return 1;					// 1 : > // -1: < // =: 0
		else if (iTu * a.iMau < a.iTu * iMau) return -1;
		else return 0;
	}
	else return 2;									// Nếu mẫu bằng 0 trả về 2
}
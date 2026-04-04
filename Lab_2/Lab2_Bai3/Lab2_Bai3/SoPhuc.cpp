#include "SoPhuc.h"
#include <iostream>
#include <math.h>
using namespace std;
void SoPhuc::Nhap()
{
	cout << "Nhap phan thuc:" << endl;
	cin >> iThuc;
	cout << "Nhap phan ao: " << endl;
	cin >> iAo;
}
void SoPhuc::Xuat() 
{
	
	if (iThuc > 0 || iThuc < 0)
	{
		if (iAo > 0 && iAo != 1) { cout << iThuc << " + " << iAo << "i" << endl; }
		else if (iAo == 0) { cout << iThuc << endl; }
		else if (iAo == 1) { cout << iThuc << " + " << "i"<< endl; }
		else if (iAo == -1) { cout << iThuc << " - " << "i" << endl; }
		else cout << iThuc << " - " << abs(iAo) << "i" << endl;
	}
	else 
	{
		if (iAo > 0 && iAo != 1) { cout << iAo << "i" << endl; }
		else if (iAo == 0) { cout << 0 << endl; }
		else if (iAo == 1) { cout  << "i" << endl; }
		else if (iAo == -1) { cout <<  " - " << "i" << endl; }
		else cout << " - " << abs(iAo) << "i" << endl;
	}
	
}

SoPhuc SoPhuc::TinhTong(const SoPhuc& a) 
{
	SoPhuc kq;
	kq.iThuc = this->iThuc + a.iThuc;
	kq.iAo = this->iAo + a.iAo;
	return kq;
}

SoPhuc SoPhuc::TinhHieu(const SoPhuc& a) 
{
	SoPhuc kq;
	kq.iThuc = this->iThuc - a.iThuc;
	kq.iAo = this->iAo - a.iAo;
	return kq;
}

SoPhuc SoPhuc::TinhTich(const SoPhuc& a) 
{
	SoPhuc kq;
	kq.iThuc = (this->iThuc * a.iThuc) - (this->iAo * a.iAo);
	kq.iAo = (this->iThuc * a.iAo) + (this->iAo * a.iThuc);
	return kq;
}

SoPhuc SoPhuc::TinhThuong(const SoPhuc& a) 
{
	SoPhuc kq;
	double MauSo = pow(a.iThuc, 2) + pow(a.iAo, 2);
	if (MauSo == 0)
	{
		throw "LOI: Mau so bang 0 !!";
	}
		kq.iThuc = (iThuc * a.iThuc + iAo * a.iAo) / MauSo;
		kq.iAo = (iAo * a.iThuc - iThuc * a.iAo) / MauSo;
	return kq;
}
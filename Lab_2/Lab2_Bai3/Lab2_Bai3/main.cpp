#include "SoPhuc.h"
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	SoPhuc a, b;
	a.Nhap();
	b.Nhap();
	cout << "So Phuc a la: "; a.Xuat();
	cout << "So Phuc b la: "; b.Xuat();

	SoPhuc x, y, z, t, f, g;
	cout << "Tong hai so phuc la: ";
	x = a.TinhTong(b);
	x.Xuat();

	cout << "Hieu giua a va b la: ";
	y = a.TinhHieu(b);
	y.Xuat();

	cout << "Hieu giua b va a la: ";
	z = b.TinhHieu(a);
	z.Xuat();

	cout << "Tich giua a va b la: ";
	t = a.TinhTich(b);
	t.Xuat();

	cout << "Thuong giua a va b la: ";
	try
	{
		f = a.TinhThuong(b);
		f.Xuat();
	}
	catch (const char* message)
	{
		cout << message << endl;
	}

	cout << "Thuong giua b va a la: ";
	try
	{
		g = b.TinhThuong(a);
		g.Xuat();
	}
	catch (const char* message)
	{
		cout << message << endl;
	}

}
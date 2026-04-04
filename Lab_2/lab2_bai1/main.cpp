#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
	Date a;
	a.Nhap();
	if (a.TimNgayThangNamTiepTheo())
	{
		a.Xuat();
	}
	return 0;
}
 
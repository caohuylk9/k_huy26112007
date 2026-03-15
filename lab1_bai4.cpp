#include <iostream>
using namespace std;
struct Date								// khai báo kiểu dữ liệu mới gồm ngày, tháng, năm
{
	int d, m, y;
};

void Nhap(Date  &a)						// nhập vào ngày, tháng,  năm
{
	cin >> a.d >> a.m >> a.y;
}
int main()
{
	Date a;
	Nhap(a);
	int songay;
	if (a.m == 1 || a.m == 3 || a.m == 5 || a.m == 7 || a.m == 8 || a.m == 10 || a.m == 12) songay = 31; // xem tháng được nhập có bao nhiêu ngày
	else if (a.m == 4 || a.m == 6 || a.m == 9 || a.m == 11) songay = 30;
	else if ( a.m == 2)
	{
		if ((a.y % 4 == 0 && a.y % 100 != 0) || a.y % 400 == 0) songay = 29;
		else songay = 28;
	}
	a.d++;								// ngày hôm sau
	if (a.d > songay) { a.d = 1; a.m++; }			// nếu số ngày lớn hơn số ngày trong tháng thì là ngày 1 tháng sau
	if (a.m > 12) { a.m = 1; a.y++; }				// nếu số tháng lớn hơn 12 là tháng  1 năm sau
	cout << a.d << "/" << a.m << "/" << a.y;
	
}

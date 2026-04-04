#include "Date.h"
#include <iostream>
using namespace std;
void Date::Nhap()				//Nhập vào ngày tháng năm ban đầu
{
	cout << "Nhap ngay: " << endl;
	cin >> iNgay;
	cout << "Nhap thang " << endl;
	cin >> iThang;
	cout << "Nhap nam " << endl;
	cin >> iNam;
}
void Date::Xuat()
{
		cout << "Ngay tiep theo la: " << endl;
		// Chèn thêm số 0 cho đủ 2 chữ số
		if (iNgay < 10)
		{
			if (iThang < 10) cout << 0 << iNgay << "/" << 0 << iThang << "/" << iNam << endl;
			else cout << 0 << iNgay << "/" << iThang << "/" << iNam << endl;
		}
		else
		{
			if (iThang < 10) cout << iNgay << "/" << 0 << iThang << "/" << iNam << endl;
			else cout << iNgay << "/" << iThang << "/" << iNam << endl;
		}
}

	bool Date::TimNgayThangNamTiepTheo()
	{
		int day;
		// Thiết lập ngày cho từng tháng
		if (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12) day = 31;
		else if (iThang == 2)
		{
			if ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0 ) day = 29;
			else day = 28;
		}
		else day = 30;
		if (iNgay > day) { cout << "Ngay thang nam bi sai" << endl; return  false; }
		if (++iNgay > day) { iNgay = 1; ++iThang; }
		// Nếu ngày tiếp theo lớn hơn số ngày trong tháng đó thì sẽ qua ngày 1 tháng sau
		if (iThang > 12) { iThang = 1; ++iNam; }
		// Nếu tháng tiếp theo lớn hơn 13 thì qua tháng 1 năm sau
		return true;
	}

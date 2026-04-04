#include "Time.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	Time a;
	a.Nhap();
    try
    {       // Nếu sai -> nhảy xuống catch ngay.
            a.Xuat("Thoi gian hien tai la : ");

            // Hàm chỉ chạy nếu a.Xuat() phía trước thành công.
            a.TinhCongThemMotGiay();

            // Xuất kết quả sau khi tăng.
            a.Xuat("Thoi gian sau khi them mot giay la: ");
     }
    catch (const char* msg)
     {
            // Nếu lỗi thì in ra dòng lệnh báo lỗi
            cout << msg << endl;
     }

     return 0;
    }
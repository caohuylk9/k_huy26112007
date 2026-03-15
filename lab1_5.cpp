#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct HocSinh					// khai báo kiểu dữ liệu mới là HocSinh 
{
	string ten;
	double DiemToan, DiemVan;
};
int main()
{
	HocSinh a;
	getline(cin,a.ten);		// nhập tên
	cin >> a.DiemToan >> a.DiemVan;					// nhập điểm 2 môn
	cout << "Ho Ten: " << a.ten << endl;
	cout << "Diem Trung Binh: " << fixed << setprecision(2) <<(a.DiemToan + a.DiemVan) / 2 << endl; // điểm trung bình làm tròn 2 chữ số thập phân
}
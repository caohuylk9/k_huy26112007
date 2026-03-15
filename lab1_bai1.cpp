
#include <iostream>
using namespace std;
struct PhanSo
{
	long long TuSo, MauSo;
};
void RutGon(PhanSo& x)					// hàm rút gọn tử và mẫu
{
	long long m = x.TuSo;
	long long n = x.MauSo;
	while (n != 0)
	{
		long long temp = m % n;
		m = n;
		n = temp;
	}
	x.TuSo /= m;						
	x.MauSo /= m;
	if (x.MauSo < 0)					// nếu mẫu số <0 lập tức chuyển dấu lên tử			
	{

		x.TuSo = -x.TuSo;
		x.MauSo = -x.MauSo;
	}
}
int main()
{
	PhanSo a;
	cin >> a.TuSo >> a.MauSo;
	if (a.TuSo == 0) {cout << 0;return 0;}
    if (a.MauSo == 0) return 0;				// nếu mẫu bằng 0 thì không in ra gì
	RutGon(a);
	if (a.MauSo == 1) cout << a.TuSo;
	else cout << a.TuSo << "/" << a.MauSo;
	return 0;

}












































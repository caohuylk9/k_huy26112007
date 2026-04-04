#include <iostream>
using namespace std;
struct PhanSo						// khai báo một kiểu dữ liệu phân số 
{
	long long TuSo, MauSo;			// phân số bao gồm tử và mẫu
};
void RutGon(PhanSo& x)				// hàm rút gọn phân số
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
	if (x.MauSo < 0)				// nếu mẫu < 0 lập tức đổi dấu - lên tử
	{
			x.TuSo = -x.TuSo;
			x.MauSo = -x.MauSo;
	}

}
int main()
{
	PhanSo a, b;
	cin >> a.TuSo >> a.MauSo >> b.TuSo >> b.MauSo;								// lần lượt nhập phân số đầu và phân số thứ 2 vào
	long long ps1 = a.TuSo * b.MauSo;											// sử dụng nhân chéo để so sánh
	long long ps2 = b.TuSo * a.MauSo;
	if (a.TuSo == 0 && b.TuSo == 0) cout << 0;
	else if (a.MauSo == 0 || b.MauSo == 0) return 0;							// nếu mẫu 1 trong 2 bằng 0 thì không in ra gì
	else if (ps1 > ps2)															
	{
		RutGon(a);
		if (a.MauSo == 1) cout << a.TuSo;
		else cout << a.TuSo << "/" << a.MauSo;
	}
	else																		// nếu 2 phân số bằng nhau thì sau khi rút gọn 2 phân số đều như nhau nên chỉ cần in ra 1 trong 2
	{
		RutGon(b);
		if (b.MauSo == 1) cout << b.TuSo;
		else cout << b.TuSo << "/" << b.MauSo;
	}

}

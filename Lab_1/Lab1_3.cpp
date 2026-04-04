#include <iostream>
using namespace std;
struct PhanSo					// khai báo một kiểu dữ liệu phân số 
{
	long long TuSo, MauSo;			// phân số bao gồm tử và mẫu
};
void RutGon(PhanSo& x)
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
	if (x.MauSo < 0)
	{
		x.TuSo = -x.TuSo;
		x.MauSo = -x.MauSo;
	}

}
int main()
{
	PhanSo a, b;
	cin >> a.TuSo >> a.MauSo >> b.TuSo >> b.MauSo;
	if (a.MauSo == 0 || b.MauSo == 0) { cout << "phan so sai "; return 0; }
	else if (a.TuSo == 0 && b.TuSo == 0)
	{
		cout << "Tong: 0 " << endl;
		cout << "Hieu a va b: 0" << endl;
		cout << "Hieu b va a: 0" << endl;
		cout << "Tich: 0" << endl;
		cout << "Khong ton tai thuong";
		return 0;
	}
	RutGon(a);
	RutGon(b);
	PhanSo c, d, e, f;							// 4 phân số này lần lượt là tổng, hiệu , tích, thương

	c.TuSo = a.TuSo * b.MauSo + a.MauSo * b.TuSo;
	c.MauSo = a.MauSo * b.MauSo;
	RutGon(c);									// rút gọn tổng

	d.TuSo = a.TuSo * b.MauSo - a.MauSo * b.TuSo;
	d.MauSo = a.MauSo * b.MauSo;
	RutGon(d);									// rút gọn hiệu a và b

	e.TuSo = a.TuSo * b.TuSo;
	e.MauSo = a.MauSo * b.MauSo;
	RutGon(e);									// rút gọn tích

	f.TuSo = a.TuSo * b.MauSo;
	f.MauSo = a.MauSo * b.TuSo;
	RutGon(f);									// rút gọn thương

	cout << "Tong: ";
	if (c.MauSo == 1) cout << c.TuSo << endl;
	else cout << c.TuSo << "/" << c.MauSo << endl;

	cout << "Hieu a va b: ";
	if (d.MauSo == 1) cout << d.TuSo << endl;
	else cout << d.TuSo << "/" << d.MauSo << endl;

	cout << "Hieu b va a: ";
	if (d.MauSo == 1) cout << -d.TuSo << endl;
	else cout << -d.TuSo << "/" << d.MauSo << endl;

	cout << "Tich: ";
	if (e.MauSo == 1) cout << e.TuSo << endl;
	else cout << e.TuSo << "/" << e.MauSo << endl;


	cout << "Thuong a va b: ";
	if (f.MauSo == 0) cout << "khong ton tai thuong" << endl;
	else if (f.MauSo == 1) cout << f.TuSo << endl;
	else cout << f.TuSo << "/" << f.MauSo << endl;

	cout << "Thuong b va a: ";
	if (f.TuSo == 0) cout << "khong ton tai thuong" << endl;
	else if (f.MauSo == 1 && f.TuSo != 1) cout << f.MauSo << "/" << f.TuSo << endl;
	else if (f.MauSo == 1 && f.TuSo == 1) cout << 1;
	else cout << f.MauSo << "/" << f.TuSo << endl;

}
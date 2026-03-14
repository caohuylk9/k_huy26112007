//
//#include <iostream>
//using namespace std;
//struct PhanSo
//{
//	long long TuSo, MauSo;
//};
//void RutGon(PhanSo& x)
//{
//	long long m = x.TuSo;
//	long long n = x.MauSo;
//	while (n != 0)
//	{
//		long long temp = m % n;
//		m = n;
//		n = temp;
//	}
//	x.TuSo /= m;
//	x.MauSo /= m;
//	if (x.MauSo < 0)
//	{
//
//		x.TuSo = -x.TuSo;
//		x.MauSo = -x.MauSo;
//	}
//}
//int main()
//{
//	PhanSo a;
//	cin >> a.TuSo >> a.MauSo;
//	if (a.TuSo == 0) {cout << 0;return 0;}
//  if (a.MauSo == 0) return 0;				// nếu mẫu bằng 0 thì không in ra gì
//	RutGon(a);
//	if (a.MauSo == 1) cout << a.TuSo;
//	else cout << a.TuSo << "/" << a.MauSo;
//	return 0;
//
//}






//#include <iostream>
//using namespace std;
//struct PhanSo					// khai báo một kiểu dữ liệu phân số 
//{
//	long long TuSo, MauSo;			// phân số bao gồm tử và mẫu
//};
//void RutGon(PhanSo& x)
//{
//	long long m = x.TuSo;
//	long long n = x.MauSo;
//	while (n != 0)
//	{
//		long long temp = m % n;
//		m = n;
//		n = temp;
//	}
//	x.TuSo /= m;
//	x.MauSo /= m;
//	if (x.MauSo < 0)
//	{
//			x.TuSo = -x.TuSo;
//			x.MauSo = -x.MauSo;
//	}
//
//}
//int main()
//{
//	PhanSo a, b;
//	cin >> a.TuSo >> a.MauSo >> b.TuSo >> b.MauSo; // lần lượt nhập phân số đầu và phân số thứ 2 vào
//	long long ps1 = a.TuSo * b.MauSo;	// sử dụng nhân chéo để so sánh
//	long long ps2 = b.TuSo * a.MauSo;
//	if (a.TuSo == 0 && b.TuSo == 0) cout << 0;
//	else if (a.MauSo == 0 || b.MauSo == 0) return 0;   // nếu mẫu 1 trong 2 bằng 0 thì không in ra gì
//	else if (ps1 > ps2)							// đề bài không yêu cầu rút gọn nhưng vì em thấy code hàm rút gọn rồi dùng cho mỗi 1 bài thì phí quá nên em đưa vào bài sau luôn
//	{
//		RutGon(a);
//		if (a.MauSo == 1) cout << a.TuSo;
//		else cout << a.TuSo << "/" << a.MauSo;
//	}
//	else // nếu 2 phân số bằng nhau thì sau khi rút gọn 2 phân số đều như nhau nên chỉ cần in ra 1 trong 2
//	{
//		RutGon(b);
//		if (b.MauSo == 1) cout << b.TuSo;
//		else cout << b.TuSo << "/" << b.MauSo;
//	}
//
//}


//#include <iostream>
//using namespace std;
//struct PhanSo					// khai báo một kiểu dữ liệu phân số 
//{
//	long long TuSo, MauSo;			// phân số bao gồm tử và mẫu
//};
//void RutGon(PhanSo& x)
//{
//	long long m = x.TuSo;
//	long long n = x.MauSo;
//	while (n != 0)
//	{
//		long long temp = m % n;
//		m = n;
//		n = temp;
//	}
//	x.TuSo /= m;
//	x.MauSo /= m;
//	if (x.MauSo < 0)
//	{
//			x.TuSo = -x.TuSo;
//			x.MauSo = -x.MauSo;
//	}
//
//}
//int main()
//{
//	PhanSo a, b;
//	cin >> a.TuSo >> a.MauSo >> b.TuSo >> b.MauSo;
//	if (a.MauSo == 0 || b.MauSo == 0) { cout << "phan so sai "; return 0; }
//	else if (a.TuSo == 0 && b.TuSo == 0)
//	{
//		cout << "Tong: 0 " <<endl;
//		cout << "Hieu a va b: 0" << endl;
//		cout << "Hieu b va a: 0" << endl;
//		cout << "Tich: 0" << endl;
//		cout << "Khong ton tai thuong";
//		return 0;
//	}
//	RutGon(a);
//	RutGon(b);
//	PhanSo c, d, e, f;							// 4 phân số này lần lượt là tổng, hiệu , tích, thương
//
//	c.TuSo = a.TuSo * b.MauSo + a.MauSo * b.TuSo; 
//	c.MauSo = a.MauSo * b.MauSo;
//	RutGon(c);									// rút gọn tổng
//
//	d.TuSo = a.TuSo * b.MauSo - a.MauSo * b.TuSo;
//	d.MauSo = a.MauSo * b.MauSo;
//	RutGon(d);									// rút gọn hiệu a và b
//
//	e.TuSo = a.TuSo * b.TuSo;
//	e.MauSo = a.MauSo * b.MauSo;
//	RutGon(e);									// rút gọn tích
//
//	f.TuSo = a.TuSo * b.MauSo;
//	f.MauSo = a.MauSo * b.TuSo;
//	RutGon(f);									// rút gọn thương
//
//	cout << "Tong: ";
//	if (c.MauSo == 1) cout << c.TuSo << endl;
//	else cout << c.TuSo << "/" << c.MauSo << endl;
//
//	cout << "Hieu a va b: ";
//	if (d.MauSo == 1) cout << d.TuSo << endl;
//	else cout << d.TuSo << "/" << d.MauSo << endl;
//
//	cout << "Hieu b va a: ";
//	if (d.MauSo == 1) cout << -d.TuSo << endl;
//	else cout << -d.TuSo << "/" << d.MauSo << endl;
//
//	cout << "Tich: ";
//	if (e.MauSo == 1) cout << e.TuSo << endl;
//	else cout << e.TuSo << "/" << e.MauSo << endl;
//
//	
//	cout << "Thuong a va b: ";
//	if (f.MauSo == 0) cout << "khong ton tai thuong" << endl;
//	else if (f.MauSo == 1) cout << f.TuSo << endl;
//	else cout << f.TuSo << "/" << f.MauSo << endl;
//
//	cout << "Thuong b va a: ";
//	if (f.TuSo == 0) cout << "khong ton tai thuong" << endl;
//	else if (f.MauSo == 1 && f.TuSo != 1) cout << f.MauSo << "/" << f.TuSo << endl;
//	else if (f.MauSo == 1 && f.TuSo == 1) cout << 1;
//	else cout << f.MauSo << "/" << f.TuSo << endl;
//
//}

//#include <iostream>
//using namespace std;
//struct Date
//{
//	int d, m, y;
//};
//
//void Nhap(Date  &a)
//{
//	cin >> a.d >> a.m >> a.y;
//}
//int main()
//{
//	Date a;
//	Nhap(a);
//	int songay;
//	if (a.m == 1 || a.m == 3 || a.m == 5 || a.m == 7 || a.m == 8 || a.m == 10 || a.m == 12) songay = 31;
//	else if (a.m == 4 || a.m == 6 || a.m == 9 || a.m == 11) songay = 30;
//	else if ( a.m == 2)
//	{
//		if ((a.y % 4 == 0 && a.y % 100 != 0) || a.y % 400 == 0) songay = 29;
//		else songay = 28;
//	}
//	a.d++;
//	if (a.d > songay) { a.d = 1; a.m++; }
//	if (a.m > 12) { a.m = 1; a.y++; }
//	cout << a.d << "/" << a.m << "/" << a.y;
//	
//}






//
//#include <iostream>
//#include <string>
//#include <iomanip>
//using namespace std;
//struct HocSinh
//{
//	string ten;
//	double DiemToan, DiemVan;
//};
//int main()
//{
//	HocSinh a;
//	getline(cin,a.ten);
//	cin >> a.DiemToan >> a.DiemVan;
//	cout << "Ho Ten: " << a.ten << endl;
//	cout << "Diem Trung Binh: " << fixed << setprecision(2) <<(a.DiemToan + a.DiemVan) / 2 << endl;
//}

























// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

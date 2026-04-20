#pragma once
#include <vector>
using namespace std;
class cDaThuc
{
private:
	int bac;
	vector <double> a;
public:
	cDaThuc(int b = 0);
	void Nhap();
	void Xuat();
	cDaThuc CongDaThuc(cDaThuc b);
	cDaThuc TruDaThuc(cDaThuc c);
	double GiaTriDaThuc(double x);
	void ChuanHoa();
};


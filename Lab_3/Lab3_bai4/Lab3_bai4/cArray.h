#pragma once
#include <vector>
using namespace std;
class cArray
	// Khai báo class cArray
{
private:
	vector <int> a;
public:
	void TaoNgauNhien();
	void Nhap();
	void Xuat();
	int Dem( int n);
	bool KiemTraTangDan();
	int TimPhanTuLeNN();
	int TimSNTLN();
	void SapXepGiam();
	bool KiemTraSNT( int z);

};


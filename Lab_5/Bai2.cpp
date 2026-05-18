#include <iostream>
#include <string>
using namespace std;


class GiaoDich {
private:
	string MaGd, NgayGd; // Mã và Ngày giao dịch
	int DonGia;          // Đơn giá
	float ThanhTien, S;  // Thành tiền và Diện tích (S)

public:
	// Constructor lớp cha
	GiaoDich(string mgd = "", string ngd = "", int dg = 0, float tt = 0, float S = 0)
	{
		this->MaGd = mgd;
		this->NgayGd = ngd;
		this->DonGia = dg;
		this->ThanhTien = tt;
		this->S = S;
	}

	// Hàm ảo nhập dữ liệu chung
	virtual void Nhap(istream& in)
	{
		cout << "Nhap ma giao dich: ";
		getline(in, MaGd);
		cout << "Nhap ngay giao dich: ";
		getline(in, NgayGd);
		cout << "Nhap don gia: ";
		in >> DonGia;
		cout << "Nhap dien tich: ";
		in >> S;
	}

	// Nạp chồng toán tử >> để nhập dữ liệu đa hình
	friend istream& operator >> (istream& in, GiaoDich& a)
	{
		a.Nhap(in); // Tự động gọi đúng hàm Nhap() của lớp con
		return in;
	}

	// Hàm ảo xuất dữ liệu chung
	virtual void Xuat(ostream& out)
	{
		out << "Ma giao dich: " << MaGd
			<< " | Ngay giao dich: " << NgayGd
			<< " | Don gia: " << DonGia
			<< " | Dien tich: " << S
			<< " | Thanh tien: " << ThanhTien;
	}

	// Nạp chồng toán tử << để xuất dữ liệu đa hình
	friend ostream& operator<<(ostream& out, GiaoDich& a)
	{
		a.Xuat(out); // Tự động gọi đúng hàm Xuat() của lớp con
		return out;
	}

	// Các hàm cập nhật và lấy giá trị thuộc tính (Getter/Setter)
	void SetThanhTien(float a) { ThanhTien = a; }
	int getDonGia() { return DonGia; }
	float getDienTich() { return S; }
	float getThanhTien() { return ThanhTien; }

	// Lọc giao dịch thuộc tháng 12 năm 2024 bằng cách cắt chuỗi ngày sinh
	bool getDate()
	{
		int thang = stoi(NgayGd.substr(3, 2)); // Cắt lấy tháng
		int nam = stoi(NgayGd.substr(6, 4));   // Cắt lấy năm
		if (thang == 12 && nam == 2024) return true;
		return false;
	}

	// Hàm thuần ảo lấy loại giao dịch (1: Đất, 2: Nhà phố, 3: Chung cư)
	virtual int getLoaiGD() = 0;

	// Hàm thuần ảo tính tiền (bắt buộc lớp con tự định nghĩa công thức)
	virtual void TinhTien() = 0;

	// Hàm hủy ảo giúp xóa bộ nhớ động an toàn
	virtual ~GiaoDich() {};
};


class GiaoDichDat : public GiaoDich {
private:
	string LoaiDat; // Loại đất (A, B, C)

public:
	// Constructor lớp con gọi lại constructor lớp cha
	GiaoDichDat(string mgd = "", string ngd = "", int dg = 0, float tt = 0, string ld = "", float S = 0)
		: GiaoDich(mgd, ngd, dg, tt, S)
	{
		this->LoaiDat = ld;
	}

	// Tính tiền giao dịch đất (Đất loại A nhân thêm hệ số 1.5)
	void TinhTien()
	{
		if (LoaiDat == "A") SetThanhTien(getDienTich() * getDonGia() * 1.5f);
		else SetThanhTien(getDienTich() * getDonGia());
	}

	// Ghi đè hàm nhập
	void Nhap(istream& in)
	{
		GiaoDich::Nhap(in); // Gọi cha nhập thông tin chung trước
		cout << "Nhap loai dat: ";
		in.ignore();        // Xóa dấu xuống dòng sót lại
		getline(in, LoaiDat);
	}

	// Ghi đè hàm xuất
	void Xuat(ostream& out)
	{
		GiaoDich::Xuat(out); // Gọi cha xuất thông tin chung trước
		out << " | Loai dat: " << LoaiDat << endl;
	}

	// Trả về số 1 đại diện cho giao dịch Đất
	int getLoaiGD() { return 1; }
	~GiaoDichDat() {};
};

class GiaoDichNhaPho : public GiaoDich {
private:
	string LoaiNha, DiaChi; // Loại nhà (caocap, thuong), địa chỉ

public:
	// Constructor lớp con gọi lại constructor lớp cha
	GiaoDichNhaPho(string mgd = "", string ngd = "", int dg = 0, float tt = 0, string ln = "", string dc = "", float S = 0)
		: GiaoDich(mgd, ngd, dg, tt, S)
	{
		this->LoaiNha = ln;
		this->DiaChi = dc;
	}

	// Tính tiền nhà phố (Nhà thường chỉ tính 90% tiền -> nhân 0.9)
	void TinhTien()
	{
		if (LoaiNha == "caocap") SetThanhTien(getDienTich() * getDonGia());
		else SetThanhTien(getDienTich() * getDonGia() * 0.9f);
	}

	// Ghi đè hàm nhập
	void Nhap(istream& in)
	{
		GiaoDich::Nhap(in); // Gọi cha nhập thông tin chung trước
		cout << "Nhap loai nha: ";
		in.ignore();        // Xóa dấu xuống dòng sót lại
		getline(in, LoaiNha);
		cout << "Nhap dia chi: ";
		getline(in, DiaChi);
	}

	// Ghi đè hàm xuất
	void Xuat(ostream& out)
	{
		GiaoDich::Xuat(out); // Gọi cha xuất thông tin chung trước
		out << " | Loai nha: " << LoaiNha << " | Dia chi: " << DiaChi << endl;
	}

	// Trả về số 2 đại diện cho giao dịch Nhà phố
	int getLoaiGD() { return 2; }
	~GiaoDichNhaPho() {};
};


class GiaoDichCanHoCC : public GiaoDich {
private:
	string MaCan;  // Mã căn hộ
	int ViTriTang; // Vị trí tầng

public:
	// Constructor lớp con gọi lại constructor lớp cha
	GiaoDichCanHoCC(string mgd = "", string ngd = "", int dg = 0, float tt = 0, string MaCan = "", float S = 0, int vt = 0)
		: GiaoDich(mgd, ngd, dg, tt, S)
	{
		this->MaCan = MaCan;
		this->ViTriTang = vt;
	}

	// Ghi đè hàm nhập
	void Nhap(istream& in)
	{
		GiaoDich::Nhap(in); // Gọi cha nhập thông tin chung trước
		cout << "Nhap vi tri tang: ";
		in >> ViTriTang;
		in.ignore();        // Xóa dấu xuống dòng sót lại
		cout << "Nhap ma can: ";
		getline(in, MaCan);
	}

	// Ghi đè hàm xuất
	void Xuat(ostream& out)
	{
		GiaoDich::Xuat(out); // Gọi cha xuất thông tin chung trước
		out << " | Ma can: " << MaCan << " | Vi tri tang: " << ViTriTang << endl;
	}

	// Tính tiền chung cư (Tầng 1 nhân hệ số 2, tầng >=15 nhân hệ số 1.2)
	void TinhTien()
	{
		if (ViTriTang == 1) SetThanhTien(getDienTich() * getDonGia() * 2);
		else if (ViTriTang >= 15) SetThanhTien(getDienTich() * getDonGia() * 1.2f);
		else SetThanhTien(getDienTich() * getDonGia());
	}

	// Trả về số 3 đại diện cho giao dịch Chung cư
	int getLoaiGD() { return 3; }
	~GiaoDichCanHoCC() {};
};


int main() {
	cout << "Nhap so giao dich: ";
	int n;
	cin >> n;

	// Tạo mảng động chứa các con trỏ lớp cha (Quản lý đa hình)
	GiaoDich** a = new GiaoDich * [n];

	// Vòng lặp nhập danh sách giao dịch
	for (int i = 0; i < n; i++)
	{
		cout << "====NHAP LOAI GIAO DICH=====\n";
		cout << "1:Giao dich dat | 2:Giao dich nha pho | 3:Giao dich can ho chung cu \n";
		int z;
		cin >> z;
		cin.ignore(); // Xóa dấu xuống dòng sau khi nhập số z

		// Khởi tạo vùng nhớ đúng cho loại giao dịch được chọn
		if (z == 1) a[i] = new GiaoDichDat;
		else if (z == 2) a[i] = new GiaoDichNhaPho;
		else a[i] = new GiaoDichCanHoCC;

		cin >> *a[i];     // Nhập dữ liệu (Đa hình)
		a[i]->TinhTien(); // Tính tiền ngay sau khi nhập (Đa hình)
	}

	// Vòng lặp xuất danh sách giao dịch
	cout << "====DANH SACH GIAO DICH=====\n";
	for (int i = 0; i < n; i++)
	{
		cout << *a[i]; // Xuất dữ liệu (Đa hình)
	}

	// Đếm số lượng giao dịch của từng loại
	int gdDat = 0, gdNhaPho = 0, gdCanHoCC = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->getLoaiGD() == 1) gdDat++;
		else if (a[i]->getLoaiGD() == 2) gdNhaPho++;
		else gdCanHoCC++;
	}
	cout << " \n\n\n=======SO GIAO DICH MOI LOAI=======: \n";
	cout << "Giao dich dat: " << gdDat << " giao dich.\n";
	cout << "Giao dich nha pho: " << gdNhaPho << " giao dich.\n";
	cout << "Giao dich can ho chung cu: " << gdCanHoCC << " giao dich.\n";

	// Tính trung bình thành tiền của riêng Căn hộ chung cư
	float T = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->getLoaiGD() == 3) // Chỉ cộng dồn nếu là chung cư
			T += a[i]->getThanhTien();
	}
	T /= gdCanHoCC; // Tổng tiền chia tổng số lượng chung cư
	if (gdCanHoCC > 0) {
		T /= gdCanHoCC;
		cout << "\n\n\nTrung binh thanh tien cua can ho chung cu: " << T;
	}
	else {
		cout << "\n\n\nTrung binh thanh tien cua can ho chung cu: 0 (Khong co giao dich chung cu nao!)";
	}

	// Tìm giao dịch Nhà Phố có giá trị (thành tiền) cao nhất
	int vt = -1; // vt lưu vị trí giao dịch nhà phố đắt nhất
	for (int i = 0; i < n; i++)
	{
		if (a[i]->getLoaiGD() == 2) // Chỉ xét Nhà phố
		{
			// Nếu là nhà phố đầu tiên gặp (vt == -1) hoặc tiền lớn hơn mốc cũ thì cập nhật vt mới
			if (vt == -1 || a[i]->getThanhTien() > a[vt]->getThanhTien()) vt = i;
		}
	}
	if (vt != -1)
	{
		cout << "\n\n\nGiao dich nha pho co gia tri cao nhat: \n";
		cout << *a[vt];
	}

	// Xuất các giao dịch diễn ra vào tháng 12 năm 2024
	cout << "\nDanh sach giao dich cua thang 12 nam 2024: \n";
	for (int i = 0; i < n; i++)
	{
		if (a[i]->getDate()) cout << *a[i]; // Nếu đúng tháng 12/2024 thì in ra
	}

	// Giải phóng bộ nhớ động tránh lãng phí RAM
	for (int i = 0; i < n; i++) {
		delete a[i];
	}
	delete[] a;

	return 0;
}
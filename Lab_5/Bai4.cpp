#include <iostream>
#include <string>
using namespace std;


class NhanVien
{
private:
	string MaNV, HoTen, email, SDT; // Mã, họ tên, email, số điện thoại
	int Tuoi, LuongCB;              // Tuổi, lương cơ bản
	long long Luong;                // Tổng lương thực nhận

public:
	// Constructor lớp cha
	NhanVien(string MaNV = "", string HoTen = "", string email = "", string sdt = ""
		, int t = 0, int lcb = 0, long long l = 0)
	{
		this->MaNV = MaNV;
		this->HoTen = HoTen;
		this->email = email;
		this->SDT = sdt;
		this->Tuoi = t;
		this->LuongCB = lcb;
		this->Luong = l;
	}

	// Hàm ảo nhập thông tin chung
	virtual void Nhap(istream& in)
	{
		cout << "Nhap ma nhan vien: ";
		getline(in, MaNV);
		cout << "Nhap ho ten: ";
		getline(in, HoTen);
		cout << "Nhap so tuoi: ";
		in >> Tuoi;
		in.ignore(); // Xóa dấu xuống dòng để không bị trôi lệnh getline phía sau
		cout << "Nhap email: ";
		getline(in, email);
		cout << "Nhap so dien thoai: ";
		getline(in, SDT);
		cout << "Nhap luong co ban: ";
		in >> LuongCB;
		in.ignore(); // Xóa dấu xuống dòng chuẩn bị cho lớp con nhập tiếp
	}

	// Nạp chồng toán tử >> để nhập dữ liệu đa hình
	friend istream& operator >> (istream& in, NhanVien& a)
	{
		a.Nhap(in); // Tự động gọi đúng hàm Nhap() của lớp con
		return in;
	}

	// Hàm ảo xuất thông tin chung
	virtual void Xuat(ostream& out)
	{
		out << "Ma NV: " << MaNV
			<< " | Ho ten: " << HoTen
			<< " | Tuoi: " << Tuoi
			<< " | SDT: " << SDT
			<< " | Email: " << email
			<< " | Luong co ban: " << LuongCB;
	}

	// Nạp chồng toán tử << để xuất dữ liệu đa hình
	friend ostream& operator << (ostream& out, NhanVien& a)
	{
		a.Xuat(out); // Tự động gọi đúng hàm Xuat() của lớp con
		return out;
	}

	// Các hàm Getter / Setter để tương tác với thuộc tính private
	void setLuong(long long Luong) { this->Luong = Luong; }
	long long getLuong() { return Luong; }
	int getLuongCB() { return LuongCB; }

	// Hàm thuần ảo bắt buộc lớp con phải tự định nghĩa lại
	virtual void Tinh_Luong() = 0; // Tính tổng lương thực nhận
	virtual int LoaiNV() = 0;      // Lấy loại NV (1: Lập trình, 2: Kiểm chứng)
};


class LapTrinhVien : public NhanVien
{
private:
	int SoGioOT; // Số giờ làm thêm (Overtime)

public:
	// Constructor lớp con gọi lại constructor lớp cha
	LapTrinhVien(string MaNV = "", string HoTen = "", string email = "", string sdt = ""
		, int t = 0, int lcb = 0, long long l = 0, int SoGioOT = 0)
		: NhanVien(MaNV, HoTen, email, sdt, t, lcb, l)
	{
		this->SoGioOT = SoGioOT;
	}

	// Ghi đè hàm nhập
	void Nhap(istream& in)
	{
		NhanVien::Nhap(in); // Gọi cha nhập thông tin chung trước
		cout << "NHap so gio overtime: ";
		in >> SoGioOT;
		in.ignore();        // Xóa dấu xuống dòng sót lại
	}

	// Ghi đè hàm xuất
	void Xuat(ostream& out)
	{
		NhanVien::Xuat(out); // Gọi cha xuất thông tin chung trước
		out << " | So gio overtime: " << SoGioOT
			<< " | Luong: " << getLuong() << endl;;
	}

	// Tính lương Lập trình viên = Lương CB + Số giờ OT * 200.000
	void Tinh_Luong()
	{
		setLuong(getLuongCB() + SoGioOT * 200000);
	}

	// Trả về số 1 đại diện cho Lập trình viên
	int LoaiNV() { return 1; }
};

class KiemChungVien : public NhanVien
{
private:
	int SoLoi; // Số lỗi phát hiện được (Bugs)

public:
	// Constructor lớp con gọi lại constructor lớp cha
	KiemChungVien(string MaNV = "", string HoTen = "", string email = "", string sdt = ""
		, int t = 0, int lcb = 0, long long l = 0, int SoLoi = 0)
		: NhanVien(MaNV, HoTen, email, sdt, t, lcb, l)
	{
		this->SoLoi = SoLoi;
	}

	// Ghi đè hàm nhập
	void Nhap(istream& in)
	{
		NhanVien::Nhap(in); // Gọi cha nhập thông tin chung trước
		cout << "NHap so loi da duoc phat hien: ";
		in >> SoLoi;
		in.ignore();        // Xóa dấu xuống dòng sót lại
	}

	// Ghi đè hàm xuất
	void Xuat(ostream& out)
	{
		NhanVien::Xuat(out); // Gọi cha xuất thông tin chung trước
		out << " | So loi: " << SoLoi
			<< " | Luong: " << getLuong() << endl;;
	}

	// Tính lương Kiểm chứng viên = Lương CB + Số lỗi * 50.000
	void Tinh_Luong()
	{
		setLuong(getLuongCB() + SoLoi * 50000);
	}

	// Trả về số 2 đại diện cho Kiểm chứng viên
	int LoaiNV() { return 2; }
};

int main()
{
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	cin.ignore(); // Xóa dấu xuống dòng sau khi nhập số lượng n

	// Tạo mảng động chứa các con trỏ lớp cha (Quản lý đa hình)
	NhanVien** a = new NhanVien * [n];

	// Vòng lặp nhập danh sách nhân viên
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap 1: Lap Trinh Vien | Nhap 2: Kiem Chung Vien \n";
		int z;
		cin >> z;
		cin.ignore(); // Xóa dấu xuống dòng sau khi nhập lựa chọn z

		// Khởi tạo vùng nhớ đúng dựa vào lựa chọn
		if (z == 1) a[i] = new LapTrinhVien;
		else a[i] = new KiemChungVien;

		cin >> *a[i];       // Nhập dữ liệu (Đa hình)
		a[i]->Tinh_Luong(); // Tính lương ngay sau khi nhập (Đa hình)
	}

	// Vòng lặp xuất toàn bộ danh sách nhân viên
	cout << "\n\n\n=========DANH SACH NHAN VIEN==========\n";
	for (int i = 0; i < n; i++)
	{
		cout << *a[i];
	}

	// Tính tổng lương và lương trung bình của cả công ty
	long long TongLuong = 0;
	for (int i = 0; i < n; i++)
	{
		TongLuong += a[i]->getLuong();
	}
	double LuongTB = TongLuong * 1.0 / n;

	// Lọc danh sách nhân viên có lương dưới mức trung bình công ty
	cout << "\n\n\n==========DANH SACH NHAN VIEN LUONG THAP HON MUC LUONG TRUNG BINH============\n";
	for (int i = 0; i < n;i++)
	{
		if (a[i]->getLuong() * 1.0 < LuongTB) cout << *a[i];
	}

	// Tìm nhân viên có lương cao nhất và thấp nhất toàn công ty
	int NVmaxL = 0; // Lưu vị trí người có lương cao nhất
	int NVminL = 0; // Lưu vị trí người có lương thấp nhất
	for (int i = 0; i < n; i++)
	{
		if (a[i]->getLuong() > a[NVmaxL]->getLuong()) NVmaxL = i;
		if (a[i]->getLuong() < a[NVminL]->getLuong()) NVminL = i;
	}
	cout << "Nhan vien co luong cao nhat: \n";
	cout << *a[NVmaxL];
	cout << "Nhan vien co luong thap nhat: \n";
	cout << *a[NVminL];

	// Tìm riêng Lập trình viên có lương cao nhất công ty
	int vitri = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->LoaiNV() == 1) // Chỉ xét Lập trình viên
		{
			if (vitri == -1 || a[i]->getLuong() > a[vitri]->getLuong()) vitri = i;
		}
	}
	if (vitri != -1)
	{
		cout << "Nhan vien lap trinh co luong cao nhat: \n";
		cout << *a[vitri];
	}
	else cout << "Trong danh sach khong co lap trinh vien !! \n";

	// Tìm riêng Kiểm chứng viên có lương thấp nhất công ty
	int vt = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->LoaiNV() == 2) // Chỉ xét Kiểm chứng viên
		{
			if (vt == -1 || a[i]->getLuong() < a[vt]->getLuong()) vt = i;
		}
	}
	if (vt != -1)
	{
		cout << "Kiem chung vien co muc luong thap nhat: \n";
		cout << *a[vt];
	}
	else cout << "Trong danh sach khong co kiem chung vien!! \n";

	// Giải phóng bộ nhớ động tránh rò rỉ RAM (Memory Leak)
	for (int i = 0; i < n; i++)
	{
		delete a[i];
	}
	delete[] a;
}
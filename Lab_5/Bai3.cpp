	#include <iostream>
	#include <string>
	using namespace std;


	class SinhVien {
	private:
		string MSSV, HoTen, DiaChi; // Mã số, họ tên, địa chỉ
		int SoTinChi;               // Số tín chỉ tích lũy
		float DiemTB;               // Điểm trung bình đại học

	public:
		// Constructor lớp cha
		SinhVien(string mssv = "", string ht = "", string dc = "", int sotc = 0, float dtb = 0)
		{
			this->MSSV = mssv;
			this->HoTen = ht;
			this->DiaChi = dc;
			this->SoTinChi = sotc;
			this->DiemTB = dtb;
		}

		// Hàm ảo nhập thông tin chung
		virtual void Nhap(istream& in)
		{
			cout << "Nhap ma so sinh vien : ";
			getline(in, MSSV);
			cout << "Nhap ho va ten: ";
			getline(in, HoTen);
			cout << "Nhap dia chi: ";
			getline(in, DiaChi);
			cout << "Nhap so tin chi: ";
			in >> SoTinChi;
			cout << "Nhap diem trung binh: ";
			in >> DiemTB;
		}

		// Nạp chồng toán tử >> để nhập dữ liệu đa hình
		friend istream& operator >> (istream& in, SinhVien& a)
		{
			a.Nhap(in); // Tự động gọi đúng hàm Nhap() của lớp con
			return in;
		}

		// Hàm ảo xuất thông tin chung
		virtual void Xuat(ostream& out)
		{
			cout << "MSSV: " << MSSV << "  | Ho va Ten: " << HoTen << "  | Dia chi: "
				<< DiaChi << "  | Tong so tin chi: " << SoTinChi << "  | Diem trung binh: "
				<< DiemTB;
		}

		// Nạp chồng toán tử << để xuất dữ liệu đa hình
		friend ostream& operator << (ostream& out, SinhVien& a)
		{
			a.Xuat(out); // Tự động gọi đúng hàm Xuat() của lớp con
			return out;
		}

		// Các hàm Getter để lấy giá trị thuộc tính private từ bên ngoài
		float getDTB() { return DiemTB; }
		int getSoTinChi() { return SoTinChi; }

		// Hàm thuần ảo kiểm tra tốt nghiệp (lớp con tự định nghĩa điều kiện riêng)
		virtual bool CheckDKTN() = 0;

		// Hàm thuần ảo lấy loại sinh viên (1: Đại học, 2: Cao đẳng)
		virtual int getLoai() = 0;

		// Hàm hủy ảo giúp xóa bộ nhớ động an toàn
		virtual ~SinhVien() {};
	};


	class SinhVienDH : public SinhVien {
	private:
		string TenLuanVan; // Tên luận văn tốt nghiệp
		float DiemLuanVan; // Điểm luận văn

	public:
		// Constructor lớp con gọi lại constructor lớp cha
		SinhVienDH(string mssv = "", string ht = "", string dc = "", int sotc = 0, float dtb = 0, string TenLuanVan = "",
			float DiemLuanVan = 0)
			:SinhVien(mssv, ht, dc, sotc, dtb)
		{
			this->TenLuanVan = TenLuanVan;
			this->DiemLuanVan = DiemLuanVan;
		}

		// Ghi đè hàm nhập
		void Nhap(istream& in)
		{
			SinhVien::Nhap(in); // Gọi cha nhập thông tin chung trước
			in.ignore();        // Xóa dấu xuống dòng sót lại sau khi nhập Điểm TB ở hàm cha
			cout << "Nhap ten luan van: ";
			getline(in, TenLuanVan);
			cout << "Nhap diem luan van: ";
			in >> DiemLuanVan;
		}

		// Ghi đè hàm xuất
		void Xuat(ostream& out)
		{
			SinhVien::Xuat(out); // Gọi cha xuất thông tin chung trước
			out << "  | Ten luan van: " << TenLuanVan << "  | Diem luan van: " << DiemLuanVan << endl;
		}

		// Điều kiện tốt nghiệp Đại học: Tín chỉ >= 170, Điểm TB >= 5, Điểm luận văn >= 5
		bool CheckDKTN()
		{
			if (getSoTinChi() >= 170 && getDTB() >= 5 && DiemLuanVan >= 5)
				return true;
			return false;
		}

		// Trả về số 1 đại diện cho sinh viên Đại học
		int getLoai() { return 1; }
	};

	class SinhVienCD : public SinhVien {
	private:
		float DiemThiTN; // Điểm thi tốt nghiệp

	public:
		// Constructor lớp con gọi lại constructor lớp cha
		SinhVienCD(string mssv = "", string ht = "", string dc = "", int sotc = 0, float dtb = 0,
			float DiemThiTN = 0)
			:SinhVien(mssv, ht, dc, sotc, dtb)
		{
			this->DiemThiTN = DiemThiTN;
		}

		// Ghi đè hàm nhập
		void Nhap(istream& in)
		{
			SinhVien::Nhap(in); // Gọi cha nhập thông tin chung trước
			cout << "Diem thi tot nghiep: ";
			in >> DiemThiTN;
		}

		// Ghi đè hàm xuất
		void Xuat(ostream& out)
		{
			SinhVien::Xuat(out); // Gọi cha xuất thông tin chung trước
			out << "  | Diem thi tot nghiep: " << DiemThiTN << endl;
		}

		// Điều kiện tốt nghiệp Cao đẳng: Tín chỉ >= 120, Điểm TB >= 5, Điểm thi TN >= 5
		bool CheckDKTN()
		{
			if (getSoTinChi() >= 120 && getDTB() >= 5 && DiemThiTN >= 5)
				return true;
			return false;
		}

		// Trả về số 2 đại diện cho sinh viên Cao đẳng
		int getLoai() { return 2; }
	};

	int main() {
		cout << "Nhap so luong sinh vien: ";
		int n;
		cin >> n;

		// Tạo mảng động chứa các con trỏ lớp cha (Quản lý đa hình)
		SinhVien** a = new SinhVien * [n];

		// Vòng lặp nhập danh sách sinh viên
		for (int i = 0; i < n; i++)
		{
			cout << "===LOAI SINH VIEN===\n";
			cout << "Nhap 1: Sinh vien dai hoc | Nhap 2: Sinh vien cao dang" << endl;
			int z;
			cin >> z;
			cin.ignore(); // Xóa dấu xuống dòng sau khi nhập số z

			// Khởi tạo vùng nhớ đúng cho loại sinh viên được chọn
			if (z == 1) a[i] = new SinhVienDH;
			else a[i] = new SinhVienCD;

			cin >> *a[i]; // Nhập dữ liệu (Đa hình)
		}

		// Vòng lặp xuất toàn bộ danh sách sinh viên đã nhập
		cout << "========DANH SACH SINH VIEN=========\n";
		for (int i = 0; i < n; i++)
		{
			cout << *a[i]; // Xuất dữ liệu (Đa hình)
		}

		// Lọc danh sách sinh viên ĐỦ điều kiện tốt nghiệp
		cout << "\n\n\n=======DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP=======\n";
		for (int i = 0; i < n; i++)
		{
			if (a[i]->CheckDKTN()) {
				cout << *a[i];
			}
		}

		// Lọc danh sách sinh viên KHÔNG ĐỦ điều kiện tốt nghiệp
		cout << "\n\n\n========DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP========\n";
		int DHKoTN = 0; // Biến đếm số SV Đại học trượt tốt nghiệp
		int CDKoTN = 0; // Biến đếm số SV Cao đẳng trượt tốt nghiệp
		for (int i = 0; i < n; i++)
		{
			if (a[i]->getLoai() == 1) // Nếu là sinh viên Đại học
			{
				if (!a[i]->CheckDKTN()) {
					DHKoTN++;
					cout << *a[i];
				}
			}
			else // Nếu là sinh viên Cao đẳng
			{
				if (!a[i]->CheckDKTN())
				{
					CDKoTN++;
					cout << *a[i];
				}
			}
		}

		// Tìm sinh viên Đại học có điểm trung bình cao nhất (Max DTB)
		cout << "\nSINH VIEN DAI HOC CO DIEM TRUNG BINH CAO NHAT: \n";
		int sv = -1; // Biến lưu vị trí thủ khoa Đại học
		for (int i = 0; i < n; i++)
		{
			if (a[i]->getLoai() == 1) // Chỉ xét hệ Đại học
			{
				if (sv == -1 || a[i]->getDTB() > a[sv]->getDTB()) sv = i;
			}
		}
		// Kiểm tra điều kiện phòng hờ danh sách trống sinh viên Đại học
		if (sv != -1) cout << *a[sv];
		else cout << "Khong co sinh vien dai hoc nao trong danh sach!\n";

		// Tìm sinh viên Cao đẳng có điểm trung bình cao nhất (Max DTB)
		cout << "\nSINH VIEN CAO DANG CO DIEM TRUNG BINH CAO NHAT: \n";
		int svv = -1; // Biến lưu vị trí thủ khoa Cao đẳng
		for (int i = 0; i < n; i++)
		{
			if (a[i]->getLoai() == 2) // Chỉ xét hệ Cao đẳng
			{
				if (svv == -1 || a[i]->getDTB() > a[svv]->getDTB()) svv = i;
			}
		}
		// Kiểm tra điều kiện phòng hờ danh sách trống sinh viên Cao đẳng
		if (svv != -1) cout << *a[svv];
		else cout << "Khong co sinh vien cao dang nao trong danh sach!\n";

		// In số lượng tổng hợp sinh viên không đủ điều kiện tốt nghiệp
		cout << "\n====SO SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP==== \n";
		cout << "Sinh vien dai hoc: " << DHKoTN << " sinh vien\n";
		cout << "Sinh vien cao dang: " << CDKoTN << " sinh vien\n";

		// Giải phóng bộ nhớ động tránh rò rỉ RAM (Memory Leak)
		for (int i = 0; i < n; i++) {
			delete a[i];
		}
		delete[] a;

		return 0;
	}
#include <iostream>
#include <string>

using namespace std;

class NhanVien {
private:
    // Nhập họ tên, ngày sinh và lương
    string ht, ns;
    long long luong;
public:
    // constructor hàm cha
    NhanVien(string ht = "", string ns = "", long long luong = 0) {
        this->ht = ht;
        this->ns = ns;
        this->luong = luong;
    }

    // Hàm ảo nhập dữ liệu chung cho lớp cha
    virtual void Nhap(istream& in) {
        cout << "  Nhap ho va ten: ";
        getline(in, ht);
        cout << "  Nhap ngay sinh dd/mm/yyyy: ";
        getline(in, ns);
    }

    // Lồng hàm Nhap vào nạp chồng toán tử thể giúp thể hiện tính đa hình
    friend istream& operator >> (istream& in, NhanVien& a) {
        a.Nhap(in);
        return in;
    }

    // Toán tử << xuất dữ liệu đối tượng
    friend ostream& operator << (ostream& out, const NhanVien& a) {
        out << "Ho ten: " << a.ht << " | Ngay sinh: " << a.ns << " | Luong: " << a.luong << " VND" << endl;
        return out;
    }

    virtual void Tinh_Luong() = 0;

    long long getLuong() {
        return luong;
    }

    // Quy đổi chuỗi "dd/mm/yyyy" thành số "yyyymmdd" để so sánh ngày tháng năm chính xác
    long long getGiaTriNgaySinh() {
        if (ns.length() < 10) return 99999999; // Phòng hờ dữ liệu lỗi
        string ngay = ns.substr(0, 2);  // Lấy dd
        string thang = ns.substr(3, 2); // Lấy mm
        string nam = ns.substr(6, 4);   // Lấy yyyy
        return stoll(nam + thang + ngay); // Trả về số yyyymmdd
    }

    void setLuong(long long a) {
        luong = a;
    }

    virtual int getLoai() = 0;

    // Hàm hủy ảo giúp giải phóng bộ nhớ động của các lớp con một cách an toàn
    virtual ~NhanVien() {}
};

class NhanVienSX : public NhanVien {
private:
    long long lcb, ssp;
public:
    NhanVienSX(string ht = "", string ns = "", long long luong = 0, long long lcb = 0, long long ssp = 0)
        : NhanVien(ht, ns, luong) {
        this->lcb = lcb;
        this->ssp = ssp;
    }

    void Nhap(istream& in)  {
        NhanVien::Nhap(in); // Kế thừa: Gọi cha nhập Họ tên, Ngày sinh trước
        cout << "  Nhap luong co ban: ";
        in >> lcb;
        cout << "  Nhap so san pham: ";
        in >> ssp;
        in.ignore(); // Xóa ký tự '\n' còn sót để không trôi lệnh của người kế tiếp
    }

    void Tinh_Luong()  {
        setLuong(lcb + ssp * 5000);
    }

    int getLoai()  {
        return 1;
    }
};

class NhanVienVP : public NhanVien {
private:
    int songaylv;
public:
    NhanVienVP(string ht = "", string ns = "", long long luong = 0, int songaylv = 0)
        : NhanVien(ht, ns, luong) {
        this->songaylv = songaylv;
    }

    void Nhap(istream& in) {
        NhanVien::Nhap(in); // Kế thừa: Gọi cha nhập Họ tên, Ngày sinh trước
        cout << "  Nhap so ngay lam viec: ";
        in >> songaylv;
        in.ignore(); // Xóa ký tự '\n' còn sót để không trôi lệnh của người kế tiếp
    }

    void Tinh_Luong()  {
        setLuong(songaylv * 100000);
    }

    int getLoai() {
        return 2;
    }
};

int main() {
    cout << "Nhap so luong nhan vien: ";
    int n;
    cin >> n;

    NhanVien** a = new NhanVien * [n];

    // Nhập danh sách nhân viên
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        cout << "Chon loai (Nhap 1: NhanVienSX ; Nhap 2: NhanVienVP): ";
        int z;
        cin >> z;
        cin.ignore(); // Xóa dấu '\n' sau khi nhập số z để chuẩn bị cho getline ở hàm cha

        if (z == 1) a[i] = new NhanVienSX;
        else a[i] = new NhanVienVP;

        cin >> *a[i]; // Giải băm con trỏ thành đối tượng để nạp chồng toán tử >> hoạt động
        a[i]->Tinh_Luong(); // Tính lương ngay sau khi nhập xong dữ liệu
    }

    // Xuất danh sách nhân viên
    cout << "\n========================================\n";
    cout << "--- DANH SACH NHAN VIEN DA NHAP ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << *a[i];
    }

    // Tính tổng lương của tất cả nhân viên
    long long S = 0;
    for (int i = 0; i < n; i++) {
        S += a[i]->getLuong();
    }
    cout << "\n=> Tong luong tat ca nhan vien: " << S << " VND" << endl;

    // Tìm nhân viên Sản Xuất có lương thấp nhất
    int vt = -1;
    for (int i = 0; i < n; i++) {
        if (a[i]->getLoai() == 1) {
            // Check vt == -1 trước để gán phần tử đầu tiên làm gốc, chống lỗi truy cập a[-1]
            if (vt == -1 || a[i]->getLuong() < a[vt]->getLuong()) {
                vt = i;
            }
        }
    }
    cout << "\n========================================\n";
    if (vt != -1) {
        cout << "--- NHAN VIEN SAN XUAT CO LUONG THAP NHAT ---" << endl;
        cout << *a[vt];
    }
    else {
        cout << "Khong co nhan vien San Xuat nao trong danh sach!" << endl;
    }

    // Tìm nhân viên Văn Phòng có số tuổi lớn nhất (giá trị Ngày/Tháng/Năm nhỏ nhất)
    int vtt = -1;
    for (int i = 0; i < n; i++) {
        if (a[i]->getLoai() == 2) {
            // Biến vtt riêng biệt, so sánh toàn diện qua hàm getGiaTriNgaySinh()
            if (vtt == -1 || a[i]->getGiaTriNgaySinh() < a[vtt]->getGiaTriNgaySinh()) {
                vtt = i;
            }
        }
    }
    if (vtt != -1) {
        cout << "--- NHAN VIEN VAN PHONG CO TUOI LON NHAT ---" << endl;
        cout << *a[vtt];
    }
    else {
        cout << "Khong co nhan vien Van Phong nao trong danh sach!" << endl;
    }
    cout << "========================================\n";

    // Giải phóng bộ nhớ động tránh rò rỉ RAM (Memory Leak)
    for (int i = 0; i < n; i++) {
        delete a[i];
    }
    delete[] a;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;


class KhachHang {
private:
    string TenKH;    
    int SoLuong;
    double DonGia;

public:
    // Hàm ảo nhập dữ liệu chung
    virtual void Nhap(istream& in)
    {
        getline(in, TenKH);
        in >> SoLuong;
        in >> DonGia;
        in.ignore(); // Xóa dấu xuống dòng để tránh trôi lệnh cho các dòng getline tiếp theo
    }

    // Nạp chồng toán tử >> ngay trong lớp cha sử dụng cơ chế hàm ảo Nhap()
    friend istream& operator>>(istream& in, KhachHang& x)
    {
        x.Nhap(in); // Tự động gọi đúng hàm Nhap() của lớp con nhờ tính đa hình
        return in;
    }

    // Hàm thuần ảo tính tiền (mỗi loại khách hàng con sẽ có công thức riêng)
    virtual double TinhTien() = 0;

    // Hàm ảo xuất dữ liệu chung
    virtual void Xuat(ostream& out)
    {
        out << TenKH << endl;
        out << TinhTien() << endl; // Gọi hàm TinhTien() đa hình để xuất hóa đơn tương ứng
    }

    // Nạp chồng toán tử << ngay trong lớp cha sử dụng cơ chế hàm ảo Xuat()
    friend ostream& operator<<(ostream& out, KhachHang& x)
    {
        x.Xuat(out); // Tự động gọi đúng hàm Xuat() của lớp con nhờ tính đa hình
        return out;
    }

    // hàm truy suất dữ liệu private
    int getSoLuong() { return SoLuong; }
    double getDonGia() { return DonGia; }

    // Hàm hủy ảo đảm bảo giải phóng vùng nhớ lớp con an toàn khi dùng con trỏ lớp cha
    virtual ~KhachHang() {}
};


class KhachHangA : public KhachHang {
public:
    // Đã sửa: Thay đổi SoLuong, DonGia thành các hàm getSoLuong(), getDonGia()
    double TinhTien()
    {
        return getSoLuong() * getDonGia() * 1.1;
    }
};

class KhachHangB : public KhachHang {
private:
    int SoNamThanThiet; // Thuộc tính riêng: Số năm khách hàng gắn bó

public:
    // Ghi đè hàm nhập của lớp cha để bổ sung nhập số năm thân thiết
    void Nhap(istream& in)
    {
        KhachHang::Nhap(in); // Gọi lớp cha nhập Tên, Số lượng, Đơn giá trước
        in >> SoNamThanThiet;
        in.ignore();         // Xóa dấu xuống dòng thừa
    }

    double TinhTien()
    {
        double km = SoNamThanThiet * 0.05;

        if (km > 0.5) // Áp trần khuyến mãi: Nếu vượt quá 50% thì giữ ở mức 50%
            km = 0.5;

        return (getSoLuong() * getDonGia()) * (1 - km) * 1.1;
    }
};


class KhachHangC : public KhachHang {
public:

    double TinhTien()
    {
        return (getSoLuong() * getDonGia() * 0.5) * 1.1;
    }
};

int main() {
    int x, y, z;
    // Nhập số lượng phần tử cần khởi tạo cho từng nhóm khách hàng A, B, C
    cin >> x >> y >> z;
    cin.ignore(); // Xóa dấu xuống dòng sau khi nhập xong bộ 3 số lượng

    int n = x + y + z; // Tổng số lượng khách hàng toàn hệ thống

    // Tạo mảng động chứa các con trỏ lớp cha 
    KhachHang** a = new KhachHang * [n];

    int k = 0; // Biến con trỏ chỉ số chạy dọc mảng a để nạp liên tục

    // Nhóm vòng lặp khởi tạo và nhập Khách Hàng Loại A
    for (int i = 0; i < x; i++)
    {
        a[k] = new KhachHangA;
        cin >> *a[k]; // Gọi toán tử >> đa hình
        k++;
    }

    // Nhóm vòng lặp khởi tạo và nhập Khách Hàng Loại B
    for (int i = 0; i < y; i++)
    {
        a[k] = new KhachHangB;
        cin >> *a[k]; // Gọi toán tử >> đa hình
        k++;
    }

    // Nhóm vòng lặp khởi tạo và nhập Khách Hàng Loại C
    for (int i = 0; i < z; i++)
    {
        a[k] = new KhachHangC;
        cin >> *a[k]; // Gọi toán tử >> đa hình
        k++;
    }

    double TongTien = 0; // tổng doanh thu toàn bộ cửa hàng

    // Xuất lại bộ số lượng x y z ở đầu đầu ra
    cout << x << " " << y << " " << z << endl;

    // Vòng lặp xuất thông tin từng người và cộng dồn tiền
    for (int i = 0; i < n; i++)
    {
        cout << *a[i]; // Gọi toán tử << đa hình
        TongTien += a[i]->TinhTien();
    }

    // In ra tổng số tiền thu được ở cuối chương trình
    cout << TongTien << endl;

    // Vòng lặp giải phóng vùng nhớ cho từng đối tượng cụ thể
    for (int i = 0; i < n; i++)
    {
        delete a[i];
    }

    // Giải phóng hoàn toàn mảng con trỏ lớn
    delete[] a;

    return 0;
}
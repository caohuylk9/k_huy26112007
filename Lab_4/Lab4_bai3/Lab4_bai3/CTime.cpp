#include "CTime.h"
// constructor
CTime::CTime(int hh, int mm, int ss)
{
    h = hh;
    m = mm;
    s = ss;
    ChuanHoa();
}
// Hàm chuẩn hóa
void CTime::ChuanHoa()
{
    // Nếu giây >= 60 -> phút tăng
    // Nếu giây < 0 -> phút giảm
    if (s >= 60)
    {
        m += s / 60;
        s %= 60;
    }

    if (s < 0)
    {
        m += (s - 59) / 60;
        s = (s % 60 + 60) % 60;
    }

    // Tương tự bên trên
    if (m >= 60)
    {
        h += m / 60;
        m %= 60;
    }

    if (m < 0)
    {
        h += (m - 59) / 60;
        m = (m % 60 + 60) % 60;
    }

    // chuẩn hoá giờ 0–23
    h = (h % 24 + 24) % 24;
}

// + thêm giây
CTime CTime::operator+(int sec) const
{
    CTime t = *this;
    t.s += sec;
    t.ChuanHoa();
    return t;
}

//  - giây
CTime CTime::operator-(int sec) const
{
    CTime t = *this;
    t.s -= sec;
    t.ChuanHoa();
    return t;
}

//  ++ trước 
CTime& CTime::operator++()
{
    s++;
    ChuanHoa();
    return *this;
}

//++ sau 
CTime CTime::operator++(int)
{
    CTime tmp = *this;
    s++;
    ChuanHoa();
    return tmp;
}

// -- trước
CTime& CTime::operator--()
{
    s--;
    ChuanHoa();
    return *this;
}

// -- sau
CTime CTime::operator--(int)
{
    CTime tmp = *this;
    s--;
    ChuanHoa();
    return tmp;
}

// Định nghĩa lại hàm nhập
istream& operator>>(istream& in, CTime& t)
{
    in >> t.h >> t.m >> t.s;
    t.ChuanHoa();
    return in;
}

// Định nghĩa lại hàm xuất
ostream& operator<<(ostream& out, const CTime& t)
{
    if (t.h < 10) out << "0";
    // Thêm số 0 cho các số có 1 chữ số
    out << t.h << ":";

    if (t.m < 10) out << "0";
    out << t.m << ":";

    if (t.s < 10) out << "0";
    out << t.s;

    return out;
}
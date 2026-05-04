#pragma once
#include <iostream>
using namespace std;

class CTime
{
private:
    int h, m, s;
public:
    CTime(int hh = 0, int mm = 0, int ss = 0);
    void ChuanHoa();
    CTime operator +(int sec) const;
    CTime operator -(int sec) const;

    CTime& operator ++(); // ++ trước
    CTime operator ++(int); // ++ sau
    CTime& operator --(); // -- trước
    CTime operator --(int); // -- sau

    friend istream& operator>>(istream& in, CTime& t);
    friend ostream& operator<<(ostream& out, const CTime& t);
};
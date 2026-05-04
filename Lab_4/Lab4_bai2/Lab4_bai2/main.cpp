#include <iostream>
#include "PhanSo.h"
using namespace std;

int main()
{
    PhanSo a, b;
    cout << "Nhap a : ";
    cin >> a;
    cout << "Nhap b : ";
    cin >> b;

    cout << "\n a = " << a;
    cout << "\n b = " << b;

    cout << "\n a + b = " << a + b;
    cout << "\n a - b = " << a - b;
    cout << "\n a * b = " << a * b;

    try {
        cout << "\n a / b = " << a / b ;
        // Khi chạy a/b nếu không lỗi thì không vào catch
        // Nếu lỗi thì xuống in ra lỗi
    }
    catch (const char* msg) {
        cout << "\n Loi: " << msg;
    }

    if (a == b) cout << "\na = b" << endl;
    else if (a < b) cout << "\na < b" << endl;
    else cout << "\na > b" << endl;

    return 0;
}
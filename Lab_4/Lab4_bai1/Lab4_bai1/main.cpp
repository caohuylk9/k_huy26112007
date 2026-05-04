#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main()
{
    SoPhuc a, b;
    cout << "Nhap so phuc a (thuc, ao): ";
    cin >> a;
    cout << "Nhap so phuc b (thuc, ao): ";
    cin >> b;
    cout << "\n a = " << a;
    cout << "\n b = " << b;
    cout << "\n a + b = " << a + b;
    cout << "\n a - b = " << a - b;
    cout << "\n a * b = " << a * b;
    try {
        cout << "\n a / b = " << a / b << endl;
    }
    // Nếu mẫu khác 0 thì in ra a/b, mẫu bằng 0 in ra Loi
    catch (const char* msg) {
        cout << "\n " << msg << endl;
    }
    if (a == b) cout << " a = b" << endl;
    else cout << " a != b" << endl;
    return 0;
}
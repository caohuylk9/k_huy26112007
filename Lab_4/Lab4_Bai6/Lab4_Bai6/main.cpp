#include <iostream>
#include "CVector.h"
using namespace std;

int main()
{
    int n;

    cout << "Nhap so chieu vector: ";
    cin >> n;

    CVector v1(n), v2(n);
    // vector có n chiều

    cout << "Nhap v1:\n";
    cin >> v1;

    cout << "Nhap v2:\n";
    cin >> v2;

    cout << "\nv1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;

    return 0;
}
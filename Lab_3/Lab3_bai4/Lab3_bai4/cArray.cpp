#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <climits>  
using namespace std;

void cArray::Nhap()
{
    a.clear();
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    // Mảng gồm n phần tử

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        // Nhập từng phần tử
        a.push_back(temp);
    }
}

void cArray::TaoNgauNhien()
{
    a.clear(); 
    cout << "Nhap so phan tu: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int c = rand() % 2000 - 1000; // random số từ -1000  đến 999
        a.push_back(c);
    }
}

void cArray::Xuat()
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
        // Xuất lần lượt các phần tử dưới dạng a b c 
    }
    cout << endl;
}

int cArray::Dem(int x)
// x là phần tử cần đếm
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == x) count++;
    }
    return count;
}

bool cArray::KiemTraTangDan()
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1]) return false;
        // Chỉ cần 1 phần tử a[i+1] > a[i] lập tức trả về sai
    }
    return true;
}

int cArray::TimPhanTuLeNN()
{
    int minVal = INT_MAX;
    bool f = false;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 != 0)
            // chỉ xét phần tử lẻ
        {
            if (a[i] < minVal)
            {
                minVal = a[i];
                f = true;
            }
        }
    }

    if (!f) return 0;
    // Nếu không có giá trị nào lẻ -> return 0
    return minVal;
}

bool cArray::KiemTraSNT(int z)
{
    if (z < 2) return false;
    for (int i = 2; i * i <= z; i++)
    {
        if (z % i == 0) return false;
    }
    return true;
}

int cArray::TimSNTLN()
{
    int maxVal = INT_MIN;
    bool f = false;

    for (int i = 0; i < a.size(); i++)
    {
        if (KiemTraSNT(a[i]))
            //Kiểm tra từng số xem phải SNT không
        {
            if (a[i] > maxVal)
            {
                maxVal = a[i];
                f = true;
            }
        }
    }

    if (!f) return -1;
    // Nếu không tồn tại SNT -> return -1
    return maxVal;
}

void cArray::SapXepGiam()
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
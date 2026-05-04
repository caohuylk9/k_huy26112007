#include <iostream>
#include <windows.h>
#include "CTime.h"
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    CTime t(0, 0, 0);

    while (true)
    {
        system("cls");

        // góc trên bên phải (ví dụ 90, 0)
        gotoxy(90, 0);
        cout << t;

        t++; // tăng 1 giây

        Sleep(1000); // 1 giây
    }

    return 0;
}
// Đoạn này em lên chatgpt chứ em cũng không biết làm
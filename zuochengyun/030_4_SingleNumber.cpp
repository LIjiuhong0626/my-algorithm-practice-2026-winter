#include<iostream>
using namespace std;

int main()
{
    //找到唯一出现奇数次的数字
    int a[11] = {1, 1, 2, 3, 3, 4, 4, 4, 4, 6, 6}, eorAll = 0;
    for(int i = 0; i<11; i++)
    {
        eorAll ^= a[i];
    }
    cout << eorAll;
}
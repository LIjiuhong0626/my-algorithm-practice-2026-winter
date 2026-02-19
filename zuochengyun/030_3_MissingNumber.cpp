#include<iostream>
using namespace std;

int TheMising(int *a);
int main()
{
    int a[10] = {0, 1, 2, 3, 5, 6, 7, 8, 9, 10};
    cout << TheMising(a);
}

int TheMising(int *a)
{
    //a的长度是10， 在0-10中缺了一个
    int eorAll = 0, eorHas = 0; 
    //为什么初始时是0，因为0和任意数字异或就是这个数字本身
    for(int i = 0; i<10; i++)
    {
        eorAll ^= i;
        eorHas ^= a[i];
    }
    eorAll ^= 10;
    return eorAll ^ eorHas;
}
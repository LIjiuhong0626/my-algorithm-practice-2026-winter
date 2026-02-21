#include<iostream>
using namespace std;

int RangeBitwiseAnd(int l, int r);

int main()
{
    int l, r;
    cin >> l >> r;
    cout << RangeBitwiseAnd(l ,r);
}

//返回范围内所有数字&的结果
//0100 1010 0110 right
//0100 1010 0100
//0100 1010 0000
//               left
int RangeBitwiseAnd(int l, int r)
{
    while(r > l)
    {
        r -= (r & -r);
    }
    return r;
}
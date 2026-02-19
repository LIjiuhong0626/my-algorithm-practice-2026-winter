#include<iostream>
#include<bitset>
using namespace std;

void printBinary(int num)
{
    for(int i = 31; i >= 0; i--)
    {
        cout << (num & (1L << i)  ? 1 : 0);
        // 1.不能 == 1，因为不是1！！
        // 2.如果是long long 用1L，1默认是32位的
    }
    cout << '\n';
}
int main()
{
    printBinary(1209384);
    // int c = 0b1011111110000000111;
    // int d = 0x4e;
    // int a = ~c;
    // short x = -12900;
    // cout << c << endl;
    // cout << a << endl; 
    // cout << d << endl;
    // cout << x << endl;

    // cout << bitset<8>(4);
}


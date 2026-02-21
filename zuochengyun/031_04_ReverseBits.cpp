#include<iostream>
using namespace std;

int reverseBits(int n)
{
    n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;
    n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;
    n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
    n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
    n = n >> 16 | n << 16;
    return n;
}

void print_binery(int n)
{
    for(int i = 31; i >= 0; i--)
    {
        cout << (((n >> i) & 1) == 1 ? 1 : 0);
    }
}
int main()
{
    int n;
    cin >> n;
    cout << n << ' ';
    print_binery(n);
    cout << '\n';
    cout << reverseBits(n) << ' ';
    print_binery(reverseBits(n));
}
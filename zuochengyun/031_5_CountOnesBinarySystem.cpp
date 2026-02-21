#include<iostream>
using namespace std;

void print_binery(int n)
{
    for(int i = 31; i >= 0; i--)
    {
        cout << (((n >> i) & 1) == 1 ? 1 : 0);   
    }
    cout << '\n';
}
int CountOnesBinarySystem(int n);

int main()
{
    int n;
    cin >> n;
    print_binery(n);
    cout << CountOnesBinarySystem(n);

}

int CountOnesBinarySystem(int n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}
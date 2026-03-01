#include <iostream>
#include <cmath>
using namespace std;
int lcm(int a, int b);

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    int l = 1, r = n * min(a, b) + 1, m = 0;
    while(l + 1 != r)
    {
        m = l + (r - l) / 2;
        if(m / a + m / b - m / lcm(a, b) < n)
            l = m;
        else
            r = m;
    }
    cout << (int)r % 10000007;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
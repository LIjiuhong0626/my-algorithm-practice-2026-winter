#include <iostream>
using namespace std;

// （（a+b）*（c-d）＋（a*c-b＊d）% mod
long a, b, c, d, mod;
int main()
{

    int o1 = a % mod;         // a
    int o2 = b % mod;         // b
    int o3 = (o1 + o2) % mod; // a + b

    int o4 = c % mod;               // c
    int o5 = d % mod;               // d
    int o6 = (o4 - o5 + mod) % mod; // c - d

    int o7 = (int)(((long long)o1 * o4)) % mod; // a * c
    int o8 = (int)(((long long)o2 * o3)) % mod; // b * d
    int o9 = (o7 - o8 + mod) % mod;           // a*c-b＊d

    int o10 = (int)(((long long)(o3 * o6))) % mod;
    int o11 = (o10 + o9) % mod;

    cout << o11;
}
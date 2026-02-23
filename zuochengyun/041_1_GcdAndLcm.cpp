#include <iostream>
using namespace std;

//greatist common divisor
//不要求a比b大
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

//least common multiple
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << " " << lcm(a, b);
}


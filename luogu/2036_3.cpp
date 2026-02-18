#include<iostream>
#include<cmath>
using namespace std;

struct food
{
    int s, k;
}f[15];

long long minm = 100000;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i].s >> f[i].k;
    }

    long long cur_s = 1, cur_k = 0;
    int u = 1 << n;//全集

    for(int i = 1; i < u; i++)
    {   
        cur_s = 1, cur_k = 0;
        //检查第几位是1
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                cur_k += f[j].k;
                cur_s *= f[j].s;
            }
        }
        minm = min(minm, (long long)abs(cur_k - cur_s));
    }
    cout << minm;
}
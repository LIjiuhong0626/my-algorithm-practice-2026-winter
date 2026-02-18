#include <iostream>
#include <cmath>
using namespace std;

struct food
{
    int s, k;
} f[15];

int n, minm = 100000;
long long multiple_s = 1;
int sum_k = 0;

void dfs(int startindex, int multiple_s, int sum_k);

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i].s >> f[i].k;
    }

    dfs(0, 1, 0);
    cout << minm;
}

//全局变量就好用递归回溯，用栈呢
void dfs(int startindex, int multiple_s, int sum_k)
{
    if (abs(multiple_s - sum_k) < minm && startindex != 0)
        minm = abs(multiple_s - sum_k);

    //cout << minm << "\n";
    for (int i = startindex; i < n; i++)
    {
        // 不能这样，这样的话之后的循环里值就变了！！！！
        //multiple_s = multiple_s * f[i].s;
        //sum_k = sum_k + f[i].k;

        dfs(i + 1, multiple_s * f[i].s, sum_k + f[i].k);
    }
}
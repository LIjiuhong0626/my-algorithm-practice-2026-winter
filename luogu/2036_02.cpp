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

void dfs(int startindex);

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i].s >> f[i].k;
    }

    dfs(0);
    cout << minm;
}

//全局变量就好用递归回溯，如果不是全局变量呢？用栈呢？
void dfs(int startindex)
{
    if (abs(multiple_s - sum_k) < minm && startindex != 0)
        minm = abs(multiple_s - sum_k);

    //cout << minm << "\n";
    for (int i = startindex; i < n; i++)
    {
        multiple_s = multiple_s * f[i].s;
        sum_k = sum_k + f[i].k;

        dfs(i + 1);

        multiple_s = multiple_s / f[i].s;
        sum_k = sum_k - f[i].k;
    }
}

/*
// 只需要传递当前位置、当前酸度积、当前苦度积
void dfs(int startindex, long long cur_s, int cur_k) {
    // 只要不是什么都没选，就更新答案
    if (startindex > 0) { 
        minm = min(minm, (int)abs(cur_s - cur_k));
    }

    for (int i = startindex; i < n; i++) {
        // 直接在参数里计算，不改变本层的值
        dfs(i + 1, cur_s * f[i].s, cur_k + f[i].k);
    }
}
// 调用时：dfs(0, 1, 0);
*/
#include <iostream>
#include <cmath>
using namespace std;

int path[13];
int f1(int i, int *path, int n);
int f2(int limit, int col, int left, int right);
int main()
{
    int n, limit;
    cin >> n;
    limit = (1 << n) - 1;

    //cout << f1(0, path, n) << '\n';
    cout << f2(limit, 0, 0, 0);
}

int check(int *path, int i, int j) // 第i行是j
{
    for (int k = 0; k < i; k++)
    {
        if (abs(j - path[k]) == abs(i - k) || j == path[k]) // 检查对角线和列
            return 0;
    }
    return 1;
}

// i 当前行
// path 0到i-1行的皇后排在哪些列
// n 是几皇后问题
int f1(int i, int *path, int n)
{
    if (i == n)
        return 1; // 到了叶子， 答案加一

    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (check(path, i, j))
        {
            path[i] = j;
            ans += f1(i + 1, path, n);
        }
    }
    return ans;// 每一行的答案数量
}

// limit 几皇后问题 0000011111
// col， 之前放了之后哪些列可以放 1是放过的
// right， 同上
int f2(int limit, int col, int left, int right)
{
    if (col == limit)
        return 1;
    // 总限制
    int ban = col | left | right;
    // ~ban 1可以放， 0不可以放
    int candidate = limit & ~ban; // 一定要limit一下， 不然就会有很多的1
    //放皇后的尝试
    int place = 0;
    //一共多少种有效方法
    int ans = 0;
    while (candidate != 0)
    {
        // 取出最右侧的1
        place = candidate & (-candidate);
        candidate ^= place;
        ans += f2(limit, col | place, (left | place) >> 1, (right | place) << 1);
    }
    return ans;
}
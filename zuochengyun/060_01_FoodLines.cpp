// 最大食物链计数
// a -> b，代表a在食物链中被b捕食
// 给定一个有向无环图，返回
// 这个图中从最初级动物到最顶级捕食者的食物链有几条
// 测试链接 : https://www.luogu.com.cn/problem/P4017
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

// 利用topo过程传递信息

#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXN = 5010;   // 节点数
const int MAXM = 500010; // 连接数
const int MOD = 80112002;

int lines[MAXN]; // 信息传递

int ans = 0;

// 链式前向星
int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int cnt = 1;

// 入度表
int indegree[MAXN];

// 队列
int queuee[MAXN];
int l = 0, r = 0;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    // 建表
    for (int i = 0; i < m; i++)
    {
        // a -> b
        int a, b;
        scanf("%d%d", &a, &b);

        indegree[b]++;
        nxt[cnt] = head[a];
        to[cnt] = b;
        head[a] = cnt;
        cnt++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            lines[i] = 1;
            queuee[r++] = i;
        }
    }

    while (l < r)
    {
        int cur = queuee[l++];
        if(head[cur] == 0)
            ans = (ans + lines[cur]) % MOD;
        for (int ei = head[cur]; ei > 0; ei = nxt[ei]) // Edge Index
        {
            indegree[to[ei]]--;
            lines[to[ei]] = (lines[cur] + lines[to[ei]]) % MOD;

            if(indegree[to[ei]] == 0)
            {
                queuee[r++] = to[ei];
            }
        }
    }

    cout << ans; 
}
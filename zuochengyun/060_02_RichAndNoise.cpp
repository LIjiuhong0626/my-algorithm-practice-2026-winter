// 喧闹和富有
// 从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值
// 给你一个数组richer，其中richer[i] = [ai, bi] 表示
// person ai 比 person bi 更有钱
// 还有一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值
// richer 中所给出的数据 逻辑自洽
// 也就是说，在 person x 比 person y 更有钱的同时，不会出现
// person y 比 person x 更有钱的情况
// 现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是,
// 在所有拥有的钱肯定不少于 person x 的人中，
// person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
// 测试链接 : https://leetcode.cn/problems/loud-and-rich/

#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        int n = quiet.size();
        const int MAXM = 50010;

        int head[505] = {0};
        int nxt[MAXM];
        int to[MAXM];
        int cnt = 1;

        vector<int> indegree(n);

        int queue[n];
        int l = 0, r = 0;

        vector<int> lines(n);
        for(int i = 0; i < n; i++)
        {
            lines[i] = i;
        }

        for (int i = 0; i < richer.size(); i++)
        {
            // a -> b
            int a = richer[i][0], b = richer[i][1];
            indegree[b]++;

            nxt[cnt] = head[a];
            head[a] = cnt;
            to[cnt] = b;
            cnt++;
        }

        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                queue[r++] = i;
            }
        }

        while (l < r)
        {
            int cur = queue[l++];
            for (int ei = head[cur]; ei > 0; ei = nxt[ei])
            {
                if(quiet[lines[cur]] < quiet[lines[to[ei]]])// 比较在这一堆范围里， 最小的是谁, 因为本身的值也要包含进去， 所以默认值就是本身
                //lines里面存的一直是节点！！！
                {
                    lines[to[ei]] = lines[cur];// 是之前所有的最小
                }

                indegree[to[ei]]--;
                if(indegree[to[ei]] == 0)
                {
                    queue[r++] = to[ei];
                }
            }
        }
        return lines;
    }
};
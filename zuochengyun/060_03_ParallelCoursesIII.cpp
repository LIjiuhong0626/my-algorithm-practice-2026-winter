// 并行课程 III
// 给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n
// 同时给你一个二维整数数组 relations ，
// 其中 relations[j] = [prevCoursej, nextCoursej]
// 表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）
// 同时给你一个下标从 0 开始的整数数组 time
// 其中 time[i] 表示完成第 (i+1) 门课程需要花费的 月份 数。
// 请你根据以下规则算出完成所有课程所需要的 最少 月份数：
// 如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
// 你可以 同时 上 任意门课程 。请你返回完成所有课程所需要的 最少 月份数。
// 注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）
// 测试链接 : https://leetcode.cn/problems/parallel-courses-iii/

#include <iostream>
using namespace std;

// 注意是从1 开始
class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        //vector 一定要分配空间
        //从n+1开始， 因为time从1开始
        //从m+1开始， 因为cnt开始为1， 第一条边的编号为1
        //不如直接给一个定的大小
        int m = relations.size();
        vector<int> head(n + 1);
        vector<int> nxt(m + 1);
        vector<int> to(m + 1);
        int cnt = 1;

        //
        vector<int> indegree(n + 1);

        //
        vector<int> queue(n + 1);
        int l = 0, r = 0;

        //
        vector<int> ans(n + 1);

        for (int i = 0; i < m; i++)
        {
            int a = relations[i][0], b = relations[i][1];
            indegree[b]++;

            nxt[cnt] = head[a];
            head[a] = cnt;
            to[cnt] = b;
            cnt++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                queue[r++] = i;
                //ans[i] = time[i];// 节点我们在链式前向星里用的是0 - 1， 所以在这里也要将i - 1对应
            }
        }

        while (l < r)
        {
            int cur = queue[l++];
            ans[cur] = ans[cur] + time[cur - 1];//cur - 1!!!
            for (int ei = head[cur]; ei > 0; ei = nxt[ei])
            {
                ans[to[ei]] = max(ans[cur], ans[to[ei]]);// 注意先后顺序！！

                indegree[to[ei]]--;
                if (indegree[to[ei]] == 0)
                {
                    queue[r++] = to[ei];
                }
            }
        }
        int ret = 0;    
        for(int i = 1; i <= n; i++)
        {
            ret = max(ret, ans[i]);
        }
        return ret;
    }
};
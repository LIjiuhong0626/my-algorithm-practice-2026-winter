// 拓扑排序模版（Leetcode）
// 邻接表建图（动态方式）
// 课程表II
// 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1
// 给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi]
// 表示在选修课程 ai 前 必须 先选修 bi
// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1]
// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序
// 你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组
// 测试链接 : https://leetcode.cn/problems/course-schedule-ii/

#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 邻接表
        vector<vector<int>> graph(numCourses);

        // 入度表
        vector<int> indegree(numCourses);

        // 同时构建两个表
        for (int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> &edge = prerequisites[i];
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u);
            indegree[u]++;
        }

        // 数组实现队列
        vector<int> queue(numCourses);
        int l = 0, r = 0;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                queue[r++] = i;
            }
        }

        int cnt = 0;//看最后是不是所有节点都拿出来了， 所有节点数就是总的课程数
        while (l < r)
        {
            int cur = queue[l++]; // 把第一个拿出来， queue里的都是indegree为0的
            cnt++;

            for (int i = 0; i < graph[cur].size(); i++)
            {
                indegree[graph[cur][i]]--;
                if (indegree[graph[cur][i]] == 0)
                {
                    queue[r++] = graph[cur][i]; // 为什么只在这里加入queue呢，因为只有这里剪了
                }
            }
        }

        //为什么要返回queue， 因为我queue没有弹出， 且queue里的都是按照顺序 indegree为0的
        return cnt == numCourses ? queue : vector<int>();
    }
};
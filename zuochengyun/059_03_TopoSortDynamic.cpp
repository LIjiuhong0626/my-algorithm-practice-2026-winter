#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 链式前向星 和 入度图
        int m = prerequisites.size();
        int cnt = 0;
        vector<int> head(numCourses, -1);//为什么是-1呢， 因为这里有编号为0的边， 最后种植条件也是ei ！= -1
        vector<int> next(m);
        vector<int> to(m);
        vector<int> indegree(numCourses);

        
        for (int i = 0; i < m; i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            // v -> u
            indegree[u]++;

            next[cnt] = head[v];
            to[cnt] = u;
            head[v] = cnt; // head指向的是边的编号
            cnt++;
        }

        int num = 0;
        vector<int> queue(numCourses);
        int l = 0, r = 0;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                queue[r++] = i;
                num++;//两种计数方式 作用是防止有环， 导致有节点没加进去
            }
        }

        while (l < r)
        {
            int cur = queue[l++];
            // 查找cur对应的节点
            for(int ei = head[cur]; ei != -1; ei = next[ei]) // ei是边的编号
            //head 和next都是边的编号！！！
            {
                int to_node = to[ei];
                indegree[to_node]--;
                if(indegree[to_node] == 0)
                {
                    queue[r++] = to_node;
                    num++;
                }
            }
        }

        return (num == numCourses ? queue : vector<int>());
    }
};
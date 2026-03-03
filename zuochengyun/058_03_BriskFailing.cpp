// 打砖块
// 有一个 m * n 的二元网格 grid ，其中 1 表示砖块，0 表示空白
// 砖块 稳定（不会掉落）的前提是：
// 一块砖直接连接到网格的顶部，或者
// 至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
// 给你一个数组 hits ，这是需要依次消除砖块的位置
// 每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消失
// 然后其他的砖块可能因为这一消除操作而 掉落
// 一旦砖块掉落，它会 立即 从网格 grid 中消失（即，它不会落在其他稳定的砖块上）
// 返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。
// 注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。
// 测试链接 : https://leetcode.cn/problems/bricks-falling-when-hit/

#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        vector<int> ans(hits.size());
        int n = grid[0].size();
        int m = grid.size();
        for (int i = 0; i < hits.size(); i++)
        {
            grid[hits[i][0]][hits[i][1]]--; // 先把砖块扣掉
        }

        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
            {
                dfs(grid, m, n, 0, i); // 把所有稳固点都标记为 2
            }
        }

        for (int i = hits.size() - 1; i >= 0; i--)
        {
            int x = hits[i][0];
            int y = hits[i][1];
            grid[x][y]++; // 把打碎的点补上
            if (grid[x][y] == 1 && (x == 0 || (x > 0 && grid[x - 1][y] == 2) || (x < m - 1 && grid[x + 1][y] == 2) || (y > 0 && grid[x][y - 1] == 2) || (y < n - 1 && grid[x][y + 1] == 2)))
            { // 看看周围是不是有稳固点或者本身是不是稳固点，（它在第一行吗？或者它身边有值等于 2 的稳固砖块吗？）
                // 把该点补上相当于一个连接作用， 如果补上之后， 再把周围的1标记成 2， 看因此多了哪些点， 哪些点就是掉落的（触发连带效应：如果这块砖变稳了，它可能会带着下面一大串原本悬空的砖（值为 1）变稳。）
                int d = dfs(grid, m, n, x, y) - 1;
                ans[i] = d;
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>> &grid, int m, int n, int x, int y)
    {
        if (x < 0 || x == m || y < 0 || y == n || grid[x][y] != 1)//(grid[x][y] == 0 || grid[x][y] == 2) 有问题， 因为可能是-1
            return 0;
        grid[x][y] = 2;
        return 1 + dfs(grid, m, n, x - 1, y) + dfs(grid, m, n, x + 1, y) + dfs(grid, m, n, x, y - 1) + dfs(grid, m, n, x, y + 1);
    }
};
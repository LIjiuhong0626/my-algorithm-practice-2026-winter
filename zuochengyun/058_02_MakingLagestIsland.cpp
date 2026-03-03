#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int id = 1;

        int size[130005] = {0};
        bool visited[130005];// 去重
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    id++;
                    dfs(grid, m, n, id, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                size[grid[i][j]]++;
            }
        }
        size[0] = 0; // 为下面的代码做准备， 如果grid是0， 就加0
                           
        int up, down, left, right, merge = 0, ans = size[2]; // 记录周围grid对应的id
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    up = (i - 1 < 0 ? 0 : grid[i - 1][j]);
                    down = (i + 1 == m ? 0 : grid[i + 1][j]);
                    left = (j - 1 < 0 ? 0 : grid[i][j - 1]);
                    right = (j + 1 == n ? 0 : grid[i][j + 1]);

                    visited[up] = 1; // 先把上搞了，不管上是不是0， 接下来就是去重
                    merge = 1 + size[up];
                    if (visited[down] == 0)
                    {
                        merge += size[down];
                        visited[down] = 1;
                    }
                    if (visited[left] == 0)
                    {
                        merge += size[left];
                        visited[left] = 1;
                    }
                    if (visited[right] == 0)
                    {
                        merge += size[right];
                        visited[right] = 1;
                    }

                    ans = (ans > merge ? ans : merge);

                    visited[up] = false;
                    visited[down] = false;
                    visited[left] = false;
                    visited[right] = false;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &board, int m, int n, int id, int x, int y)
    {
        if (x < 0 || x == m || y < 0 || y == n || board[x][y] != 1)
            return;
        board[x][y] = id;
        dfs(board, m, n, id, x - 1, y);
        dfs(board, m, n, id, x + 1, y);
        dfs(board, m, n, id, x, y - 1);
        dfs(board, m, n, id, x, y + 1);
    }
};
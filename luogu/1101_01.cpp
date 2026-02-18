#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int record[110][110], n, dir[8][2] = {{1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {-1, 0}, {0, -1}}, cnt = 0;
char origin[110][110];

string base = "yizhong";
void dfs(int sx, int sy, int step, int d);
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> origin[i][j]; // 会读取换行！！
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dfs(i, j, 0, -1);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(record[i][j]) cout << origin[i][j];
            else cout << '*';
        }
        cout<<'\n';
    }
}

void dfs(int sx, int sy, int step, int d)
{
    if (origin[sx][sy] != base[step])
        return;

    if (sx < 0 || sx >= n || sy < 0 || sy >= n)
        return;

    if (step == 6)
    {
        for (int i = 0; i < 7; i++)
        {
            record[sx][sy] = 1;
            sx = sx - dir[d][0];
            sy = sy - dir[d][1];
        }
        return;
    }
    if (d == -1)
    {
        for (int i = 0; i < 8; i++)
        {
            int x, y;
            x = sx + dir[i][0];
            y = sy + dir[i][1];
            dfs(x, y, step + 1, i);
        }
    }
    else
    {
        int x, y;
        x = sx + dir[d][0];
        y = sy + dir[d][1];
        dfs(x, y, step + 1, d);
    }
}
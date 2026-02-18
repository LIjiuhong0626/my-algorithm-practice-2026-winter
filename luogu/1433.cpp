#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

struct point
{
    double x, y;
}p[20];

bool used[20];
int n, count;
double dist_matrix[20][20];//预处理
double cur = 0, mmin = 1e10;
double dis(point p1, point p2);
void dfs(int last, int count);
int main()
{
    p[0]={0, 0};
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        double x, y;
        scanf("%lf%lf", &x, &y);
        p[i] = {x, y};
    }
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=n ;j++)
        {
            dist_matrix[i][j] = dis(p[i], p[j]);
        }
    }
    dfs(0, 0);

    printf("%0.2lf", mmin);
}

double dis(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void dfs(int last, int count)
{
    if(cur >= mmin) return;
    if(count == n)//猜的
    {
        mmin = cur;
        return;
    }

    for(int i = 1; i<=n; i++)
    {
        if(used[i]) continue;
        used[i] = 1;
        cur += dist_matrix[i][last];

        dfs(i, count + 1);

        used[i] = 0;
        cur -= dist_matrix[i][last];
    }
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, weight[5050], value[5050], dp[5050][5050], max_weight;
int main()
{
    scanf("%d%d", &n, &max_weight);
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);

    // init
    for (int i = 0; i <= max_weight; i++)
    {
        if (i < weight[0])
            dp[0][i] = 0;
        else
            dp[0][i] = value[0];
    }
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    //
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= max_weight; j++)
        {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n - 1][max_weight];
}
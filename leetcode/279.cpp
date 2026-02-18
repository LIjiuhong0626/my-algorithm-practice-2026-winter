#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int s[150];
    for(int i = 1; i<=149; i++)
    {
        s[i] = i * i;
    }

    int target, dp[2000]; cin >> target;
    
    dp[0] = 0;
    for(int i = 1; i<=target; i++)
    {
        dp[i] = INT_MAX;
    }
    
    for(int i = 1; i <= 149; i++)
    {
        for(int j = 0; j <= target; j++)
        {
            if(j - s[i] >= 0)
            dp[j] = min(dp[j], dp[j-s[i]] + 1);
        }
    }

    cout << dp[target];
}
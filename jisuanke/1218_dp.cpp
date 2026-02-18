#include <iostream>
using namespace std;

int a[25], n, target, dp[25][1010];
int main()
{
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // init
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    for (int i = 0 ;i <= target; i++)
        dp[0][i] = (i >= a[0] ? a[0] : 0);
    
    //
    for(int i = 1; i < n ;i++)
    {
        for(int j = 1; j < target; j++)
        {
            
        }
    }
}
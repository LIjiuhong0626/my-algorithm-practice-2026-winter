#include <iostream>
#include <algorithm>
using namespace std;

int n, max_space, value[5010], space[5010], dp[5010];
int main()
{
    cin >> n >> max_space;
    for (int i = 0; i < n; i++)
        cin >> space[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];

    // subject = 0
    //不用这个，下面会自动执行的，因为逻辑都是一样的
    for (int i = 0; i <= max_space; i++)
        if (i < space[0])
            dp[i] = 0;
        else
            dp[i] = value[0];

    //
    for (int i = 1; i < n; i++)
        for (int j = max_space; j > 0; j--)
        {
            if(j >= space[i])
                dp[j] = max(dp[j], dp[j - space[i]] + value[i]);
        }
    
    cout << dp[max_space];
}
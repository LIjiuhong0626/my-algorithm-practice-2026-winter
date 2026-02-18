#include <iostream>
#include <algorithm>
using namespace std;

int num_size, a[210], dp[210], sum = 0, target = 0;
int main()
{
    cin >> num_size;
    for (int i = 0; i < num_size; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    target = sum / 2;

    for (int i = 0; i < num_size; i++)
    {
        for (int j = target; j >= 0; j--)
        {
            if(j >= a[i])
            {
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            }
        }
    }
    cout << ((target == dp[target]) ? "true" : "false");
}
#include <iostream>
using namespace std;

int a[21];
int n, target, ans = 0;
void dfs(int startindex, int sum);

int main()
{
    cin >> n >> target;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dfs(0, 0);
    cout << ans;
    return 0;
}

void dfs(int startindex, int sum)
{
    if(sum == target) 
    {
        ans++;
        return;
    }
    if(startindex > n) return;
    
    for(int i = startindex; i < n; i++)
    {
        sum += a[i];
        dfs(i + 1, sum);
        sum -= a[i];
    }
}
#include<iostream>
#include<vector>
using namespace std;

int n, used[10];
vector<int> cur;
void dfs();
int main()
{
    cin >> n;
    dfs();
}

void dfs()
{
    if(cur.size() == n)
    {
        for(int i = 0; i<n; i++)
        {
            cout << cur[i];
        }
        cout<<'\n';
    }
    for(int i = 1; i<=n; i++)
    {
        if(used[i]) continue;
        used[i] = 1;
        cur.push_back(i);

        dfs();

        used[i] = 0;
        cur.pop_back();
    }
}
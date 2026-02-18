#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> cur;
void dfs(int startindex);
int main()
{
    cin >> n;
    dfs(1);
}

void dfs(int startindex)
{
    for(int i = 0; i < cur.size(); i++)
    {
        cout << cur[i];
    }
    cout << "\n";

    for(int i = startindex; i <= n; i++)
    {
        cur.push_back(i);
        dfs(i + 1);
        cur.pop_back();
    }
}
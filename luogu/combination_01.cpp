#include <iostream>
#include <vector>
using namespace std;

int n;

void dfs(int startindex, vector<int> cur);
int main()
{
    cin >> n;
    vector<int> cur;
    dfs(1, cur);
}

//局部树 , 但是是传的值，每次都要复制， 性能不好；
void dfs(int startindex, vector<int> cur)
{
    //cur.push_back(startindex);
    for (int i = 0; i < cur.size(); i++)
    {
        //if(cur[i] == 0) continue;
        cout << cur[i];
    }
    cout << "\n";

    for (int i = startindex; i <= n; i++)
    {
        //如果要用应该这样用
        //dfs(i + 1, cur.push_back(startindex));
        vector<int> t = cur;
        t.push_back(i);
        dfs(i + 1, t);
    }
}
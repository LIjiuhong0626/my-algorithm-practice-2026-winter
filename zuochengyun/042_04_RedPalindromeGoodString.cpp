#include <iostream>
#include <string>
using namespace std;

char red[3] = {'r', 'e', 'd'};
string cur;
int n;
int f(int index);
int main()
{
    for (int i = 0; i < 10; i++)
    {
        n = i;
        cout << i << " : " << f(0) << "\n";
    }
}

bool is(string s, int l, int r)
{
    while (l < r) // 小于就行
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int f(int index)
{
    if (index == n)// 到达叶子
    {
        int cnt = 0;
        for (int l = 0; l < n; l++)
        {
            for (int r = l + 1; r < n; r++)
            {
                if (is(cur, l, r))
                {
                    cnt++;
                }
                if (cnt > 1)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        int ans = 0;//用 ans， 因为这里我开始了分支， 结果就是每个分枝结果汇总， 而每片叶子根据
                    //有效和无效又返回0或者1
        for (int i = 0; i < 3; i++)
        {
            cur.push_back(red[i]);
            ans += f(index + 1);
            cur.pop_back();
        }
        return ans;
    }
}
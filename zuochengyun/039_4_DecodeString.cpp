#include<iostream>
#include<string>
using namespace std;

string f(int i);
string s;

int where;// 每次运行完f， 都要更新where， 确保上一个f知道现在在哪里了
int main()
{
    cin >> s;
    cout << f(0);
}

string f(int i)
{
    string ans = "";
    int cur = 0;
    for(;i < s.size() && s[i] != ']'; i++)// 用for i直接++， 跳出循环的情况，有两个
    {
        if(s[i] >= '1' && s[i] <= '9')
        {
            cur = cur * 10 + s[i] - '0';
        }
        else if (s[i] == '[')
        {
            //string t = "";
            string tmp = f(i + 1);//解构里面的
            // while(cur--)//这样不好， cur会变成-1！！
            // {
            //     t += tmp;
            // }
            while(cur > 0)
            {
                ans += tmp;
                cur--;
            }//这样清楚一些
            //ans += t;
            i = where;// 关键
            cur = 0; //确保万无一失
        }
        else{//字母情况
            ans += s[i];
        }
    }
    where = i;// 关键
    return ans;
}
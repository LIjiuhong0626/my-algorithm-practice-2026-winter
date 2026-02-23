#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> numbers;
stack<char> opts;
string s;
int f1();

int main()
{
    cin >> s;
    f1();
    while (!numbers.empty())
    {
        cout << numbers.top() << "\n";
        numbers.pop();
    }
    while (!opts.empty())
    {
        cout << opts.top() << "\n";
        opts.pop();
    }
}

int f1()
{
    int cur = 0;
    for (int i = 0;; i++)
    {
        if (s[i] >= '0' && s[i] <= '9' && i < s.size())
        {
            int num = s[i] - '0';
            cur = cur * 10 + num;
        }
        else if (i == s.size())
        {
            numbers.push(cur);//??不得行
        }
        else // 遇到下一个符号
        {
            numbers.push(cur);
            if (!opts.empty())
            {
                if (opts.top() == '/')
                {
                    int t = numbers.top();
                    numbers.pop();
                    opts.pop();
                    cur = t / cur;
                    numbers.push(cur);
                }
                else if (opts.top() == '*')
                {
                    int t = numbers.top();
                    numbers.pop();
                    opts.pop();
                    cur = numbers.top() * cur;
                    numbers.push(cur);
                }
            }
            opts.push(s[i]);
        }
    }
}
// 逻辑有点混乱，应该搞清楚什么时候结算
/*
int f1()
{
    int cur = 0;
    // 存入栈中
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int num = s[i] - '0';
            cur = cur * 10 + num;
            if(i == s.size() - 1)
            {
                numbers.push(cur);
            }
        }
        else
        {
            // numbers.push(cur);

            // 3
            // 5 *
            if (!opts.empty() && opts.top() == '/')
            {
                cur = numbers.top() / cur;
                numbers.push(cur);
            }
            else if (!opts.empty() && opts.top() == '*')
            {
                cur = numbers.top() * cur;
                numbers.push(cur);
            }
            else
            {
                numbers.push(cur);
                opts.push(s[i]);
            }
            cur = 0;
        }
    }
}
*/

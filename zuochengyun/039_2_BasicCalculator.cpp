#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 没有括号版本
void push(stack<int> &numbers, stack<char> &opts, int cur, char o);
int computer(stack<int> &numbers, stack<char> &opts);
int f();

string s;
int main()
{
    cin >> s;
    cout << f();
}

int f()
{
    int cur = 0;
    stack<int> numbers;
    stack<char> opts;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            cur = cur * 10 + (s[i] - '0');
        }
        else
        {
            push(numbers, opts, cur, s[i]);
            cur = 0;
        }
    }
    push(numbers, opts, cur, '+');

    return computer(numbers, opts);
}

void push(stack<int> &numbers, stack<char> &opts, int cur, char o)
{
    if (opts.empty() || opts.top() == '+' || opts.top() == '-')
    {
        numbers.push(cur);
        opts.push(o);
    }
    else
    {
        if (opts.top() == '*')
        {
            cur = numbers.top() * cur;
        }
        else
        {
            cur = numbers.top() / cur;
        }
        numbers.pop();
        numbers.push(cur);
        opts.pop();
        opts.push(o);
    }
}

int computer(stack<int> &numbers, stack<char> &opts)
{
    opts.pop();
    int ans = 0;
    while (!opts.empty())
    {
        ans += (opts.top() == '+' ? numbers.top() : -numbers.top());
        numbers.pop();
        opts.pop();
    }
    ans += numbers.top();
    return ans;
}
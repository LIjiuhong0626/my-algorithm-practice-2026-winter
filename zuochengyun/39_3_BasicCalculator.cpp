#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 有括号版本
void push(stack<int> &numbers, stack<char> &opts, int cur, char o);
int compute(stack<int> &numbers, stack<char> &opts);
int where = 0;
int f(int i);

string s;
int main()
{
    cin >> s;
    cout << f(0);
}

int f(int i)
{
    //开头是-也没问题，因为cur默认是0，而push可以做到把0和下一个符号压入
    int cur = 0;
    stack<int> numbers;
    stack<char> opts;
    for (; i < s.size() && s[i] != ')'; i++)
    {
        if (s[i] == '(')
        {
            cur = f(i + 1);
            i = where; // where是')'的位置,注意这里是where，不用加一，因为下一次就要加1
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            cur = cur * 10 + (s[i] - '0');
        }
        else
        {
            // s[i]是 + - * /
            push(numbers, opts, cur, s[i]);
            cur = 0;
        }
    }
    //遇见结尾或者）， 要把这个数字要进去并且为了满足哦push的格式， 加入+号
    push(numbers, opts, cur, '+');
    where = i;
    return compute(numbers, opts);
}

//压入数字和符号
void push(stack<int> &numbers, stack<char> &opts, int cur, char o)
{
    //如果是空或者之前是+或者-， 直接压
    if (opts.empty() || opts.top() == '+' || opts.top() == '-')
    {
        numbers.push(cur);
        opts.push(o);
    }
    else
    {
        //如果是*或者/， 就要先算了来
        if (opts.top() == '*')
        {
            cur = numbers.top() * cur;
        }
        else
        {
            cur = numbers.top() / cur;
        }
        //弹出之前的， 加入新的
        numbers.pop();
        numbers.push(cur);
        opts.pop();
        opts.push(o);
    }
}

//运算完整的栈
int compute(stack<int> &numbers, stack<char> &opts)
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
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

stack<int> st;
int deep(stack<int> &st);
int mmax(stack<int> &st, int deep);
int times(stack<int> &st, int deep, int max);
void down(stack<int> &st, int deep, int max, int k);
void SortStackWithRecursive(stack<int> &st);
int main()
{
    //cout << (int)0x80000000 << endl;
    //cout << 0x80000000 << endl; // 默认看成无符号数，即2^31 1000 0000 ...
                                // if 有符号 就是-（2^32 / 2）
    st.push(1);
    st.push(9);
    st.push(6);
    st.push(9);
    st.push(5);
    //cout << times(st, 3, 9) << endl;
    //cout << deep(st) << '\n';
    //cout << mmax(st, 3);
    SortStackWithRecursive(st);
    int len = deep(st);
    for(int i = 0; i < len; i++)
    {
        cout << st.top() <<"\n";
        st.pop();
    }
}
// 总结，以下的递归都是先把st弹出来一个，然后对这个st进行操作，最后又还原，
// 其实本质和之前的permutation的seap回溯是一样的
// 计算栈的深度
int deep(stack<int> &st)
{
    if (st.empty())
        return 0;
    int num = st.top();
    st.pop();

    int len = deep(st) + 1;
    // 恢复栈
    st.push(num);
    return len;
}

// 返回指定深度内的最大值
int mmax(stack<int> &st, int deep)
{
    if (deep == 1)
        return st.top();
    // or if(deep == 0) return 0x80000000;

    int num = st.top();
    st.pop();
    int TheMax = max(num, mmax(st, deep - 1)); // restMmax将该数和之前的最大值进行比较
    st.push(num);                              // 恢复
    return TheMax;
}

// 从栈当前的顶部开始，往下数deep层，已知最大值是max了
// 返回，max出现了几次，不改变栈的数据状况
int times(stack<int> &st, int deep, int max)
{
    if (deep == 0)
        return 0;
    int num = st.top();
    st.pop();

    int ans = ((num == max ? 1 : 0) + times(st, deep - 1, max)); // restTimes
    st.push(num);
    return ans;
}

// 从栈当前的顶部开始，往下数deep层，已知最大值是max，出现了k次
// 请把这k个最大值沉底，剩下的数据状况不变
void down(stack<int> &st, int deep, int max, int k)
{
    if (deep == 0)
    {
        while (k--)
            st.push(max);
        return;
    }
    int num = st.top();
    st.pop();

    down(st, deep - 1, max, k);
    if (num != max)
        st.push(num);
}

void SortStackWithRecursive(stack<int> &st)
{
    int depth = deep(st);
    while (depth > 0)
    {
        int max = mmax(st, depth);
        int k = times(st, depth, max);
        down(st, depth, max, k);
        depth -= k;
    }
}
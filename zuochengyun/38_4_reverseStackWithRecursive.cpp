#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int BottomOut(stack<int> &st);
int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << BottomOut(st) << '\n';
    cout << st.top();
}

// 栈底元素移除掉，上面的元素盖下来
// 返回移除掉的栈底元素
void reverse(stack<int> &st)
{
    if (st.empty())
        return;
    int num = BottomOut(st);
    reverse(st);
    st.push(num);
}
int BottomOut(stack<int> &st)
{
    int ans = st.top();
    st.pop();
    if (st.empty())
    {
        return ans;
    }
    else
    {
        int last = BottomOut(st);
        st.push(ans);
        return last;
    }
}
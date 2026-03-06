// 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
// 给定一个可能含有重复值的数组 arr
// 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
// 返回所有位置相应的信息。
// 输入描述：
// 第一行输入一个数字 n，表示数组 arr 的长度。
// 以下一行输入 n 个数字，表示数组的值
// 输出描述：
// 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
// 测试链接 : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

#include <iostream>
using namespace std;

#define MAX 1000010
int arr[MAX];
int ans[MAX][2];
int Mystack[MAX];
int r = 0, n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cur;
    // 遍历阶段
    for (int i = 0; i < n; i++)
    {
        // i -> arr[i]
        while (r != 0 && arr[i] <= arr[Mystack[r - 1]]) // r 指向的是当前栈顶元素之上！因为r最开始是0， 相当于就是底部的上面
        {
            cur = Mystack[--r]; // stack里面放的是下标
            ans[cur][0] = (r > 0 ? Mystack[r - 1] : -1);
            ans[cur][1] = i;
        }
        Mystack[r++] = i; // 为什么要r++呢， 因为r指向的是栈顶之上
    }

    // 清算阶段
    while (r != 0)
    {
        cur = Mystack[--r];
        ans[cur][0] = (r > 0 ? Mystack[r - 1] : -1);
        ans[cur][1] = -1; // 为什么是-1， 只要最后还没有离开栈的都是-1
    }

    // 修正阶段
    // 左侧的答案不需要修正一定是正确的，只有右侧答案需要修正
    // 从右往左修正，n-1位置的右侧答案一定是-1，不需要修正
    for(int i = n - 2; i > 0; i--)
    {
        if(arr[ans[i][1]] == arr[i])// ans对应是下标， i对应是下标
        {
            ans[i][1] = ans[ans[i][1]][1];// eg. 下标9 对应 的答案是11， 下标11 对应的答案又是多少
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    }
}
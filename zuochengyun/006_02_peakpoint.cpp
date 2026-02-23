/*
方法总结：
红蓝数组法
while(l + 1 != r)
{
    m = (l + r) / 2;
    if(isblue(m))
        l = m;
    else
        r = m;
}
    return l or r;
用ans记录法，eg求>=5的第一个数字，满足条件：记录答案往左二分。不满足条件：记录答案往右二分
ans = -1;
while(l <= r)
{
    m = l + (r - l) >> 1;
    if(is())
        r = m - 1;
        ans = m;//因为要尽量找到左边的答案，所以要往左二分
    else
        l = m + 1;
}
        return ans;
二分总结
一定要有序吗，某侧必有or某侧必没有，就足以二分了

峰值元素是指其值严格大于左右相邻值的元素。
给你一个整数数组 nums，找到峰值元素并返回其索引。
数组可能包含多个峰值，在这种情况下，返回 任何一个峰值所在位置即可。
你可以假设 nums[-1] = nums[n] = -∞

eg.无序，但是利用罗尔定理，足以判断一侧是不是有极值点*/

#include <iostream>
using namespace std;

int a[10] = {1, 2, 3, 4, 5, 3, 6, 1, 2, 1};
int is_peak();
int main()
{
    cout<<is_peak();
}

int is_peak()
{
    int len = sizeof(a) / sizeof(a[0]);
    if (len == 1)
        return -1;
    if (a[0] > a[1])
        return 0;
    else if (a[len - 1] > a[len - 2])
        return len - 1;

    int l = 0, r = len - 1, ans = -1, m = 1;
    while (l <= r)
    {
        m = l + ((r - l) >> 1);
        if (a[m - 1] > a[m])
            r = m - 1;
        else if (a[m + 1] > a[m])
            l = m + 1;
        else//是峰值点
        {
            ans = m;
            break;
        }
    }
    return ans;
}
#include <iostream>
using namespace std;

int a[10] = {1, 2, 3, 6, 6, 6, 8, 9, 10, 13};
//           b  b  b  l  l  l  l  l   l   l
//isblue 是 < 6
//找到第一个大于6的元素位置
bool isblue(int m);
int main()
{
}

bool isblue(int m)
{
    return 1;
}

int find_left(int target)
{
    int left = 0, right = 9, m = 0;
    while (left + 1 != right)//用蓝红边界好搞一些！！！，这就需要用这个判定条件而不是。。。
    {
        m = left + ((right - left) >> 1);// 如果是left + right 可能溢出;
        if(isblue(m))
            left = m;
        else
            right = m;
    }
    return right;//or left 如果是找到最后一个小于的，就是返回left
}
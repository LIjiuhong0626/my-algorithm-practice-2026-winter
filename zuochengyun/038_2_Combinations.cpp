#include <iostream>
using namespace std;

string s;
char path[100];
void f(int i, int size);

int main()
{
    cin >> s;
    f(0, 0);
}

//[1, 1, 1, 1, 2, 2, 2, 3, 3, 4]
void f(int i, int size)
{
    if (i == s.size())
    {
        for (int k = 0; k < size; k++)
            cout << path[k];
        cout << '\n';
        return;
    }
    //找到下一个不一样的数在哪里
    int j = i + 1;
    while (j < s.size() && s[i] == s[j])
        j++;

    //选择0个1
    f(j, size);//和38_1完全对应， j 至少等于 i + 1

    //选择剩下的
    for (; i < j; i++)
    {
        path[size] = s[i];
        size++;
        //为什么不是在f里面size+1， 因为for循环要求在下一次循环中继承这个size

        f(j, size);
    }
}
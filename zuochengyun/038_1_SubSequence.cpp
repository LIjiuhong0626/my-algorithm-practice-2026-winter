#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string path1 = "", s;
char path2[100];
unordered_set<string> set;
void f1(int i);
void f2(int i, int size);

int main()
{
    cin >> s;
    f2(0, 0);
}

// 没去重版本
void f1(int i)
{
    if (i == s.size())
    {
        set.insert(path1);
        cout << path1 << '\n';
        return;
    }

    path1.push_back(s[i]);
    f1(i + 1);

    path1.pop_back();
    f1(i + 1);
}

void f2(int i, int size)
{
    if (i == s.size())
    {
        for (int k = 0; k < size; k++)
            cout << path2[k];
        cout << '\n';
        return;
    }

    path2[size] = s[i];
    f2(i + 1, size + 1);
    //你把字符填入当前位置，然后告诉下一层：“我已经占了 size 这个坑，你从 size + 1 开始填。”

    f2(i + 1, size);
    //你不移动指针。下一层递归如果选择“要”字符，会直接覆盖掉当前 path2[size] 的值。

    /*
    和38_2对应，是其简化版本
    选择0个
    f2(i + 1, size);

    选择1个
    path2[size] = s[i];
    f2(i + 1, size + 1);
    */
}
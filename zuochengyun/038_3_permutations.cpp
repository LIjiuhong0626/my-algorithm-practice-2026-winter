#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string s;
void f(int i);
int main()
{
    cin >> s;
    f(0);
}

void swap(int a, int b)
{
    char t = s[a];
    s[a] = s[b];
    s[b] = t;
}

void f(int i)// i是从0开始，一个个看s的每一个位置
{
    if(i == s.size())
    {
        cout << s <<"\n";
        return;
    }
    unordered_set<char> set;
    
    for(int j = i; j < s.size(); j++)
    {
        //同一个位置，同样的字母，每个只能选一次，这样就可以去重
        //其本质就是多个同样的字符占据一个位置，而之后的回溯一样，导致重复
        if(set.find(s[j]) != set.end()) continue;
        set.insert(s[j]);
        //if(s[i] == s[j] && j!=i ) continue; 不行

        swap(i, j);
        f(i + 1);
        swap(i, j);
    }
}


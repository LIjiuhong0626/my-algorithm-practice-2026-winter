#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string path = "", s;
void f1(int i);
int main()
{
    cin >> s;
    f1(0);
}

void f1(int i)
{
    if(i == s.size())
    {
        cout << path << '\n';
        return;
    }

    path.push_back(s[i]);
    f1(i + 1);

    path.pop_back();
    f1(i + 1);
}
#include<iostream>
using namespace std;
char win1(int n);

// 草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64.••
// 谁在自己的回合正好把草吃完谁赢，根据输入的n，返回谁赢
int main()
{
    for(int i = 0; i < 70; i++)
    {
        cout<<i << " : " << win1(i) <<"\n";
    }
}

// rest 剩余草
// cur 当前选手名字
char f(int rest, char cur)
{   
    char enemy = (cur == 'A' ? 'B' : 'A');
    if(rest < 5)
    return (rest == 0 || rest == 2) ? enemy : cur;

    // 我选1份草， 剩下的给敌人， 看我赢不赢
    //    4
    //    16
    int pick = 1;
    while(pick < rest)
    {
        if(f(rest - pick, enemy) == cur)
            return cur;
        pick *= 4;
    }
    return enemy;
}

char win1(int n)
{
    return f(n, 'A');
}
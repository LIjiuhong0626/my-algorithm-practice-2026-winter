// 找规律的题
#include <iostream>
#include <cmath>
using namespace std;

const int INF = 1000000;
void bags1(int apple);
int main()
{
    for(int i = 1; i < 100; i++)
    {
        bags1(i);
    }
    return 0;
}

// 当前还有rest个苹果，使用的每个袋子必须装满，返回至少几个袋子；

int f(int rest)
{
    if (rest < 0)
        return INF;
    if (rest == 0)
        return 0;

    // 使用8规格， 剩余袋子要几个
    int p1 = f(rest - 8);
    int p2 = f(rest - 6);

    // 无效维持无效， 有效方可加1
    p1 += (p1 != INF ? 1 : 0);
    p2 += (p2 != INF ? 1 : 0);
    return min(p1, p2);
    /*
    // 逻辑：如果两种方案都返回 INF，说明都走不通
    if (p1 == INF && p2 == INF)
        return INF;

    // 如果其中一个走得通，选小的（注意排除 INF）
    if (p1 == INF)
        return p2 + 1;
    if (p2 == INF)
        return p1 + 1;
    return min(p1, p2) + 1;
    */
}

void bags1(int apple)
{
    int ans = f(apple);
    cout << apple <<" : " << (ans == INF ? 1000000 : ans) <<"\n";
}
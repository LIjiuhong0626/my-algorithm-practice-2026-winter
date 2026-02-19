#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {1, 1, 2, 3, 3, 4, 4, 4, 4, 6, 7, 7, 7, 7};
    // 假设唯二出现奇数次的数字是x, y
    int eor1 = 0, eor2 = 0;
    for (int i = 0; i < a.size(); i++)
        eor1 ^= a[i];
    // eor1 = x ^ y

    // 提取出二进制最右侧的一个1
    int rightOne = eor1 & (-eor1);

    for (int i = 0; i < a.size(); i++)
    {
        //rightOne 0000 0100
        //a[i]     1100 0010
        //         0000 0000

        if ((a[i] & rightOne) == 0)//第一个1的状态不一样
            eor2 ^= a[i];
    }
    cout << (eor1 ^ eor2)<< " " << eor2;
}

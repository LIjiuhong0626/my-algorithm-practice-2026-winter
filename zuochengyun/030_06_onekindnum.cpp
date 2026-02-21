#include<iostream>
#include<vector>
using namespace std;

int cnt[32];
int main()
{
    vector<int> a = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    for(int i = 0; i<a.size(); i++)
    {
        for(int j = 0; j<32; j++)
        {
            if((a[i] & (1 << j)) != 0) cnt[j]++;//判断第几位是1
            //cnt[i] += (num >> j & 1) ->只能是0或者1
        }
    }

    //构造ans，怎么把某一位赋成1
    //0000 0000
    // ｜
    //0000 0001

    //0000 0001
    int ans = 0;
    for(int i =0 ;i<32; i++)
    {
        if(cnt[i] % 2 != 0)
        {
            //将第i位构造成1
            ans = ans | (1 << i);
        }
    }
    cout << ans;
}
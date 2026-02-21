#include <iostream>
using namespace std;

//一个数是不是2的幂， 看最右侧的1是不是和这个数一样， 因为这个数应该只有一个1
int main()
{
    int a;
    cin >> a;
    cout << ((a & (-a)) == a);
}
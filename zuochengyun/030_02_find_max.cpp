#include<iostream>
using namespace std;

int sign(int a);
int flip(int a);
int find_max(int a, int b);

int main()
{
    cout << find_max(1000000, 900091) << endl;
    cout << sign(-19);
}

int flip(int a)
{
    return 1 ^ a;
}

int sign(int a)//同号返回1， 异号返回0
{
    return flip(((a >> 31) & 1));
}

int find_max(int a, int b)
{
    int c = a - b;
    int sa = sign(a), sb = sign(b), sc = sign(c);
    int diffAB = sa ^ sb;// a b 同号为0
    int sameAB = flip(diffAB);// a b同好为1  //两个为互斥

    int returnA = diffAB * sa + sameAB * sc;
    // a b 同号，返回c的符号， a b 异号，返回a的符号
    int returnB = flip(returnA);

    return a * returnA + b * returnB;
}
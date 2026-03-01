#include<iostream>
using namespace std;
bool is(int n);

int main()
{
    for(int i = 1; i <= 50; i++)
    {
        cout << i <<" : "<< (is(i) == true ? "T" : "F") <<"\n";
    }
}

bool is(int n)
{
    for(int i = 1; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += j;
            if(sum > n) break;
            if(sum == n) return true;
        }
    }
    return false;
}
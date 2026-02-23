#include <iostream>
#include <string>
using namespace std;

void hanoi(int i, string from, string to, string other);
int main()
{
    hanoi(4, "左", "中", "右");
}

void hanoi(int i, string from, string to, string other)
{
    if (i == 1)
    {
        cout << "1" << " from " << from << " to " << to << "\n";
        return;
    }
    hanoi(i - 1, from, other, to);
    cout << i << " from " << from << " to " << to << "\n";
    hanoi(i - 1, other, to, from);
}
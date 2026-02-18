#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int k[210], ans[210], a, b, n;
queue<int> Q;
int main()
{
    memset(ans, -1, sizeof(ans));
    cin >> n >> a >> b;
    if (a == b)
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    Q.push(a);
    ans[a] = 0;

    while (!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        int up = tmp + k[tmp], down = tmp - k[tmp];

        if (up <= n && ans[up] == -1)
        {
            Q.push(up);
            ans[up] = ans[tmp] + 1;
            if (up == b)
            {
                cout << ans[up];
                return 0;
            }
        }

        if (down >= 1 && ans[down] == -1)
        {
            Q.push(down);
            ans[down] = ans[tmp] + 1;
            if (down == b)
            {
                cout << ans[down];
                return 0;
            }
        }
    }
    cout << -1;
}
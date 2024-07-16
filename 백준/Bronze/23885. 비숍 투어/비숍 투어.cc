#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int sy, sx, dy, dx;
void input()
{
    cin >> N >> M;
    cin >> sy >> sx >> dy >> dx;
}
void solve()
{
    int diffy = sy - dy;
    int diffx = sx - dx;
    if ((diffy + diffx) % 2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        input();
        solve();
    }
    return 0;
}
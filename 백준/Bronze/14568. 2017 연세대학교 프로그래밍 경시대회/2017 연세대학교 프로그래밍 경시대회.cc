#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
void input()
{
    cin >> N;
}
void solve()
{
    // 택 영 남
    // 남규가 영훈이보다 2개 이상 더 많이
    // 0개는 안됨
    // 택희는 짝수
    // 최소 : 2 1 3
    int ans = 0;
    int c;
    if (N < 6)
    {
        cout << "0\n";
        return;
    }
    for (int a = 2; a <= N; a += 2)
    {
        for (int b = 1; b <= N; b++)
        {
            c = N - a - b;
            if (c < 1 || b + 2 > c)
            {
                continue;
            }
            ans++;
        }
    }
    cout << ans << '\n';
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
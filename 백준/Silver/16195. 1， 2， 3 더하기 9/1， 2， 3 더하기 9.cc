#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int dp[1001][1001]; //[나타낸 수][사용한 수 개수]
void init()
{
    dp[1][1] = 1;
    dp[2][1] = 1; // 2 , 1 1
    dp[2][2] = 1; // 2 , 1 1
    dp[3][1] = 1; // 3 , 1 2 , 2 1, 111
    dp[3][2] = 2; // 3 , 1 2 , 2 1, 111
    dp[3][3] = 1; // 3 , 1 2 , 2 1, 111
    for (int i = 4; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            dp[i][j] = dp[i - 1][j - 1];
            dp[i][j] %= 1000000009;
            dp[i][j] += dp[i - 2][j - 1];
            dp[i][j] %= 1000000009;
            dp[i][j] += dp[i - 3][j - 1];
            dp[i][j] %= 1000000009;
        }
    }
}
void input()
{
    cin >> N >> M;
}
void solve()
{
    int ans = 0;
    for (int i = 0; i <= M; i++)
    {
        ans += dp[N][i];
        ans %= 1000000009;
    }
    cout << ans << '\n';
}
int main()
{
    int tt = 1;
    cin >> tt;
    init();
    while (tt--)
    {
        input();
        solve();
    }
    return 0;
}
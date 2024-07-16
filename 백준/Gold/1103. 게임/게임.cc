#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
string mp[51];
int dp[51][51];
int v[51][51];
int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int ans;
void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> mp[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i][j] = -1;
        }
    }
}
void dfs(int y, int x)
{
    // dp저장값은 앞으로 더 갈수 있는 칸 최대

    // dp가 0이 아니라면 이미 계산되어있는거니까
    if (dp[y][x] != -1)
    {
        v[y][x] = 0;
        return;
    }
    int ret = 0;
    int nexty, nextx;
    for (auto [dy, dx] : d)
    {
        nexty = y + dy * ((mp[y][x]) - '0');
        nextx = x + dx * ((mp[y][x]) - '0');

        if (nexty < 0 || nextx < 0)
        {
            continue;
        }
        if (nexty >= N || nextx >= M)
        {
            continue;
        }
        if (mp[nexty][nextx] == 'H')
        {
            continue;
        }
        if (v[nexty][nextx] != 0)
        {
            cout << "-1\n";
            exit(0);
        }
        v[nexty][nextx] = v[y][x] + 1;
        dfs(nexty, nextx);
        ret = max(ret, dp[nexty][nextx]);
        // return은 반환값 중 최대인놈
        // 반환값은 처음부터 해서 최대가는거로 하자
    }
    dp[y][x] = ret + 1;
    // cout << dp[y][x] << ' ';
    v[y][x] = 0;
    return;
}
void solve()
// map에 써져있는 숫자만큼 이동할건데
// 최대로 이동가능한 횟수를 출력해야함
// 그래프 순회하면서 튕겨저 나갔을 때, 그걸 max에 계속 저장하면됨
// 홀에 빠지는 것도 ㅇㅇ
// 그런데, 무한반복해서 안나갈 수 있는 경우를 따로 체크해야함
// 왔다갔다가능하면 안되는거지
// dfs해서 그때 갔던곳을 또 가는게 가능하면 끝내자
// N,M이 50인걸 보아하니 dp 안쓰면 시간터질거같음
// dp에는 각각 지금으로부터 더 가능한 횟수를 저장해두면 되는거 아닌가?
// dfs 를 돌면서 끝나면, 다시 회수하면서 1씩 늘려서 저장해두면 될듯
// 튕기기 직전이 1 그 전이 2 ... 이렇게
// 물론, 더 큰값이 있다면 갱신하지 않는다.
// 그럼 시작부분에 결국 저장된값 출력하면 되네
// 무한반복만 어떻게 처리할건지 고민좀
// 돌아갈때 visit 0하면 되겠네
{
    v[0][0] = 1;
    dfs(0, 0);

    cout << dp[0][0] << '\n';
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << ans << '\n';
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
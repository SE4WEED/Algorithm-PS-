#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int arr[1001][1001];
int ans[1001][1001];
pair<int, int> goal;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                goal.first = i;
                goal.second = j;
            }
        }
    }
    ans[goal.first][goal.second] = 0; // 목표 지점은 0으로 설정
}

void bfs(int a, int b)
{
    int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({a, b});
    while (!q.empty())
    {
        auto [nowa, nowb] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nexta = nowa + d[i][0];
            int nextb = nowb + d[i][1];
            if (nexta < 0 || nextb < 0 || nexta >= n || nextb >= m)
                continue;
            if (arr[nexta][nextb] != 1)
                continue;
            if (ans[nexta][nextb] != 0) // 방문한 적이 있으면 건너뛰기
                continue;
            ans[nexta][nextb] = ans[nowa][nowb] + 1;
            q.push({nexta, nextb});
        }
    }
}

void solve()
{
    bfs(goal.first, goal.second);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && ans[i][j] == 0)
            {
                cout << "-1 ";
                continue;
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return; // return 문 위치 수정
}

int main()
{
    input();
    solve();
    return 0;
}

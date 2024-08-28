#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
// #define debug
using namespace std;
int N, M, D;
int arr[20][20];
int tmparr[20][20];
int archer[4];
int target[4][2];
bool ok[20];
int v[4][20][20];
int d[3][2] = {{0, -1}, {-1, 0}, {0, 1}};
int ans, nowAns;
void testPrint()
{
    // if (ans <= nowAns)
    if (archer[1] == 2 && archer[2] == 4 && archer[3] == 5)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cout << v[4][i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
void input()
{
    cin >> N >> M >> D;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }
    ans = 0;
}
bool okPlace(int r, int c, int arcNum)
{
    if (r <= 0 || N < r)
    {
        return false;
    }
    if (c <= 0 || M < c)
    {
        return false;
    }
    if (v[arcNum][r][c] != 0)
    {
        return false;
    }
    return true;
}
void findTarget(int row, int arcNum, int arcPos)
{
    queue<pair<int, int>> q;
    v[arcNum][row][arcPos] = 1;
    q.push({row, arcPos});
    if (tmparr[row][arcPos] == 1)
    {
        target[arcNum][0] = row;
        target[arcNum][1] = arcPos;
        return;
    }
    while (!q.empty())
    {
        auto [nowR, nowC] = q.front();

        q.pop();
        for (int i = 0; i < 3; i++)
        {
            if (v[arcNum][nowR][nowC] + 1 > D)
            {
                return;
            }
            int nextR, nextC;
            nextR = nowR + d[i][0];
            nextC = nowC + d[i][1];
            if (!okPlace(nextR, nextC, arcNum))
            {
                continue;
            }
            if (tmparr[nextR][nextC] == 1)
            {
                target[arcNum][0] = nextR;
                target[arcNum][1] = nextC;
                return;
            }
            else
            {
                v[arcNum][nextR][nextC] = v[arcNum][nowR][nowC] + 1;
                q.push({nextR, nextC});
            }
        }
    }
}
void initV()
{
    target[1][0] = -1;
    target[1][1] = -1;
    target[2][0] = -1;
    target[2][1] = -1;
    target[3][0] = -1;
    target[3][1] = -1;
    for (int i = 1; i <= N; i++) //(i,archer[1,2,3])에 아쳐가 서있다는 뜻.
    {
        for (int j = 1; j <= M; j++)
        {
            v[1][i][j] = 0;
            v[2][i][j] = 0;
            v[3][i][j] = 0;
        }
    }
}
void killTarget()
{

    for (int i = 1; i <= 3; i++)
    {
        if (target[i][0] == -1)
        {
            continue;
        }
        tmparr[target[i][0]][target[i][1]] = -1;
    }
}
void realSolve()
{
    // cout << archer[1] << ' ' << archer[2] << ' ' << archer[3] << '\n';
    // 이제 이 세명의 아처로 bfs돌리던가해서 결과를 보면 됨.
    // 방법은, N-1에서부터 출발시켜서 죽이는거. (최대거리가 D임을 유의하자.)
    // 세명에 대해 각각 가장 가깝고 살아있는 적을찾는다
    // 찾고 죽인다(-1로 바꾸자)
    // N에서 출발한다고 생각하고 다시
    // 찾고 죽인다
    // 각자위치에서 가장가까운놈을 bfs로 찾아오고
    // 세번찾아오고 죽이고, 이동 bfs
    //``
    // 이케 ㄱㄱ
    // #ifdef debug
    //     cout << archer[1] << ' ' << archer[2] << ' ' << archer[3] << "\n\n\n";
    // #endif
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            tmparr[i][j] = arr[i][j];
        }
    }
    for (int i = N; i >= 1; i--) //(i,archer[1,2,3])에 아쳐가 서있다는 뜻.
    {
        initV();
        for (int j = 1; j <= 3; j++)
        {

            findTarget(i, j, archer[j]);
        }
        killTarget();
    }
    nowAns = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (tmparr[i][j] == -1)
            {
                nowAns++;
            }
        }
    }
#ifdef debug
    testPrint();
#endif
    ans = max(ans, nowAns);
}
void backt(int num)
{
    if (num == 3)
    {
        realSolve();
    }
    for (int i = archer[num] + 1; i <= M; i++)
    {
        if (ok[i] == true)
        {
            continue;
        }

        ok[i] = true;
        archer[num + 1] = i;
        backt(num + 1);
        ok[i] = false;
    }
}
void solve()
{
    // 3명을 M개의 위치에 위치시킬 수 있는 경우의 수를 모두 찾자.
    // 백트래킹
    // 백트래킹으로 위치 찾고, 세개 각각 그래프탐색한다. 위로, 왼, 오른쪽 만 가는거로해서
    // 거리가 D까지인거만 보면되기때문에(최대 1개) bfs로 탐색한다. 거리가 같다면 최좌측
    for (int i = 1; i <= M; i++)
    {
        ok[i] = false;
    }
    backt(0);
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

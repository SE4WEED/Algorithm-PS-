#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int N, M, K;
int tmparr[55][55];
int arr[55][55];
int com[7][3];
int selected[7];
int order[7];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int ans;
void input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        cin >> com[i][0] >> com[i][1] >> com[i][2];
    }
    ans = 999999999;
}
void rotate(int order)
{
    //[0][1][2]에 각각 순서대로 회전 중심의 y, x와 scale 저장되어있음
    int y, x, scale;
    y = com[order][0] - 1;
    x = com[order][1] - 1;
    scale = com[order][2];
    // cout << y + 1 << ' ' << x + 1 << ' ' << scale << '\n';
    int cy, cx, ny, nx, cur, now;
    for (int i = 1; i <= scale; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                ny = y - i;
                nx = x - i;
                cy = ny + 1;
                cx = nx;
                cur = tmparr[cy][cx];
                for (int k = 0; k < 2 * i + 1; k++)
                {
                    now = tmparr[ny][nx];
                    tmparr[ny][nx] = cur;
                    cur = now;
                    nx++;
                }
            }
            else if (j == 1)
            {
                ny = y - i + 1;
                nx = x + i;
                for (int k = 0; k < 2 * i; k++)
                {
                    now = tmparr[ny][nx];
                    tmparr[ny][nx] = cur;
                    cur = now;
                    ny++;
                }
            }
            else if (j == 2)
            {
                ny = y + i;
                nx = x + i - 1;
                for (int k = 0; k < 2 * i; k++)
                {
                    now = tmparr[ny][nx];
                    tmparr[ny][nx] = cur;
                    cur = now;
                    nx--;
                }
            }
            else
            {
                ny = y + i - 1;
                nx = x - i;
                for (int k = 0; k < 2 * i; k++)
                {
                    now = tmparr[ny][nx];
                    tmparr[ny][nx] = cur;
                    cur = now;
                    ny--;
                }
            }
        }
    }
}
void realSol()
{
    // order[i] = j 라고 한다면, j를 i번째로 쓰면 될듯
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tmparr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        rotate(order[i]);
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << tmparr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // cout << '\n';
    }
    for (int i = 0; i < N; i++)
    {
        int now = 0;
        for (int j = 0; j < M; j++)
        {
            now += tmparr[i][j];
        }
        ans = min(ans, now);
    }
}
void backt(int num)
{
    if (num == K)
    {
        realSol();
    }
    for (int i = 0; i < K; i++)
    {
        if (selected[i])
            continue; // 아직 선택 안된놈이면
        selected[i] = true;
        order[i] = num;
        backt(num + 1);
        selected[i] = false;
    }
}
void solve()
{
    // 백트로 돌면서, K개의 명령을 모든 순서대로 동작시켜본다.
    // 그 이후, 최소값을 출력한다.
    for (int i = 0; i < K; i++)
    {
        selected[i] = false;
        order[i] = 0;
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
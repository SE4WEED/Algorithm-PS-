// boj 23748
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define iint pair<int, int>
using namespace std;
int N, X, Y;
int x[55];
int y[55];
iint knapsack[55][110][110]; // 냅색그거랑, 몇명째인지//만약 초과 했다면, X나 Y를, 배열을 10000 10000까지 가기에는 비효율적이니
// X번째에 그대로 두기로하자.
void input()
{
    cin >> N >> X >> Y;
    int i = 0;
    while (i < N)
    {
        cin >> x[i] >> y[i++];
    }
}
void solve()
{
    knapsack[0][0][0] = {1, 0}; // 여기 있음, 0명 샀음
    if (x[0] >= X)
    {
        x[0] = X;
    }
    if (y[0] >= Y)
    {
        y[0] = Y;
    }
    knapsack[0][x[0]][y[0]] = {1, 1}; // 여기 있음, 1명 샀음
    int nx, ny;
    for (int human = 0; human < N; human++) // human번째를 보면서, human+1번을 바꿀 수 있다면 바꿔주기로.
    {
        for (int xx = 0; xx <= X; xx++)
        {
            for (int yy = 0; yy <= Y; yy++)
            {
                if (knapsack[human][xx][yy].first == 1)
                {
                    nx = xx + x[human + 1];
                    ny = yy + y[human + 1];
                    if (nx >= X)
                    {
                        nx = X;
                    }
                    if (ny >= Y)
                    {
                        ny = Y;
                    }
                    if (knapsack[human + 1][xx][yy].first == 1)
                    {
                        knapsack[human + 1][xx][yy].second = min(knapsack[human + 1][xx][yy].second, knapsack[human][xx][yy].second);
                    }
                    else
                    {
                        knapsack[human + 1][xx][yy] = knapsack[human][xx][yy];
                    }

                    if (knapsack[human + 1][nx][ny].first == 1)
                    {
                        knapsack[human + 1][nx][ny].second = min(knapsack[human + 1][nx][ny].second, knapsack[human][xx][yy].second + 1);
                    }
                    else
                    {
                        knapsack[human + 1][nx][ny] = {knapsack[human][xx][yy].first, knapsack[human][xx][yy].second + 1};
                    }
                }
            }
        }
    }
    vector<int> anscandi;
    int m = 10000;
    for (int i = 0; i <= N; i++)
    {
        if (knapsack[i][X][Y].first == 1)
        {
            m = min(m, knapsack[i][X][Y].second);
        }
    }

    for (int i = 0; i <= N; i++)
    {
        if (knapsack[i][X][Y].second == m)
        {
            anscandi.push_back(i);
        }
    }
    if (anscandi.size() == 0)
    {
        cout << "-1" << '\n';
        return;
    }
    cout << m << '\n'
         << anscandi[0] + 1 << '\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int try__ = 1;
    // cin >> try__ ;
    while (try__--)
    {
        input();
        solve();
    }

    return 0;
}
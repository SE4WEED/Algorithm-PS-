#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int N, M;
int map[501][501];
int v[501][501];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            v[i][j] = -1;
        }
    }
}
int dfs(int y, int x) {
    // cout << y << ' ' << x << "\n";
    if (y == N - 1 && x == M - 1) return 1;
    if (v[y][x] == -1)
        v[y][x] = 0;
    else
        return v[y][x];
    for (int i = 0; i < 4; i++) {
        int nextY = y + d[i][0];
        int nextX = x + d[i][1];
        if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M) continue;
        if (map[y][x] <= map[nextY][nextX]) continue;
        v[y][x] += dfs(nextY, nextX);
    }
    return v[y][x];
}
void solve() {
    dfs(0, 0);
    cout << v[0][0] << '\n';

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}
int main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        input();
        solve();
    }
    return 0;
}
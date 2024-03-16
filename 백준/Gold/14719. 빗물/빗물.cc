#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int h, w;
vector<int> wall(501);
void input() {
    cin >> h >> w;
    int i = 0;
    while (i < w) {
        cin >> wall[i++];
    }
}
int findlm(int id) {
    int max = wall[id];
    for (int i = id; i >= 0; i--) {
        if (max < wall[i]) {
            max = wall[i];
        }
    }
    return max;
}

int findrm(int id) {
    int max = wall[id];
    for (int i = id; i < w; i++) {
        if (max < wall[i]) {
            max = wall[i];
        }
    }
    return max;
}
void solve() {
    int lm, rm;
    int ans = 0;
    for (int i = 1; i < w; i++) {
        lm = findlm(i);
        rm = findrm(i);
        int m = min(lm, rm);
        if (m > wall[i]) {
            ans += m - wall[i];
        }
    }
    cout << ans << '\n';
    return;
}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int cc;
    cc = 1;
   // cin >> cc;
    for (int i = 0; i < cc; i++) {
        input();
        solve();
    }
}
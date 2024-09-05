#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int N, M, K;
string str[2010];
int dp[2010][2010];
void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }
    if (K == 1) {
        cout << "0\n";
        exit(0);
    }
}
void initdp() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 0;
        }
    }
}
void printdp() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << dp[i][j];
        }
        cout << '\n';
    }
}
int solve2(char firstChar) {
    // firstChar에 있는애가
    // y+x 가 짝수인곳에 있어야하는거임
    // dp에는 0,0~ i,j까지 해서 바꿔야 하는 개수 넣어두기
    int tmpans = 999999999;
    int tmp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) {
                if (str[i][j] == firstChar) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1;
                }
            } else if (i == 0 && j != 0) {
                if ((i + j) % 2 == 0 && str[i][j] == firstChar) {  // first가 들어가야하는 자리
                    dp[i][j] = dp[i][j - 1];
                } else if ((i + j) % 2 == 1 && str[i][j] != firstChar)  // first안들어가야하고 안들어가있는
                {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
            } else if (i != 0 && j == 0) {
                if ((i + j) % 2 == 0 && str[i][j] == firstChar) {  // first가 들어가야하는 자리
                    dp[i][j] = dp[i - 1][j];
                } else if ((i + j) % 2 == 1 && str[i][j] != firstChar)  // first안들어가야하고 안들어가있는
                {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            } else {
                if ((i + j) % 2 == 0 && str[i][j] == firstChar) {  // first가 들어가야하는 자리
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                } else if ((i + j) % 2 == 1 && str[i][j] != firstChar)  // first안들어가야하고 안들어가있는
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1;
                }
            }
            if (K - 1 < i && K - 1 < j) {
                tmp = dp[i][j] + dp[i - K][j - K] - dp[i - K][j] - dp[i][j - K];
                tmpans = min(tmp, tmpans);
            } else if (K - 1 == i && K - 1 < j) {
                tmp = dp[i][j] - dp[i][j - K];
                tmpans = min(tmp, tmpans);
            } else if (K - 1 < i && K - 1 == j) {
                tmp = dp[i][j] - dp[i - K][j];
                tmpans = min(tmp, tmpans);
            } else if (K - 1 == i && K - 1 == j) {
                tmp = dp[i][j];
                tmpans = min(tmp, tmpans);
            }
        }
    }
    // cout << tmpans << '\n';
    return tmpans;
}
void solve() {
    int ans = 999999999;
    initdp();
    ans = min(ans, solve2('B'));
    // printdp();
    // cout << "\n\n\n";
    initdp();
    ans = min(ans, solve2('W'));
    // printdp();
    cout
        << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        input();
        solve();
    }
    return 0;
}
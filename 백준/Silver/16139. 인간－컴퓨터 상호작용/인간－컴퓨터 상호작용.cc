#include <string.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
char str[200010];
int sum[200010][26];
int q;
void input() {
    cin >> str;
    cin >> q;
}
void solve() {
    int l = strlen(str);

    for (int c = 'a'; c <= 'z'; c++) {
        if (str[0] == c) {
            sum[0][c - 'a'] = 1;
        } else {
            sum[0][c - 'a'] = 0;
        }
    }
    for (int i = 1; i < l; i++) {
        for (int c = 'a'; c <= 'z'; c++) {
            if (str[i] == c) {
                sum[i][c - 'a'] = sum[i - 1][c - 'a'] + 1;
            } else {
                sum[i][c - 'a'] = sum[i - 1][c - 'a'];
            }
        }
    }
    char c;
    int s, e;
    for (int i = 0; i < q; i++) {
        cin >> c >> s >> e;
        if (s == 0) {
            cout << sum[e][c - 'a'] << '\n';
            continue;
        }
        cout << sum[e][c - 'a'] - sum[s - 1][c - 'a'] << '\n';
    }
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